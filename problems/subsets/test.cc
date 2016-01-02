
#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(SubsetsTest, 3Elements) {
  Solution sol;

  std::vector<int> nums;
  for (int i=0; i<3; i++) {
    nums.push_back(i+1);
  }
  EXPECT_THAT(sol.subsets(nums),
              UnorderedElementsAre(ElementsAre(),
                                   ElementsAre(1),
                                   ElementsAre(2),
                                   ElementsAre(3),
                                   ElementsAre(1, 2),
                                   ElementsAre(1, 3),
                                   ElementsAre(2, 3),
                                   ElementsAre(1, 2, 3)));
}
