#include "gmock/gmock.h"
#include "solution.h"

int main( int argc, char **argv ) {
  testing::InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(MinimumSizeSubarraySum, Example) {
  int arr[] = {2, 3, 1, 2, 4, 3};
  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );
  Solution sol;
  EXPECT_EQ( 2, sol.minSubArrayLen(7, vec) );
}

TEST(MinimumSizeSubarraySum, 1Elem) {
  int arr[] = {9};
  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );
  Solution sol;
  EXPECT_EQ( 1, sol.minSubArrayLen(7, vec) );
}

TEST(MinimumSizeSubarraySum, 1ElemFail) {
  int arr[] = {9};
  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );
  Solution sol;
  EXPECT_EQ( 0, sol.minSubArrayLen(11, vec) );
}

TEST(MinimumSizeSubarraySum, Empty) {
  std::vector<int> vec;
  Solution sol;
  EXPECT_EQ( 0, sol.minSubArrayLen(7, vec) );
}
