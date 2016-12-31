#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(LongestSubstringWithoutRepeatingCharacters, Example) {
  Solution sol;

  EXPECT_EQ(0, sol.lengthOfLongestSubstring(""));
  EXPECT_EQ(1, sol.lengthOfLongestSubstring("a"));
  EXPECT_EQ(1, sol.lengthOfLongestSubstring("aa"));
  EXPECT_EQ(3, sol.lengthOfLongestSubstring("abcabcbb"));
  EXPECT_EQ(1, sol.lengthOfLongestSubstring("bbbbb"));
  EXPECT_EQ(3, sol.lengthOfLongestSubstring("pwwkew"));
  EXPECT_EQ(5, sol.lengthOfLongestSubstring("tmmzuxt"));
}
