#include <concepts>
#include <experimental/coroutine>
#include <exception>
#include <iostream>

using namespace std::experimental;

struct ReturnObject
{
    //一定要定义在Return Object里面, 为何?
    // promise_type有一个实例对象在coroutine资源中
    // Return Object应该不持有promise, 只是持有一个指针
    // promise在什么时候被创建? 在多次coroutine之间是一直存活的吗?
    // 我感觉可以不用一直存活, 可以实时创建, 因为需要一直保存的数据可以放在coroutine的本地栈内
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
            data += 1;
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
        int data = 0;
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
    // Awaiter a{};
    for (unsigned i = 0;; ++i)
    {
        co_await suspend_always{};
        std::cout << "counter: " << i << std::endl;
    }
}

int main()
{
    coroutine_handle<ReturnObject::promise_type> h;
    h = counter().h_;
    // h.promise() 返回的是 promise_type&
    // promise_type是copyable的.
    ReturnObject::promise_type &p = h.promise();
    // counter(&h);
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "In main1 function, data = " << p.data << "\n";
        // auto obj = h();  // 错误, h() 或 h.resume没有返回值
        h();
    }
    h.destroy();
}
