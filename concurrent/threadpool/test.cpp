#include "pool2/pool.hpp"
#include "profile.hpp"
#include <future>

#define NUM_TASK 102400
// #define NUM_W

std::vector<int> primes;

void using_async()
{
    std::vector<std::future<bool>> v;

    for (int i = 0; i < NUM_TASK; ++i)
    {
        v.push_back(std::async(std::launch::async, &isPrime, primes[i]));
    }

    for (auto &f : v)
    {
        f.get();
    }
}

void using_threads()
{
}

// IO密集和CPU密集的区别?

void using_pool(int num_workers)
{
    Pool pool(num_workers);

    // Task task = {
    //     ,
    //     isPrime}; //没报错吗

    pool.start();
    for (int i = 0; i < NUM_TASK; ++i)
    {
        pool.commit({primes[i],
                     isPrime});
    }

    return;
}

int main()
{
    for (int i = 0; i < NUM_TASK; ++i)
    {
        primes.push_back(rand() % 100);
    }
    // Task task = {
    //     1073676287,
    //     isPrime}; //没报错吗
    // Pool pool(NUM_WORKERS);
    // pool.start();
    // for (int i = 0; i < NUM_TASKS; ++i)
    // {
    //     pool.commit(task);
    // }
    TIME_START(using_async);
    using_async();
    TIME_END(using_async);

    TIME_START(using_pool_4);
    using_pool(4);
    TIME_END(using_pool_4);

    TIME_START(using_pool_8);
    using_pool(8);
    TIME_END(using_pool_8);

    TIME_START(using_pool_10);
    using_pool(10);
    TIME_END(using_pool_10);

    TIME_START(using_pool_16);
    using_pool(16);
    TIME_END(using_pool_16);

    TIME_START(using_pool_20);
    using_pool(20);
    TIME_END(using_pool_20);

    TIME_START(using_pool_24);
    using_pool(24);
    TIME_END(using_pool_24);
    return 0;
}