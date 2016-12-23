#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(ValidParentheses, Examples) {
  Solution sol;
  EXPECT_EQ(true, sol.isValid("()"));
  EXPECT_EQ(true, sol.isValid("(()(())())"));
  EXPECT_EQ(true, sol.isValid("{(())}"));
  EXPECT_EQ(true, sol.isValid("()[]{}"));
  EXPECT_EQ(false, sol.isValid("(]"));
  EXPECT_EQ(false, sol.isValid("[(]"));
  EXPECT_EQ(false, sol.isValid("([{)]}"));
  EXPECT_EQ(false, sol.isValid("}}))}]]]"));
}
