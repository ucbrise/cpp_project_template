#include "factor/factor.h"

namespace factor {

std::vector<int64_t> factor(int64_t x) {
  if (x == 1) {
    return {1};
  }

  std::vector<int64_t> factors;
  while (x != 1) {
    for (int64_t i = 2; i <= x; ++i) {
      if (x % i == 0) {
        x /= i;
        factors.push_back(i);
        break;
      }
    }
  }
  return factors;
}

}  // namespace factor
