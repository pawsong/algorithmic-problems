#include "solution.h"

static void internalCombine(int begin, int end, int k, std::vector< std::vector<int> >& combinations, std::vector<int>& current ) {
  if ( end - begin + 1 == k ) {
    combinations.push_back(current);
    for ( int i=begin; i<=end; i++ ) {
      combinations.back().push_back( i );
    }
  }
  else if ( end - begin + 1 > k ) {
    internalCombine( begin+1, end, k, combinations, current );

    if ( k > 0 ) {
      std::vector<int> newCurrent = current;
      newCurrent.push_back(begin);
      internalCombine( begin+1, end, k-1, combinations, newCurrent );
    }
  }
}

std::vector<std::vector<int>> Solution::combine(int n, int k) {
  std::vector< std::vector<int> > combinations;
  std::vector<int> current;

  internalCombine( 1, n, k, combinations, current );

  return combinations;
}
