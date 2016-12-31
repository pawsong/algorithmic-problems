#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(TwoSum, Example) {
  int arr[] = { 2, 7, 11, 15 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;
  EXPECT_THAT(sol.twoSum(vec, 9), ElementsAre(0, 1));
}
