#include <concepts>
#include <experimental/coroutine>
#include <exception>
#include <iostream>

using namespace std::experimental;

struct ReturnObject
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
        ReturnObject get_return_object()
        {
            return {
                coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::experimental::suspend_never initial_suspend() { return {}; }

        /*
        重要:
        当 co_return 返回时, coroutine_state(以及其中的promise_type) 是否要销毁, 由final_suspend决定.
        如果返回值为suspend_never, 则coroutine不再挂起, 直接结束并销毁.
        如果返回值为suspend_always, 则coroutine 挂起, 由caller决定何时销毁
        */
        std::experimental::suspend_always final_suspend() noexcept
        {
            printf("final_suspend\n");
            return {};
        }

        void return_void(){};

        void unhandled_exception()
        {
            printf("unhandled_exception\n");
            ex_ptr = std::current_exception();
        }
        suspend_always yield_value(unsigned data)
        {
            this->data = data;
            return {};
        }
        /* 数据放在promise_type中 */
        unsigned data = -1;
        /* 异常也放在promise_type中 */
        std::exception_ptr ex_ptr;
    };

    ReturnObject(coroutine_handle<promise_type> h) : h_(h)
    {
        std::cout << "RetureObject ctor" << std::endl;
    }

    ~ReturnObject()
    {
        std::cout << "RetureObject dtor" << std::endl;
    }

    coroutine_handle<promise_type> h_;
};

ReturnObject
counter()
{
    //在进入counter之前, counter的coroutine_state以及其中的promise_type
    //以及 Return object就被创建了.
    printf("Start coroutine\n");
    for (unsigned int i = 0;; ++i)
    {
        std::cout << "counter: " << i << std::endl;
        if (i > 5)
        {
            throw std::runtime_error("Exception: i > 5");
        }
        co_yield i;
    }
}

int main()
{
    coroutine_handle<ReturnObject::promise_type> h;
    printf("before call coroutine\n");
    h = counter().h_;
    printf("after call coroutine\n");

    // h.promise() 返回的是 promise_type&
    ReturnObject::promise_type &p = h.promise();
    try
    {
        while (1)
        {
            std::cout << "In main1 function, data = " << p.data << "\n";
            h.resume();
            if (p.ex_ptr)
            {
                std::rethrow_exception(p.ex_ptr);
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    auto h2 = std::move(h);
    h = nullptr;
    printf("h2.addr = %p, h. addr = %p", h2.address(), h.address());
    // if (h)
    //     h.destroy();
}
