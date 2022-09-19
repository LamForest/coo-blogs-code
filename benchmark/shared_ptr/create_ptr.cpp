#include <memory>
#include "benchmark/benchmark.h"
namespace bm = benchmark;

class Cat
{
    // std::string name;
    // double weight;
    // int age;
    int a[64];
};



static void BM_RawPointer(benchmark::State &state)
{
    for (auto _ : state)
    {
        {
            Cat *p = new Cat();
            bm::DoNotOptimize(p);
            delete p;
        }
    }
}

static void BM_SharedPointer(benchmark::State &state)
{
    for (auto _ : state)
    {
        {
            std::shared_ptr<Cat> p(new Cat());
            bm::DoNotOptimize(p);
        }
    }
}

// Define another benchmark
static void BM_MakeShared(benchmark::State &state)
{
    for (auto _ : state)
    {
        {
            auto p = std::make_shared<Cat>();
            bm::DoNotOptimize(p);
        }
    }
}

static void BM_UniquePointer(benchmark::State &state)
{
    for (auto _ : state)
    {
        {
            std::unique_ptr<Cat> p(new Cat());
            bm::DoNotOptimize(p);
        }
    }
}

static void BM_MakeUnique(benchmark::State &state)
{
    for (auto _ : state)
    {
        {
            auto p = std::make_unique<Cat>();
            bm::DoNotOptimize(p);
        }
    }
}

// Register the function as a benchmark
BENCHMARK(BM_RawPointer);
BENCHMARK(BM_SharedPointer);
BENCHMARK(BM_MakeShared);
// BENCHMARK(BM_MakeSharedPassRef);

BENCHMARK(BM_UniquePointer);
BENCHMARK(BM_MakeUnique);


BENCHMARK_MAIN();