#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(MinimumWindowSubstring, Example) {
  Solution sol;
  EXPECT_EQ( sol.minWindow( "ABOBECODEBANC", "ABC" ), "BANC" );
}

TEST(MinimumWindowSubstring, InTheMiddle) {
  Solution sol;
  EXPECT_EQ( sol.minWindow( "ABOBECODEBANCOOOOAOOOOOBOOOOOC", "ABC" ), "BANC" );
}

TEST(MinimumWindowSubstring, NoMatch) {
  Solution sol;
  EXPECT_EQ( sol.minWindow( "AAAAAAAAAAAAAAAAAAAAAAAAAAAA", "ABC" ), "" );
}

TEST(MinimumWindowSubstring, Reverse) {
  Solution sol;
  EXPECT_EQ( sol.minWindow( "ABCDEFGHIJK", "KJIHGFEDCBA" ), "ABCDEFGHIJK" );
}

TEST(MinimumWindowSubstring, Competing) {
  Solution sol;
  EXPECT_EQ( sol.minWindow( "AOBOOA", "AB" ), "AOB" );
}

TEST(MinimumWindowSubstring, Empty) {
  Solution sol;
  EXPECT_EQ( sol.minWindow( "", "" ), "" );
}

TEST(MinimumWindowSubstring, NoMatch2) {
  Solution sol;
  EXPECT_EQ( sol.minWindow( "a", "aa" ), "" );
}

TEST(MinimumWindowSubstring, SmallChars) {
  Solution sol;
  EXPECT_EQ( sol.minWindow( "ab", "b" ), "b" );
}

TEST(MinimumWindowSubstring, SameChars) {
  Solution sol;
  EXPECT_EQ( sol.minWindow( "aa", "aa" ), "aa" );
}
