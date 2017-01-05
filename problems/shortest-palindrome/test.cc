#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(ShortestPalindrome, Example) {
  Solution sol;

  EXPECT_EQ("aaacecaaa", sol.shortestPalindrome("aacecaaa"));
  EXPECT_EQ("aabaa", sol.shortestPalindrome("abaa"));
  EXPECT_EQ("a", sol.shortestPalindrome("a"));
  EXPECT_EQ("bab", sol.shortestPalindrome("ab"));
  EXPECT_EQ("dcbabcd", sol.shortestPalindrome("abcd"));
}
