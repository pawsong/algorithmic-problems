#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(SortCharactersByFrequency, Example) {
  Solution sol;

  EXPECT_EQ(sol.frequencySort(""), "");
  EXPECT_EQ(sol.frequencySort("a"), "a");
  EXPECT_EQ(sol.frequencySort("ab"), "ba");
  EXPECT_EQ(sol.frequencySort("tree"), "eert");
  EXPECT_EQ(sol.frequencySort("cccaaa"), "aaaccc");
  EXPECT_EQ(sol.frequencySort("Aabb"), "bbaA");
}
