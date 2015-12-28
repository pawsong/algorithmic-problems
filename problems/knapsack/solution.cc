
#include "solution.h"

int Solution::knapsackWithRepetition(const std::vector<KnapsackItem>& items, int maxWeight) {

  std::vector<int> maxValues (maxWeight + 1);

  // The max value for the zero-weight capacity knapsack is zero.
  maxValues[0] = 0;

  // Solve the rest of subproblems.
  for ( int j=1; j<=maxWeight; j++ ) {
    int maxValue = 0;

    // Each subproblem takes up to O(n) to compute.
    for ( int i=0; i<items.size(); i++ ) {
      if ( j < items[i].weight )
        continue;

      int value = maxValues[ j - items[i].weight ] + items[i].value;
      if ( value > maxValue ) {
        maxValue = value;
      }
    }
    maxValues[j] = maxValue;
  }

  return maxValues[maxValues.size() - 1];
}
