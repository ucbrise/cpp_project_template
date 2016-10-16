#ifndef FACTOR_FACTOR_H_
#define FACTOR_FACTOR_H_

#include <cstdint>
#include <vector>

namespace factor {

// `factor(x)` returns the prime factors of `x` in increading order. It is a
// precondition that `x` is a positive number.
std::vector<int64_t> factor(int64_t x);

}  // namespace factor

#endif  // FACTOR_FACTOR_H_
