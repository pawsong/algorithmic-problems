#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(CountOfRangeSum, Example1) {
  int arr[] = { -1, 2, -1, -2 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(1, sol.countRangeSum(vec, -5, -3));
}

TEST(CountOfRangeSum, Combinatorial) {
  int arr[] = { -1, 1, -1, 1 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(10, sol.countRangeSum(vec, -1, 1));
}
