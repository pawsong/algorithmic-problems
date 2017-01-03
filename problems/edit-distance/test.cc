
#include <string>
#include <vector>
#include <iostream>

#include "gmock/gmock.h"
#include "solution.h"

int main(int argc, char** argv) {
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

void test(std::string stringA, std::string stringB, int expectedDistance) {
  Solution sol;
  AlignedPair result = sol.align(stringA, stringB);

  // Verify edit distance.
  EXPECT_EQ(result.editDistance, expectedDistance);

  // Verify reconstructed strings.
  EXPECT_EQ(result.alignedA.length(), result.alignedB.length());

  int actualDistance = 0;
  for ( int i=0; i<result.alignedA.length(); i++ ) {
    if (result.alignedA[i] != result.alignedB[i]) {
      actualDistance++;
    }
  }
  EXPECT_EQ(actualDistance, expectedDistance);
}

TEST(EditDistance, SimilarWords) {
  test("POLYNOMIAL", "EXPONENTIAL", 6);
  test("INTENTION", "EXECUTION", 5);
  test("APPROXIMATE", "APPROPRIATE", 3);
}

TEST(EditDistance, SameChars) {
  test("SAMECHARS", "SAMECHARS", 0);
}

TEST(EditDistance, AllDifferenetChars) {
  test("ABCD", "EFGH", 4);
}

TEST(EditDistance, SubString) {
  test("SUBSTRING", "STRING", 3);
  test("SUBSTRING", "SUB", 6);
}

TEST(EditDistance, Phrase) {
  test("APPROPRIATE MEANING", "APPROXIMATE MATCHING", 7);
}

TEST(EditDistance, Misc) {
  Solution sol;
  EXPECT_EQ(0, sol.minDistance("", ""));
  EXPECT_EQ(1, sol.minDistance("", "A"));
  EXPECT_EQ(3, sol.minDistance("ABCD", "A"));
  EXPECT_EQ(0, sol.minDistance("ABCD", "ABCD"));
  EXPECT_EQ(1, sol.minDistance("ABCD", "ABCE"));
  EXPECT_EQ(2, sol.minDistance("ABCD", "ABDC"));
  EXPECT_EQ(2, sol.minDistance("DABC", "ABCD"));
  EXPECT_EQ(4, sol.minDistance("ABCD", "DCBA"));
}
