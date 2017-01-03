#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(SlidingWindowMaximum, Example) {
  int arr[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
  std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  Solution sol;

  EXPECT_THAT(sol.maxSlidingWindow(vec, 3), ElementsAre(3, 3, 5, 5, 6, 7));
}
