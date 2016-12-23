#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(PalindromePartitioning, Example) {
  Solution sol;
  auto possiblePartitions = sol.partition( "aab" );

  EXPECT_THAT(possiblePartitions, UnorderedElementsAre(ElementsAre("aa", "b"),
                                                       ElementsAre("a", "a", "b")));
}

TEST(PalindromePartitioning, PalindromeA) {
  Solution sol;
  auto possiblePartitions = sol.partition( "aba" );

  EXPECT_THAT(possiblePartitions, UnorderedElementsAre(ElementsAre("a", "b", "a"),
                                                       ElementsAre("aba")));
}

TEST(PalindromePartitioning, PalindromeB) {
  Solution sol;
  auto possiblePartitions = sol.partition( "babab" );

  EXPECT_THAT(possiblePartitions, UnorderedElementsAre(ElementsAre("b", "a", "b", "a", "b"),
                                                       ElementsAre("b", "aba", "b"),
                                                       ElementsAre("bab", "a", "b"),
                                                       ElementsAre("b", "a", "bab"),
                                                       ElementsAre("babab")));
}
