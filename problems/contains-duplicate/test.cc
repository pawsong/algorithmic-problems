#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(ContainsDuplicate, 8ElemsDistinct) {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(false, sol.containsDuplicate(vec));
}

TEST(ContainsDuplicate, 8ElemsDuplicates) {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 1 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_EQ(true, sol.containsDuplicate(vec));
}
