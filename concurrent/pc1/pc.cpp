
#include <thread>
#include <mutex>
#include <time.h>

#define THREAD_NUM 2

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int cnt = 0;
std::atomic<bool> stop{false};
std::mutex lock;

void sleep(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void producer_func()
{
    while (!stop)
    {
        int num = -1;
        {
            std::lock_guard<std::mutex> guard(lock);
            if (cnt < BUFFER_SIZE)
            {
                num = rand() % 100;
                buffer[cnt++] = num;
            }
        }
        printf("[%d] Produce %d\n", std::this_thread::get_id(), num);
    }
}

void consumer_func()
{
    while (!stop)
    {
        sleep(1);
        int num = -1;
        {
            std::lock_guard<std::mutex> guard(lock);
            if (cnt > 0)
            {
                num = buffer[--cnt];
            }
        }
        printf("[%d] : Consume %d\n", std::this_thread::get_id(), num);
    }
}

void stop_after(int seconds)
{
    sleep(seconds);
    stop = true;
}

int main()
{
    std::thread producer(producer_func);
    std::thread consumer(consumer_func);

    std::thread timer(stop_after, 1);
    //如果生产者, 消费者一同样的速度生产/消费
    //当#生产者 > 消费者时
    //一段时间后, buffer就会满
    //其中一个生产者就会idle
    producer.join();
    consumer.join();
    timer.join();
}