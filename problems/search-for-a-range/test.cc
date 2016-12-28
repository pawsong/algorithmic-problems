#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(SearchForARange, Example1) {
  int arr[] = {5, 7, 7, 8, 8, 8, 8, 8, 8, 10};
  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  Solution sol;
  EXPECT_THAT(sol.searchRange( vec, 5 ), ElementsAre( 0, 0 ));
  EXPECT_THAT(sol.searchRange( vec, 7 ), ElementsAre( 1, 2 ));
  EXPECT_THAT(sol.searchRange( vec, 8 ), ElementsAre( 3, 8 ));
  EXPECT_THAT(sol.searchRange( vec, 10 ), ElementsAre( 9, 9 ));
}

TEST(SearchForARange, Example2) {
  int arr[] = {5, 7, 7, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9};
  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  Solution sol;
  EXPECT_THAT(sol.searchRange( vec, 5 ), ElementsAre( 0, 0 ));
  EXPECT_THAT(sol.searchRange( vec, 7 ), ElementsAre( 1, 2 ));
  EXPECT_THAT(sol.searchRange( vec, 8 ), ElementsAre( 3, 4 ));
  EXPECT_THAT(sol.searchRange( vec, 9 ), ElementsAre( 5, 12 ));
}
