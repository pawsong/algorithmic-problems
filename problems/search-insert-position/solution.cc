#include "solution.h"

int Solution::searchInsert(std::vector<int>& nums, int target) {
  int lo = 0, hi = nums.size() - 1;

  while ( lo <= hi ) {
    int mid = (lo + hi) / 2;

    int n = nums[ mid ];
    if ( n > target ) {
      hi = mid - 1;
    }
    else if ( n < target ) {
      lo = mid + 1;
    }
    else {
      lo = mid;
      hi = mid - 1;
    }
  }

  return lo;
}
