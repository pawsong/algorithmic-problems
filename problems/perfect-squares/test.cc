
#include "gmock/gmock.h"
#include "solution.h"

int main(int argc, char** argv) {
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(PerfectTriangleTest, 0) {
  Solution sol;
  int numSquares = sol.numSquares(0);
  int expected[] = {};
  EXPECT_EQ(numSquares, sizeof(expected) / sizeof(int));
}

TEST(PerfectTriangleTest, 1) {
  Solution sol;
  int numSquares = sol.numSquares(1);
  int expected[] = {1};
  EXPECT_EQ(numSquares, sizeof(expected) / sizeof(int));
}

TEST(PerfectTriangleTest, 12) {
  Solution sol;
  int numSquares = sol.numSquares(12);
  int expected[] = {4, 4, 4};
  EXPECT_EQ(numSquares, sizeof(expected) / sizeof(int));
}

TEST(PerfectTriangleTest, 13) {
  Solution sol;
  int numSquares = sol.numSquares(13);
  int expected[] = {4, 9};
  EXPECT_EQ(numSquares, sizeof(expected) / sizeof(int));
}

TEST(PerfectTriangleTest, 16) {
  Solution sol;
  int numSquares = sol.numSquares(16);
  int expected[] = {16};
  EXPECT_EQ(numSquares, sizeof(expected) / sizeof(int));
}
