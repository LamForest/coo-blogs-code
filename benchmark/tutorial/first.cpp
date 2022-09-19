
#include <algorithm> // `std::sort`
#include <cmath>     // `std::pow`
#include <cstdint>   // `int32_t`
#include <cstdlib>   // `std::rand`
#include <execution> // `std::execution::par_unseq`
#include <new>       // `std::launder`
#include <random>    // `std::mt19937`
#include <vector>    // `std::algorithm`

#include "benchmark/benchmark.h"

namespace bm = benchmark;

static void i32_addition(bm::State &state) {
    int32_t a = 0, b = 0, c = 0;
    for (auto _ : state)
        c = a + b;
}

// The compiler will just optimize everything out.
// After the first run, the value of `c` won't change.
// The benchmark will show 0ns per iteration.
BENCHMARK(i32_addition);

static void i32_addition_random(bm::State &state) {
    int32_t c = 0;
    for (auto _ : state)
        c = std::rand() + std::rand();
}

// This run in 25ns, or about 100 CPU cycles.
// Is integer addition really that expensive?
BENCHMARK(i32_addition_random);

static void i32_addition_semirandom(bm::State &state) {
    int32_t a = std::rand(), b = std::rand(), c = 0;
    for (auto _ : state)
        bm::DoNotOptimize(c = (++a) + (++b));
}

// We trigger the two `inc` instructions and the `add` on x86.
// This shouldn't take more then 0.7 ns on a modern CPU.
// So all the time spent - was in the `rand()`!
BENCHMARK(i32_addition_semirandom);

// Our `rand()` is 100 cycles on a single core, but it involves
// global state management, so it can be as slow 12'000 ns with
// just 8 threads.
BENCHMARK(i32_addition_random)->Threads(32);
BENCHMARK(i32_addition_semirandom)->Threads(32);

// ------------------------------------
// ## Let's do some basic math
// ### Maclaurin series
// ------------------------------------

static void f64_sin(bm::State &state) {
    double argument = std::rand(), result = 0;
    for (auto _ : state)
        bm::DoNotOptimize(result = std::sin(argument += 1.0));
}

//为什么比std::sin还慢?
static void f64_sin_maclaurin(bm::State &state) {
    double argument = std::rand(), result = 0;
    for (auto _ : state) {
        argument += 1.0;
        result = argument - std::pow(argument, 3) / 6 + std::pow(argument, 5) / 120;
        bm::DoNotOptimize(result);
    }
}

// Lets compute the `sin(x)` via Maclaurin series.
// It will involve a fair share of floating point operations.
// We will only take the first 3 parts of the expansion:
//  sin(x) ~ x - (x^3) / 3! + (x^5) / 5!
// https://en.wikipedia.org/wiki/Taylor_series
BENCHMARK(f64_sin);
BENCHMARK(f64_sin_maclaurin);


// Lets compute the `sin(x)` via Maclaurin series.
// It will involve a fair share of floating point operations.
// We will only take the first 3 parts of the expansion:
//  sin(x) ~ x - (x^3) / 3! + (x^5) / 5!
// https://en.wikipedia.org/wiki/Taylor_series
BENCHMARK(f64_sin);
BENCHMARK(f64_sin_maclaurin);

static void f64_sin_maclaurin_powless(bm::State &state) {
    double argument = std::rand(), result = 0;
    for (auto _ : state) {
        argument += 1.0;
        result = argument - (argument * argument * argument) / 6.0 +
                 (argument * argument * argument * argument * argument) / 120.0;
        bm::DoNotOptimize(result);
    }
}

// Help the compiler Help you!
// Instead of using the heavy generic operation - describe your special case to the compiler!
BENCHMARK(f64_sin_maclaurin_powless);

//clang 怎么注明-ffast-math
// The old syntax in GCC is: __attribute__((optimize("-ffast-math")))
__attribute__((optimize("-ffast-math"))) static void f64_sin_maclaurin_with_fast_math(bm::State &state) {
    double argument = std::rand(), result = 0;
    for (auto _ : state) {
        argument += 1.0;
        result = argument - (argument * argument * argument) / 6.0 +
                 (argument * argument * argument * argument * argument) / 120.0;
        bm::DoNotOptimize(result);
    }
}

// Floating point math is not associative!
// So it's not reorderable! And it requires extra annotation!
// Use only when you work with low-mid precision numbers and values of similar magnitude.
// As always with IEEE-754, you have same number of elements in [-inf,-1], [-1,0], [0,1], [1,+inf].
// https://en.wikipedia.org/wiki/Double-precision_floating-point_format
BENCHMARK(f64_sin_maclaurin_with_fast_math);


BENCHMARK_MAIN();