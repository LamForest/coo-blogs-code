#include <chrono>
#include <iostream>

int add1(int *a, int *b)
{
    *a = 10;
    *b = 12;
    return *a + *b;
}

int add2(int *__restrict a, int *__restrict b)
{
    *a = 10;
    *b = 12;
    return *a + *b;
}

int main()
{
    int *a = new int;
    int *b = new int;

    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 100000000; i++)
            add1(a, b);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
    }

    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 100000000; i++)
        {
            add2(a, b);
        }
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
    }
    return 0;
}