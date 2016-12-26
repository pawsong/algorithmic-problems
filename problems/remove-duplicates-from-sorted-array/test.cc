#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char **argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(RemoveDuplicatesFromSortedArray, ExampleI) {
  int arr[] = {1, 1, 2};
  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  i::Solution sol;
  int cnt = sol.removeDuplicates(vec);
  EXPECT_EQ(2, cnt);
  EXPECT_THAT(vec, ElementsAre(1, 2));
}

TEST(RemoveDuplicatesFromSortedArray, ExampleII) {
  int arr[] = {1, 1, 2, 3, 3, 4, 5, 5};
  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  ii::Solution sol;
  int cnt = sol.removeDuplicates(vec);
  EXPECT_EQ(8, cnt);
  EXPECT_THAT(vec, ElementsAre(1, 1, 2, 3, 3, 4, 5, 5));
}
