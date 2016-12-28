#include "solution.h"

bool Solution::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
  if ( matrix.size() == 0 )
    return false;

  int i = 0;
  while ( i < matrix.size() - 1 ) {
    if ( target >= matrix[i][0] && target < matrix[i+1][0] ) {
      break;
    }
    i++;
  }

  int lo = 1;
  int hi = matrix[i].size();

  while ( lo <= hi ) {
    int mid = lo + (hi - lo) / 2;

    int n = matrix[i][mid-1];

    if ( n < target ) {
      lo = mid + 1;
    }
    else if ( n > target ) {
      hi = mid - 1;
    }
    else {
      return true;
    }
  }

  return false;
}
