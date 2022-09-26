#include <concepts>
#include <experimental/coroutine>
#include <exception>
#include <iostream>

using namespace std::experimental;

/*
用Generator来管理协程, 协程是分配在堆中的资源, 占用了内存, 如果不释放. 则会内存泄漏;
如果重复释放, 则会crash

所以Generator以RAII为设计思想, 类似unique_ptr, 管理协程
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

        /* initial_suspend 返回 suspend_always, 即lazy evaluation */
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

    Generator(handle_type h) : h_(h)
    {
        std::cout << "Generator ctor" << std::endl;
    }
    Generator(const Generator &rhs) = delete;
    Generator(Generator &&rhs)
    {
        h_ = std::move(rhs.h_);
        rhs.h_ = nullptr;
    }
    Generator &operator=(const Generator &rhs) = delete;
    Generator &operator=(Generator &&rhs)
    {
        h_ = std::move(rhs.h_); //并不会将 rhs.h_置为空, 会导致double free
        rhs.h_ = nullptr;
        return *this;
    }
    handle_type h_;
    int next()
    {
        h_.resume();
        if (h_.done())
        {
            return -1;
        }
        return h_.promise().data;
    }
    ~Generator()
    {
        std::cout
            << "Generator dtor" << std::endl;
        if (h_)
            h_.destroy();
    }
};

Generator counter(int N)
{
    printf("Start coroutine\n");
    for (int i = 0; i < N; ++i)
    {
        std::cout << "counter: " << i << std::endl;
        co_yield i;
    }
}

int main()
{
    {
        auto gen_ = counter(2);
        auto gen = std::move(gen_);
        for (int i = 0; i < 5; ++i)
        {
            int cur = gen.next();
            printf(" i = %d, gen.next = %d\n", i, cur);
            if (cur == -1)
            {
                break;
            }
        }
    }

    return 0;
}
