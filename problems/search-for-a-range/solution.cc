#include "solution.h"

std::vector<int> Solution::searchRange(std::vector<int>& nums, int target) {
  std::vector<int> ret(2, -1);

  if (nums.size() == 0)
    return ret;

  int lo = 0, hi = nums.size() - 1;

  while ( lo <= hi ) {
    int mid = (lo + hi) / 2;

    int n = nums[mid];
    if ( n < target ) {
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
  }

  ret[0] = nums[lo] == target ? lo : -1;

  lo = 0, hi = nums.size() - 1;

  while ( lo <= hi ) {
    int mid = (lo + hi) / 2;

    int n = nums[mid];
    if ( n <= target ) {
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
  }

  ret[1] = nums[lo - 1] == target ? lo - 1 : -1;

  return ret;
}
