#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char **argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(SearchInsertPosition, Example1) {
  int arr[] = {1, 3, 5, 6, 9};
  std::vector<int> vec(arr, arr+sizeof(arr)/sizeof(arr[0]));

  Solution sol;
  EXPECT_EQ(0, sol.searchInsert(vec, 0));
  EXPECT_EQ(0, sol.searchInsert(vec, 1));
  EXPECT_EQ(1, sol.searchInsert(vec, 2));
  EXPECT_EQ(1, sol.searchInsert(vec, 3));
  EXPECT_EQ(2, sol.searchInsert(vec, 4));
  EXPECT_EQ(2, sol.searchInsert(vec, 5));
  EXPECT_EQ(4, sol.searchInsert(vec, 7));
  EXPECT_EQ(4, sol.searchInsert(vec, 8));
  EXPECT_EQ(4, sol.searchInsert(vec, 9));
  EXPECT_EQ(5, sol.searchInsert(vec, 10));
}
