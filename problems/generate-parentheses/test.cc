#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(GenerateParentheses, N1) {
  Solution sol;

  EXPECT_THAT(sol.generateParenthesis(1), UnorderedElementsAre("()"));
}

TEST(GenerateParentheses, N2) {
  Solution sol;

  EXPECT_THAT(sol.generateParenthesis(2), UnorderedElementsAre("(())",
                                                               "()()"));
}

TEST(GenerateParentheses, N3) {
  Solution sol;

  EXPECT_THAT(sol.generateParenthesis(3), UnorderedElementsAre("((()))",
                                                               "(()())",
                                                               "(())()",
                                                               "()(())",
                                                               "()()()"));
}
