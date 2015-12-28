
#include <vector>

#include "gmock/gmock.h"
#include "solution.h"

int main(int argc, char** argv) {
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

KnapsackItem createKnapsackItem(int weight, int value) {
  KnapsackItem item;
  item.weight = weight;
  item.value = value;
  return item;
}

TEST(KnapsackWithRepetitionTest, SmallCase) {

  std::vector<KnapsackItem> items;
  items.push_back(createKnapsackItem(6, 30));
  items.push_back(createKnapsackItem(3, 14));
  items.push_back(createKnapsackItem(4, 16));
  items.push_back(createKnapsackItem(2, 9));

  Solution sol;
  int actual = sol.knapsackWithRepetition(items, 10);
  int expected = 30 + 9 + 9;

  EXPECT_EQ(actual, expected);
}
