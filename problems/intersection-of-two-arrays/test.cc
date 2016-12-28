#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char **argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(Intersection, Example1) {
  int arr1[] = {1, 2, 2, 1};
  int arr2[] = {2, 2};

  std::vector<int> vec1( arr1, arr1+sizeof(arr1)/sizeof(arr1[0]) );
  std::vector<int> vec2( arr2, arr2+sizeof(arr2)/sizeof(arr2[0]) );

  Solution sol;
  EXPECT_THAT(sol.intersection(vec1, vec2), UnorderedElementsAre(2));
}

TEST(Intersection, Example2) {
  int arr1[] = {1, 2, 2, 1, 3, 3, 3, 4, 5, 7};
  int arr2[] = {2, 2, 3, 10, 11, 12, 13, 14, 15, 16, 100};

  std::vector<int> vec1( arr1, arr1+sizeof(arr1)/sizeof(arr1[0]) );
  std::vector<int> vec2( arr2, arr2+sizeof(arr2)/sizeof(arr2[0]) );

  Solution sol;
  EXPECT_THAT(sol.intersection(vec1, vec2), UnorderedElementsAre(2, 3));
}
