#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(TopKFrequentElements, Example) {
  int arr[] = { 3, 1, 2, 1, 1, 2 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_THAT(sol.topKFrequent(vec, 1), ElementsAre(1));
  EXPECT_THAT(sol.topKFrequent(vec, 2), ElementsAre(1, 2));
  EXPECT_THAT(sol.topKFrequent(vec, 3), ElementsAre(1, 2, 3));
}
