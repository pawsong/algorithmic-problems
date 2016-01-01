
#include <vector>

#include "solution.h"

int Solution::numSquares(int n) {

  if (n<0) return 0;

  std::vector<int> solutions ( n + 1 );

  // Solutions to the base cases.
  solutions[0] = 0;

  for ( int i=1; i<solutions.size(); i++ ) {
    int j = 1;
    solutions[i] = solutions[i-j] + 1;
    j++;

    while ( i >= j*j ) {
      solutions[i] = std::min<int>(solutions[i], solutions[i - j*j] + 1);
      j++;
    }
  }

  return solutions[solutions.size()-1];
}
