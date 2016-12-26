#include "solution.h"

int Solution::removeDuplicates(std::vector<int>& sortedNums) {
  int cnt = 0;

  for( int i=0; i<sortedNums.size(); i++ ) {
    if ( i > 0 && sortedNums[i-1] == sortedNums[i] ) {
      continue;
    }

    sortedNums[cnt++] = sortedNums[i];
  }

  sortedNums.resize(cnt);

  return sortedNums.size();
}
