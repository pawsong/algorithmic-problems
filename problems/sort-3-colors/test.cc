#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(Sort3Colors, ManyReds) {
  int arr[] = {0,0,0,2,1,2,0,0,0,0};

  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  int expected[] = {0,0,0,0,0,0,0,1,2,2};

  Solution sol;
  sol.sortColors(vec);

  EXPECT_THAT(vec, ElementsAreArray(expected));
}

TEST(Sort3Colors, ManyWhites) {
  int arr[] = {1,1,1,2,0,1,1,1,1};

  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  int expected[] = {0,1,1,1,1,1,1,1,2};

  Solution sol;
  sol.sortColors(vec);

  EXPECT_THAT(vec, ElementsAreArray(expected));
}

TEST(Sort3Colors, Reverse) {
  int arr[] = {2, 2, 1, 1, 0, 0};

  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  int expected[] = {0,0,1,1,2,2};

  Solution sol;
  sol.sortColors(vec);

  EXPECT_THAT(vec, ElementsAreArray(expected));
}

TEST(Sort3Colors, Repeat) {
  int arr[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  int expected[] = {0,0,0,1,1,1,2,2,2};

  Solution sol;
  sol.sortColors(vec);

  EXPECT_THAT(vec, ElementsAreArray(expected));
}

TEST(Sort3Colors, Sorted) {
  int arr[] = {0,0,0,1,1,1,2,2,2};

  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  int expected[] = {0,0,0,1,1,1,2,2,2};

  Solution sol;
  sol.sortColors(vec);

  EXPECT_THAT(vec, ElementsAreArray(expected));
}
