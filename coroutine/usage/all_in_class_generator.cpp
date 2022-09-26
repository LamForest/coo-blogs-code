#include <concepts>
#include <experimental/coroutine>
#include <exception>
#include <iostream>

using namespace std::experimental;

/*
想将协程写在ReturnObject中
但似乎太晦涩难懂了
*/

struct Generator
{

    struct promise_type
    {
        promise_type()
        {
            printf("promise_type ctor, this = %p\n", this);
        }

        ~promise_type()
        {
            printf("promise_type dtor, this = %p\n", this);
        }

        /*
        get_return_object的返回值就是coroutine的返回值
        */
        Generator get_return_object()
        {
            return {
                coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::experimental::suspend_always initial_suspend() { return {}; }

        /*
        重要:
        当 co_return 返回时, coroutine_state(以及其中的promise_type) 是否要销毁, 由final_suspend决定.
        如果返回值为suspend_never, 则coroutine不再挂起, 直接结束并销毁.
        如果返回值为suspend_always, 则coroutine 挂起, 由caller决定何时销毁
        */
        std::experimental::suspend_always final_suspend() noexcept { return {}; }

        void return_void() {}

        void unhandled_exception() {}

        suspend_always yield_value(int data)
        {
            this->data = data;
            return {};
        }
        /* 数据放在promise_type中 */
        int data = -1;
        /* 异常也放在promise_type中 */
        std::exception_ptr ex_ptr;
    };
    using handle_type = coroutine_handle<promise_type>;

    Generator()
    {
        Generator g = counter();
        this->h_ = g.h_;
        g.h_ = nullptr;
        std::cout
            << "Generator ctor" << std::endl;
    }

    Generator(const Generator &) = delete;
    Generator(Generator &&rhs)
    {
        h_ = rhs.h_;
        rhs.h_ = nullptr;
    }

    Generator(handle_type h) : h_(h)
    {
        std::cout
            << "Generator ctor" << std::endl;
    }
    handle_type h_;
    int next()
    {
        h_.resume();
        return h_.promise().data;
    }
    ~Generator()
    {
        std::cout
            << "Generator dtor" << std::endl;
        if (h_)
            h_.destroy();
    }

    static Generator counter()
    {
        printf("Start coroutine\n");
        for (int i = 0;; ++i)
        {
            std::cout << "counter: " << i << std::endl;
            co_yield i;
        }
    }
};

int main()
{
    auto gen = Generator();

    for (int i = 0; i < 3; ++i)
    {
        int cur = gen.next();
        printf(" i = %d, cur = %d\n", i, cur);
    }
    return 0;
}
