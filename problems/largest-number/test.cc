#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(LargestNumber, Example) {
  int arr[] = { 3, 30, 34, 5, 9 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ("9534330", sol.largestNumber(vec));
}

TEST(LargestNumber, LeadingZeros) {
  int arr[] = { 0, 0 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ("0", sol.largestNumber(vec));
}
