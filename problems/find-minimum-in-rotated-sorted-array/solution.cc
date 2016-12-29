#include "solution.h"

int Solution::findMin(std::vector<int>& nums) {
  if ( nums.size() == 0 ) {
    return -1;
  }
  else if ( nums.back() >= nums[0] ) {
    return nums[0];
  }

  int lo = 0, hi = nums.size() - 1;

  while ( lo <= hi ) {
    int mid = (lo + hi) / 2;

    if ( nums[0] <= nums[mid] ) {
      lo = mid + 1;
    }
    else /*if ( nums[0] > nums[mid] )*/ {
      hi = mid - 1;
    }
  }

  return nums[lo];
}
