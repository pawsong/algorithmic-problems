#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(FindMinimumInRotatedSortedArray, Example1) {
  int arr[] = { 14, 15, 16, 17, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(-2, sol.findMin(vec));
}

TEST(FindMinimumInRotatedSortedArray, Example2) {
  int arr[] = { 14, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(-2, sol.findMin(vec));
}

TEST(FindMinimumInRotatedSortedArray, Example3) {
  int arr[] = { -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(-2, sol.findMin(vec));
}
