
#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(LongestConsecutiveSequence, Basic) {
  const int arr[] = {100, 4, 200, 1, 3, 2};
  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  Solution sol;

  EXPECT_EQ(4, sol.longestConsecutive(vec));
}

TEST(LongestConsecutiveSequence, IncreasingPositiveNumbers) {
  const int NUM_POSITIVE_NUMBERS = 10;
  std::vector<int> vec;
  for (int i=0; i<NUM_POSITIVE_NUMBERS; i++) {
    vec.push_back(i+1);
  }

  Solution sol;

  EXPECT_EQ(NUM_POSITIVE_NUMBERS, sol.longestConsecutive(vec));
}

TEST(LongestConsecutiveSequence, DecreasingPositiveNumbers) {
  const int NUM_POSITIVE_NUMBERS = 10;
  std::vector<int> vec;
  for (int i=NUM_POSITIVE_NUMBERS; i>0; i--) {
    vec.push_back(i);
  }

  Solution sol;

  EXPECT_EQ(NUM_POSITIVE_NUMBERS, sol.longestConsecutive(vec));
}

TEST(LongestConsecutiveSequence, TwoDisjointSets) {
  const int NUM_POSITIVE_NUMBERS = 10;
  std::vector<int> vec;
  for (int i=NUM_POSITIVE_NUMBERS; i>0; i--) {
    vec.push_back(i);
  }

  const int NUM_NEGATIVE_NUMBERS = NUM_POSITIVE_NUMBERS * 2;
  for (int i=NUM_NEGATIVE_NUMBERS; i>0; i--) {
    vec.push_back(-i);
  }

  Solution sol;

  EXPECT_EQ(NUM_NEGATIVE_NUMBERS, sol.longestConsecutive(vec));
}

TEST(LongestConsecutiveSequence, NegativeIntegers) {
  const int NUM_POSITIVE_NUMBERS = 10;
  std::vector<int> vec;
  for (int i=NUM_POSITIVE_NUMBERS; i>0; i--) {
    vec.push_back(i);
  }

  const int NUM_NEGATIVE_NUMBERS = NUM_POSITIVE_NUMBERS * 2;
  for (int i=NUM_NEGATIVE_NUMBERS; i>=0; i--) {
    vec.push_back(-i);
  }

  Solution sol;

  EXPECT_EQ(NUM_POSITIVE_NUMBERS + NUM_NEGATIVE_NUMBERS + 1, sol.longestConsecutive(vec));
}

TEST(LongestConsecutiveSequence, EvenOdd) {
  const int NUM_POSITIVE_NUMBERS = 10;
  std::vector<int> vec;
  for (int i=0; i<NUM_POSITIVE_NUMBERS; i++) {
    vec.push_back(2*i);
  }

  for (int i=0; i<NUM_POSITIVE_NUMBERS; i++) {
    vec.push_back(2*i+1);
  }

  Solution sol;

  EXPECT_EQ(NUM_POSITIVE_NUMBERS * 2, sol.longestConsecutive(vec));
}
