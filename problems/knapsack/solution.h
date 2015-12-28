
#include <vector>

struct KnapsackItem {
  int weight;
  int value;
};

class Solution {
 public:
  Solution() {}

  int knapsackWithRepetition(const std::vector<KnapsackItem>& items, int maxWeight);
};
