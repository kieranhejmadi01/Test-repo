// Strength reduction
// By: Kieran Hejmadi

#include <benchmark/benchmark.h>
#include <vector>

// Benchmark idiv instruction with division
static void baseDiv(benchmark::State &s) {
  std::vector<int> v_in(4096);
  std::vector<int> v_out(4096);

  for (auto _ : s) {
    for (size_t i = 0; i < v_in.size(); i++) v_out[i] = v_in[i] / s.range(0);
    // s.range(0) is unknown at compile time, cannot be reduced
  }
}
// BENCHMARK(baseDiv)->Arg(7)->Unit(benchmark::kMicrosecond);
BENCHMARK(baseDiv)->Arg(1500)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
