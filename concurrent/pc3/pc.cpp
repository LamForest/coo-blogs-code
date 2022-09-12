
#include <thread>
#include <vector>
#include <mutex>
#include <time.h>
#include <condition_variable>

#define NUM_PRODUCER 1
#define NUM_CONSUMER 2

#define BUFFER_SIZE 10

#define TASK 20 //递归斐波那契数列的参数

int buffer[BUFFER_SIZE];
int cnt = 0;
std::atomic<bool> stop{false};
std::atomic<int> g_i{0};
std::mutex mutex;
std::condition_variable cv_wait_for_task, cv_wait_for_slot;

void sleep(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

/**
 * 任务:递归计算斐波那契数列
 * */
int factorial(int i)
{
    if (i < 2)
        return 1;
    return factorial(i - 2) + factorial(i - 1);
}

void producer_func(int thread_id)
{
    while (!stop)
    {
        int num = -1;
        {
            std::unique_lock<std::mutex> lock(mutex);

            cv_wait_for_slot.wait(lock, [&]()
                                  { return cnt < BUFFER_SIZE || stop; }); // BUG: 可能stop = true后依旧等待
            if (stop)
                break;
            num = TASK;
            buffer[cnt++] = num;
        }
        cv_wait_for_task.notify_one(); //在里面在外面? 先释放mutex吗?
        printf("[P%d] : Produce %d\n", thread_id, num);
    }
}

void consumer_func(int thread_id)
{
    while (1)
    {
        int num = -1;
        {
            std::unique_lock<std::mutex> lock(mutex);
            cv_wait_for_task.wait(lock, [&]()
                                  { return cnt > 0 || stop; }); // BUG: 可能stop = true后依旧等待
            if (stop)
            {
                if (cnt == 0)
                    break;
                else //将buffer中剩余的都执行完, 才能够break
                    printf("[C%d] remain %d tasks, thread cannot stop\n", thread_id, cnt);
            }

            num = buffer[--cnt];
        }
        cv_wait_for_slot.notify_one();
        printf("[C%d] : Consume %d\n", thread_id, factorial(num));
    }
}

void stop_after(int seconds)
{
    sleep(seconds);
    stop = true;
    printf("----------------stop!!!-------------------\n");
}

int main()
{
    std::thread timer(stop_after, 1);
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;
    for (int i = 0; i < NUM_PRODUCER; ++i)
    {
        producers.emplace_back(std::thread(producer_func, i));
    }
    for (int i = 0; i < NUM_CONSUMER; ++i)
    {
        consumers.emplace_back(std::thread(consumer_func, i));
    }

    //-----join-----
    timer.join();
    for (auto &producer : producers)
        producer.join();
    for (auto &consumer : consumers)
        consumer.join();
    printf("buffer remain %d tasks\n", cnt); //如何解决?
    return 0;
}