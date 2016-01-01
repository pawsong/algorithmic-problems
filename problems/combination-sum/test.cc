
#include <vector>
#include <iterator>

#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(CombinationSumTest, Sum8) {
  int input[] = {2, 3, 5};
  int target = 8;

  Solution sol;
  std::vector<int> candidates (std::begin(input), std::end(input));
  std::vector< std::vector<int> > solutions = sol.combinationSum(candidates, target);

  EXPECT_THAT(solutions, UnorderedElementsAre(ElementsAre(2, 2, 2, 2), ElementsAre(2, 3, 3), ElementsAre(3, 5)));
}

TEST(CombinationSumTest, Sum7) {
  int input[] = {2, 3, 6, 7};
  int target = 7;

  Solution sol;
  std::vector<int> candidates (std::begin(input), std::end(input));
  std::vector< std::vector<int> > solutions = sol.combinationSum(candidates, target);

  EXPECT_THAT(solutions, UnorderedElementsAre(ElementsAre(7), ElementsAre(2, 2, 3)));
}

TEST(CombinationSumTest, Sum16) {
  int input[] = {4, 6, 10, 16};
  int target = 16;

  Solution sol;
  std::vector<int> candidates (std::begin(input), std::end(input));
  std::vector< std::vector<int> > solutions = sol.combinationSum(candidates, target);

  for (int i=0; i<solutions.size(); i++) {
    int actualSum = 0;
    for (int j=0; j<solutions[i].size(); j++) {
      actualSum += solutions[i][j];
    }
    EXPECT_EQ(actualSum, target);
  }

  EXPECT_THAT(solutions,
              UnorderedElementsAre(ElementsAre(16),
                                   ElementsAre(6, 10),
                                   ElementsAre(4, 6, 6),
                                   ElementsAre(4, 4, 4, 4)));
}

TEST(CombinationSumTest, Sum11) {
  int input[] = {8, 7, 4, 3};
  int target = 11;

  Solution sol;
  std::vector<int> candidates (std::begin(input), std::end(input));
  std::vector< std::vector<int> > solutions = sol.combinationSum(candidates, target);

  for (int i=0; i<solutions.size(); i++) {
    int actualSum = 0;
    for (int j=0; j<solutions[i].size(); j++) {
      actualSum += solutions[i][j];
    }
    EXPECT_EQ(actualSum, target);
  }

  EXPECT_THAT(solutions,
              UnorderedElementsAre(ElementsAre(3, 4, 4),
                                   ElementsAre(3, 8),
                                   ElementsAre(4, 7)));
}

TEST(CombinationSumTest, Sum21) {
  int input[] = {6, 9, 7, 4, 5, 3, 10, 12};
  int target = 21;

  Solution sol;
  std::vector<int> candidates (std::begin(input), std::end(input));
  std::vector< std::vector<int> > solutions = sol.combinationSum(candidates, target);

  for (int i=0; i<solutions.size(); i++) {
    int actualSum = 0;
    for (int j=0; j<solutions[i].size(); j++) {
      actualSum += solutions[i][j];
    }
    EXPECT_EQ(actualSum, target);
  }
}
