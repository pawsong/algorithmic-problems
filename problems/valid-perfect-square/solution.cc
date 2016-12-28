#include "solution.h"

bool Solution::isPerfectSquare(int num) {
  if ( num <= 0 ) {
    return false;
  }

  int sqrt = num;
  int scale = num;
  while ( scale >= 2 ) {
    long long int cur = sqrt;
    cur *= cur;
    scale = (scale + 1) / 2;
    if ( cur < num ) {
      sqrt += scale;
    }
    else if ( cur > num ) {
      sqrt -= scale;
    }
  }

  return sqrt * sqrt == num ? true : false;
}
