#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(LeavingString, Example1) {
  Solution sol;

  std::string s1( "aabcc" );
  std::string s2( "dbbca" );

  EXPECT_EQ(true, sol.isInterleave(s1, s2, "aadbbcbcac"));
  EXPECT_EQ(false, sol.isInterleave(s1, s2, "aadbbbaccc"));
}

TEST(LeavingString, Example2) {
  Solution sol;

  std::string s1( "aa" );
  std::string s2( "ab" );

  EXPECT_EQ(true, sol.isInterleave(s1, s2, "abaa"));
  EXPECT_EQ(false, sol.isInterleave(s1, s2, "baaa"));
}
