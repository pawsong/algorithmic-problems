
#include <iostream>
#include <vector>

#include "gmock/gmock.h"
#include "solution.h"

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(LongestIncreasingSubsequenceTest, Case1) {

  std::vector<int> input;
  input.push_back(5);
  input.push_back(2);
  input.push_back(8);
  input.push_back(6);
  input.push_back(3);
  input.push_back(6);
  input.push_back(9);
  input.push_back(7);

  Solution sol;
  std::vector<int> result = sol.get_longest_increasing_subsequence(input);

  int expected[] = {2, 3, 6, 9};
  EXPECT_THAT(result, testing::ElementsAreArray(expected));
}
