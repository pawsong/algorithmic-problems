#include <climits>
#include "solution.h"

std::vector<int> Solution::maxSlidingWindow(std::vector<int>& nums, int k) {
  if ( nums.size() < k || k <= 0 ) {
    return std::vector<int>();
  }

  std::vector<int> leftToRight( nums.size(), INT_MIN );

  for ( int i = 0; i < nums.size(); i++ ) {
    if ( i % k == 0 ) {
      leftToRight[i] = nums[i];
      continue;
    }

    leftToRight[i] = std::max( leftToRight[i-1], nums[i] );
  }

  std::vector<int> rightToLeft( nums.size(), INT_MIN );

  for ( int i = nums.size() - 1; i >= 0; i-- ) {
    if ( i % k == k - 1 || i == nums.size() - 1 ) {
      rightToLeft[i] = nums[i];
      continue;
    }

    rightToLeft[i] = std::max( rightToLeft[i+1], nums[i] );
  }

  std::vector<int> maxArr( nums.size() - k + 1 );

  for ( int i = 0; i < maxArr.size(); i++ ) {
    maxArr[i] = std::max( rightToLeft[i], leftToRight[i + k - 1] );
  }

  return maxArr;
}
