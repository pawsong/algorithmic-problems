#include "solution.h"

int Solution::knapsackWithRepetition(const std::vector<KnapsackItem>& items, int maxWeight) {
  std::vector<int> maxValues( maxWeight + 1, 0 );

  // Solve the rest of subproblems.
  for ( int i=0; i<items.size(); i++ ) {
    for ( int j=items[i].weight; j<=maxWeight; j++ ) {
      int value = maxValues[ j - items[i].weight ] + items[i].value;
      if ( value > maxValues[j] ) {
        maxValues[j] = value;
      }
    }
  }

  return maxValues.back();
}
