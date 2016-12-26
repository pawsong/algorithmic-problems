#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char **argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(RemoveDuplicatesFromSortedArray, Example) {
  int arr[] = {1, 1, 2};
  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  Solution sol;
  int cnt = sol.removeDuplicates(vec);
  EXPECT_EQ(2, cnt);
  EXPECT_THAT(vec, ElementsAre(1, 2));
}
