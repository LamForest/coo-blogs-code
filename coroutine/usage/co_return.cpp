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
                // coroutine_handle<void> 没有这个静态方法.
                // promise_type 可以和 包含这个promise_type的coroutine state 的 handler之间互相转化
                // coroutine_handle -> promise_type: .promise()
                // promise_type -> coroutine_handle : 如下
                coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::experimental::suspend_never initial_suspend() { return {}; }

        /*
        重要:
        当 co_return 返回时, coroutine_state(以及其中的promise_type) 是否要销毁, 由final_suspend决定.
        如果返回值为suspend_never, 则coroutine不再挂起, 直接结束并销毁.
        如果返回值为suspend_always, 则coroutine 挂起, 由caller决定何时销毁
        */
        std::experimental::suspend_never final_suspend() noexcept { return {}; }
        /*
        return_void和 return_value不能同时定义. 否则会报编译错误
        它们的返回值不是awaitable object而是void
        */
        // void return_value(unsigned data) { this->data = data; }
        void return_void(){};

        void unhandled_exception() {}
        suspend_always yield_value(unsigned data)
        {
            this->data = data;
            return {};
        }
        unsigned data = -1;
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
        co_yield i;
        if (i > 5)
        {
            co_return;
        }
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
    while (!h.done())
    {
        std::cout << "In main1 function, data = " << p.data << "\n";
        h();
    }
    h.destroy();
}
