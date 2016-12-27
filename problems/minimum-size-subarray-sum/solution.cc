#include "solution.h"

int Solution::minSubArrayLen(int s, std::vector<int>& nums) {
  int n = nums.size();

  int start = 0;

  int sum = 0;
  int minimalLength = -1;

  for ( int i = 0; i < nums.size(); i++ ) {
    sum += nums[i];

    while ( start <= i && sum >= s ) {
      if ( minimalLength == -1 || minimalLength > i - start + 1 )
        minimalLength = i - start + 1;
      sum -= nums[start++];
    }
  }

  return minimalLength == -1 ? 0 : minimalLength;
}
