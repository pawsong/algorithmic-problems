#include "solution.h"

static double myPow(double x, long long int n) {
  if ( n == 0 ) {
    return 1;
  }
  else if ( n < 0 ) {
    x = 1/x;
    n *= -1;
  }

  double ret = 1;
  double cur = x;
  while ( n > 0 ) {
    if ( n % 2 == 1 ) {
      ret *= cur;
      n -= 1;
    }
    else {
      cur *= cur;
      n /= 2;
    }
  }

  return ret;
}

double Solution::myPow(double x, int n) {
  return ::myPow(x, (long long int)n);
}
