
#include <vector>

struct KnapsackItem {
  int weight;
  int value;
};

class Solution {
 public:
  int knapsackWithRepetition(const std::vector<KnapsackItem>& items, int maxWeight);
  int knapsackWithoutRepetition(const std::vector<KnapsackItem>& items, int maxWeight);
};
