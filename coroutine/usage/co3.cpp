#include <concepts>
#include <experimental/coroutine>
#include <exception>
#include <iostream>

using namespace std::experimental;

struct ReturnObject
{
    // promise_type有一个实例对象在coroutine资源中
    // promise_type虽然定义在ReturnObject中, 但ReturnObject实例中并没有promise_type对象
    // promise在什么时候被创建? coroutine创建时
    // 在多次coroutine之间是一直存活的吗? 是
    // promise_type只用存放一些coroutine和调用者之间需要传递的数据
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
            // data += 1;
            return {
                // coroutine_handle<void> 没有这个静态方法.
                // promise_type 可以和 包含这个promise_type的coroutine state 的 handler之间互相转化
                // coroutine_handle -> promise_type: .promise()
                // promise_type -> coroutine_handle : 如下
                coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::experimental::suspend_never initial_suspend() { return {}; }
        std::experimental::suspend_never final_suspend() noexcept { return {}; }
        void return_void(){};
        void unhandled_exception() {}
        unsigned int *data = nullptr;
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

/*
为了在coroutine中获取coroutine state中的promise
而定义的awaitable类
*/
struct GetPromise
{

    ReturnObject::promise_type *p;

    bool await_ready() { return false; }

    bool await_suspend(coroutine_handle<ReturnObject::promise_type> h)
    {
        p = &(h.promise());
        return false;
    }

    ReturnObject::promise_type *await_resume()
    {
        return p;
    }
};

ReturnObject
counter()
{
    //在进入counter之前, counter的coroutine_state以及其中的promise_type
    //以及 Return object就被创建了.
    printf("Start coroutine\n");
    ReturnObject::promise_type *pp = co_await GetPromise();
    unsigned i = 0;
    // coroutine的变量保存在堆上, 所以可以返回局部变量的指针.
    pp->data = &i;
    for (;; ++i)
    {
        co_await suspend_always{};
        std::cout << "counter: " << i << std::endl;
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
    // counter(&h);
    for (int i = 0; i < 10; ++i)
    {
        // auto obj = h();  // 错误, h() 或 h.resume没有返回值
        h();
        std::cout << "In main1 function, data = " << *(p.data) << "\n";
    }
    h.destroy();
}
