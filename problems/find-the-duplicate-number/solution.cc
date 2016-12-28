#include "solution.h"

int Solution::findDuplicate(std::vector<int>& nums) {
  if ( nums.size() <= 1 )
    return -1;

  int lowerBound = 1;
  int upperBound = nums.size() - 1;
  int mid = (lowerBound + upperBound) / 2;

  while ( lowerBound < upperBound ) {
    int cnt = 0;
    for ( int n : nums ) {
      if ( n <= mid ) {
        cnt++;
      }
    }

    if ( cnt > mid ) {
      upperBound = mid;
    }
    else {
      lowerBound = mid + 1;
    }
    mid = (lowerBound + upperBound) / 2;
  }

  return lowerBound;
}
