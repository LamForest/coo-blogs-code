#include "benchmark/benchmark.h"
#include <vector>
using std::vector;
#define N 10000
#define K 100
static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  vector<float> v;
  // vector<size_t> inds;
  std::iota(v.begin(), v.end(), 0);
  for()
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();