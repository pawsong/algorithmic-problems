
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

TEST(EditDistanceTest, SimilarWords) {
  test("POLYNOMIAL", "EXPONENTIAL", 6);
  test("INTENTION", "EXECUTION", 5);
  test("APPROXIMATE", "APPROPRIATE", 3);
}

TEST(EditDistanceTest, SameChars) {
  test("SAMECHARS", "SAMECHARS", 0);
}

TEST(EditDistanceTest, AllDifferenetChars) {
  test("ABCD", "EFGH", 4);
}

TEST(EditDistanceTest, SubString) {
  test("SUBSTRING", "STRING", 3);
  test("SUBSTRING", "SUB", 6);
}

TEST(EditDistanceTest, Phrase) {
  test("APPROPRIATE MEANING", "APPROXIMATE MATCHING", 7);
}
