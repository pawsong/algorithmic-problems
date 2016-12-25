#include "solution.h"

bool Solution::canPartition(std::vector<int>& nums) {
  if ( nums.size() == 0 ) {
    return true;
  }

  if ( nums.size() == 1 ) {
    return false;
  }

  int sum = 0;
  for ( int n : nums ) {
    sum += n;
  }

  if ( sum % 2 == 1 ) {
    return false;
  }

  sum /= 2;

  std::vector<bool> sumExists(sum+1, false);
  sumExists[0] = true;

  for ( int n : nums ) {
    for ( int i = sum; i >= n; i-- ) {
      sumExists[i] = sumExists[i] || sumExists[i-n];
    }
  }

  return sumExists[sum];
}
