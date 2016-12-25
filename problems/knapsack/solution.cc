#include "solution.h"

int Solution::knapsackWithRepetition(const std::vector<KnapsackItem>& items, int maxWeight) {
  std::vector<int> maxValues( maxWeight + 1, 0 );

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

int Solution::knapsackWithoutRepetition(const std::vector<KnapsackItem>& items, int maxWeight) {
  std::vector<std::vector<unsigned>> sols( items.size()+1, std::vector<unsigned>(maxWeight+1, 0) );

  for ( int i=1; i<=items.size(); i++ ) {
    const auto &item = items[i-1];
    for ( int w=1; w<=maxWeight; w++ ) {
      if ( w < item.weight ) {
        sols[i][w] = sols[i-1][w];
      }
      else {
        sols[i][w] = sols[i-1][w - item.weight] + item.value;
        if ( sols[i-1][w] > sols[i][w] ) {
          sols[i][w] = sols[i-1][w];
        }
      }
    }
  }

  return sols[ items.size() ][ maxWeight ];
}
