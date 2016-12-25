#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char **argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(FindKPairsWithSmallestSums, Example1) {
  int arr1[] = {1,7,11};
  int arr2[] = {2,4,6};
  int k = 3;

  std::vector<int> vec1( arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]) );
  std::vector<int> vec2( arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]) );

  Solution sol;
  auto result = sol.kSmallestPairs( vec1, vec2, k );

  EXPECT_THAT( result, ElementsAre( std::make_pair(1,2),
                                    std::make_pair(1,4),
                                    std::make_pair(1,6) ) );
}


TEST(FindKPairsWithSmallestSums, Example2) {
  int arr1[] = {1,1,2};
  int arr2[] = {1,2,3};
  int k = 2;

  std::vector<int> vec1( arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]) );
  std::vector<int> vec2( arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]) );

  Solution sol;
  auto result = sol.kSmallestPairs( vec1, vec2, k );

  EXPECT_THAT( result, ElementsAre( std::make_pair(1,1),
                                    std::make_pair(1,1) ) );
}


TEST(FindKPairsWithSmallestSums, Example3) {
  int arr1[] = {1,2};
  int arr2[] = {3};
  int k = 3;

  std::vector<int> vec1( arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]) );
  std::vector<int> vec2( arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]) );

  Solution sol;
  auto result = sol.kSmallestPairs( vec1, vec2, k );

  EXPECT_THAT( result, ElementsAre( std::make_pair(1,3),
                                    std::make_pair(2,3) ) );
}
