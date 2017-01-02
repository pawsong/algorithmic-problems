#include "solution.h"

static int mergeSort( std::vector<long long int> &nums, int start, int end, int lower, int upper ) {
  if ( start == end && nums[start] >= lower && nums[start] <= upper ) {
    return 1;
  }
  else if ( start >= end ) {
    return 0;
  }

  int mid = (start + end) / 2;

  int ret = mergeSort( nums, start, mid, lower, upper ) + mergeSort( nums, mid + 1, end, lower, upper );

  std::vector<int> tmp( end - start + 1 );

  int i = start;
  int j = mid + 1;
  int k = 0;

  while ( k < tmp.size() ) {
    if ( (i <= mid && j <= end && nums[i] <= nums[j]) || j > end ) {
      int l = j - 1;
      while ( l > mid && nums[l] - nums[i] >= lower ) {
        if ( nums[l] - nums[i] <= upper )
          ret++;
        l--;
      }

      tmp[k] = nums[i];
      i++;
    }
    else {
      int l = i - 1;
      while ( l >= start && nums[j] - nums[l] <= upper ) {
        if( nums[j] - nums[l] >= lower )
          ret++;
        l--;
      }

      tmp[k] = nums[j];
      j++;
    }

    k++;
  }

  std::copy( tmp.begin(), tmp.end(), nums.begin() + start );

  return ret;
}

int Solution::countRangeSum(std::vector<int>& nums, int lower, int upper) {
  std::vector<long long int> sums( nums.size() );

  for ( int i = 0; i < sums.size(); i ++ ) {
    sums[i] = nums[i];
    if ( i > 0 ) {
      sums[i] += sums[i-1];
    }
  }

  return mergeSort( sums, 0, sums.size() - 1, lower, upper );
}
