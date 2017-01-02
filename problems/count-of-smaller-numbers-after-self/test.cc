#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(CountOfSmallerNumbersAfterSelf, MonotonicallyIncreasing) {
  int arr[] = { 1, 2, 3, 4, 5 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_THAT(sol.countSmaller(vec), ElementsAre( 0, 0, 0, 0, 0 ));
}

TEST(CountOfSmallerNumbersAfterSelf, MonotonicallyDecreasing) {
  int arr[] = { 5, 4, 3, 2, 1 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_THAT(sol.countSmaller(vec), ElementsAre( 4, 3, 2, 1, 0 ));
}

TEST(CountOfSmallerNumbersAfterSelf, DuplicateNumbers) {
  int arr[] = { 6, 5, 5, 5, 5 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_THAT(sol.countSmaller(vec), ElementsAre( 4, 0, 0, 0, 0 ));
}
