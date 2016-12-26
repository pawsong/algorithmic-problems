#include "solution.h"

namespace i {

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

}

namespace ii {

int Solution::removeDuplicates(std::vector<int>& sortedNums) {
  if ( sortedNums.size() <= 1 ) {
    return sortedNums.size();
  }

  int cnt = 0;

  int tmp = sortedNums[0];
  for( int i=0; i<sortedNums.size(); i++ ) {
    if ( i > 1 ) {
      if ( i-1 == cnt ) {
        if ( tmp == sortedNums[i] && sortedNums[i-1] == sortedNums[i] ) {
          continue;
        }
      }
      else if ( sortedNums[i-2] == sortedNums[i] && sortedNums[i-1] == sortedNums[i] ) {
        continue;
      }
    }

    tmp = sortedNums[cnt];
    sortedNums[cnt++] = sortedNums[i];
  }

  sortedNums.resize(cnt);

  return sortedNums.size();
}

}
