#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(LongestPalindrome, Example) {
  Solution sol;

  EXPECT_EQ(0, sol.longestPalindrome(""));
  EXPECT_EQ(1, sol.longestPalindrome("a"));
  EXPECT_EQ(1, sol.longestPalindrome("Aa"));
  EXPECT_EQ(5, sol.longestPalindrome("ababab"));
  EXPECT_EQ(6, sol.longestPalindrome("abcabc"));
  EXPECT_EQ(7, sol.longestPalindrome("abccccdd"));
}
