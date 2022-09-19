#include "benchmark/benchmark.h"

#include <vector>
using std::vector;

namespace bm = benchmark;

static void vector_create_empty(bm::State &state) {
    for (auto _ : state){
        vector<int> v;
        bm::DoNotOptimize(v);
    }
}
BENCHMARK(vector_create_empty);

static void vector_create_one(bm::State &state) {
    for (auto _ : state){
        vector<int> v(1);
        bm::DoNotOptimize(v);
    }
}
BENCHMARK(vector_create_one);

static void vector_reserve(bm::State &state) {
    for (auto _ : state){
        vector<int> v;
        v.reserve(1);
        bm::DoNotOptimize(v);
    }
}
BENCHMARK(vector_reserve);

static void vector_reserve_push_back(bm::State &state) {
    for (auto _ : state){
        vector<int> v;
        v.reserve(4);
        v.push_back(42);
        v.push_back(42);
        v.push_back(42);
        v.push_back(42);

        bm::DoNotOptimize(v);
    }
}
BENCHMARK(vector_reserve_push_back);


static void vector_push_back(bm::State &state) {
    for (auto _ : state){
        vector<int> v;
        v.push_back(42);
        v.push_back(42);
        v.push_back(42);
        v.push_back(42);
        bm::DoNotOptimize(v);
    }
}

BENCHMARK(vector_push_back);

BENCHMARK_MAIN();