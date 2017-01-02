#include "solution.h"

static int internalSplitArray( std::vector<int> &nums, int idx, int m ) {
  if ( idx <= 0 ) {
    if ( nums.size() > 0 )
      return nums[idx];
    else
      return 0;
  }

  std::vector<int> sums( nums.size(), 0 );
  for ( int i = 0; i < sums.size(); i++ ) {
    sums[i] = nums[i];
    if ( i > 0 )
      sums[i] += sums[i-1];
  }

  if ( m == 1 ) {
    return sums[idx];
  }

  std::vector<std::vector<int>> dp( m+1, std::vector<int>(nums.size(), INT_MAX) );

  for ( int i = 0; i < dp[0].size(); i++ ) {
    dp[1][i] = sums[i];
  }

  for ( int i = 2; i <= m; i++ ) {
    for ( int j = 0; j <= idx; j++ ) {
      for ( int k = i-2; k < j; k++ ) {
        dp[i][j] = std::min( dp[i][j], std::max( sums[j] - sums[k], dp[i-1][k] ) );
      }
    }
  }

  return dp[m][idx];
}

int Solution::splitArray(std::vector<int>& nums, int m) {
  return internalSplitArray( nums, nums.size() - 1, m );
}
