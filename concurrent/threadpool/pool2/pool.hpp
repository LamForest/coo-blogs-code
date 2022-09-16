
#include <thread>
#include <vector>
#include <mutex>
#include <time.h>
#include <condition_variable>
#include <deque>

// #define NUM_WORKERS 10
// TODO Task -> Task*
// TODO 单独有个调度线程, 用于分配任务

struct Task
{
    int payload;
    std::function<bool(int)> func;
};

// std::mute

// TODO 测试IO密集的任务
bool isPrime(int n)
{
    if (n <= 3)
    {
        return n > 1;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
class Pool
{
public:
    Pool(int num_workers) : num_workers(num_workers)
    {
        workers_workload.resize(num_workers);
    }

    void start()
    {
        for (int t = 0; t < num_workers; ++t)
        {
            // "Effective Modern C++", Item 34: Prefer lambdas to std::bind
            // 必须写成 &Pool::worker_loop, 只是worker_loop不行
            workers.emplace_back(std::bind(&Pool::worker_loop, this, std::placeholders::_1), t);
        }
    }

    void commit(Task task)
    {
        {
            std::lock_guard<decltype(queue_mutex)> guard(queue_mutex);

            task_queue.push_back(std::move(task));
        }
        cv_wait_for_task.notify_one();
    }

    void worker_loop(int worker_id)
    {
        while (1)
        {
            Task task;
            {
                // conditional variable不接受lock_guard作为参数
                std::unique_lock<decltype(queue_mutex)> lock(queue_mutex);

                cv_wait_for_task.wait(lock, [&]() -> bool
                                      { return task_queue.size() > 0 || is_stop; });
                if (is_stop && task_queue.size() == 0)
                {
                    break;
                }

                task = task_queue.front();
                task_queue.pop_front();
            }
            workers_workload[worker_id] += 1;
            bool is_prime = task.func(task.payload);
            // printf("thread [%2d] - %d is_prime ? %d\n", worker_id, task.payload, is_prime);
        }
    }

    void stop()
    {
        is_stop = true;
        cv_wait_for_task.notify_all();
    }

    //   使用类来包装线程池的好处之一, 就是可以在析构函数中join
    ~Pool()
    {
        stop();
        for (auto &worker : workers)
        {
            worker.join();
        }
        // printf("Pool remain %d task\n", task_queue.size());
        for (int i = 0; i < num_workers; ++i)
        {
            // printf("thread [%2d] - finish %d jobs\n", i, workers_workload[i]);
        }
    }

private:
    int num_workers;
    std::vector<std::thread> workers;
    std::vector<int> workers_workload;

    std::deque<Task> task_queue;

    std::mutex queue_mutex;

    std::condition_variable cv_wait_for_task;

    std::atomic_bool is_stop{false};
};
