#include "factor/factor.h"

#include "benchmark/benchmark.h"

namespace factor {

void FactorBench(benchmark::State& state) {
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(factor(state.range_x()));
  }
}
BENCHMARK(FactorBench)->Range(1, 10 << 10);

}  // namespace factor

int main(int argc, char** argv) {
  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();
  return 0;
}
