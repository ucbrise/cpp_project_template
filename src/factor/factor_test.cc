#include "factor/factor.h"

#include <vector>

#include "gtest/gtest.h"

namespace factor {

TEST(Factor, SmallNumbers) {
  EXPECT_EQ(factor(1), std::vector<long>({1}));
  EXPECT_EQ(factor(2), std::vector<long>({2}));
  EXPECT_EQ(factor(3), std::vector<long>({3}));
  EXPECT_EQ(factor(4), std::vector<long>({2, 2}));
  EXPECT_EQ(factor(5), std::vector<long>({5}));
  EXPECT_EQ(factor(6), std::vector<long>({2, 3}));
  EXPECT_EQ(factor(7), std::vector<long>({7}));
  EXPECT_EQ(factor(8), std::vector<long>({2, 2, 2}));
  EXPECT_EQ(factor(9), std::vector<long>({3, 3}));
}

TEST(Factor, BigNumbers) {
  EXPECT_EQ(factor(1209), std::vector<long>({3, 13, 31}));
  EXPECT_EQ(factor(4242), std::vector<long>({2, 3, 7, 101}));
}

}  // namespace factor

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
