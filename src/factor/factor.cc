#include "factor/factor.h"

namespace factor {

std::vector<long> factor(long x) {
  if (x == 1) {
    return {1};
  }

  std::vector<long> factors;
  while (x != 1) {
    for (int i = 2; i <= x; ++i) {
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
