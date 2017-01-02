#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(MissingNumber, 1Elem) {
  int arr[] = { 0 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(1, sol.missingNumber(vec));
}

TEST(MissingNumber, MissingLastNumber) {
  int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(9, sol.missingNumber(vec));
}

TEST(ContainsDuplicate, Missing1) {
  int arr[] = { 2, 0, 4, 3, 7, 5, 6 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(1, sol.missingNumber(vec));
}
