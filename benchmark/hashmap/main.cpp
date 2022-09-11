#include "benchmark/benchmark.h"
#include <vector>
#include <random>
#include <unordered_set>

#define N 100000
#define K 10000

static void BM_UnorderedMapEqual(benchmark::State &state)
{
  std::vector<int> v(state.range(0));
  std::iota(v.begin(), v.end(), 0);
  std::unordered_set<int> s1(v.begin(), v.end());
  std::mt19937 rng{0};
  std::shuffle(v.begin(), v.end(), rng);
  std::unordered_set<int> s2(v.begin(), v.end());
  for (auto _ : state)
  {
    bool equal = s2 == s1;
    benchmark::DoNotOptimize(&equal);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_UnorderedMapEqual)->RangeMultiplier(4)->Range(4, 4 << 14);

// Define another benchmark
static void BM_VectorEqual(benchmark::State &state)
{
  std::vector<int> v(state.range(0));
  std::iota(v.begin(), v.end(), 0);
  std::mt19937 rng{0};
  std::shuffle(v.begin(), v.end(), rng);
  auto v2 = v;
  for (auto _ : state)
  {
    bool equal = v2 == v;
    benchmark::DoNotOptimize(&equal);
  }
}
BENCHMARK(BM_VectorEqual)->RangeMultiplier(4)->Range(4, 4 << 14);
;

BENCHMARK_MAIN();