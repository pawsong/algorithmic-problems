
#include "solution.h"

int Solution::minimumTotal(std::vector< std::vector<int> >& triangle) {
  std::vector<int> solutions ( triangle.size() );

  int iter = 0;
  if (triangle.size() > 0 && triangle[0].size() > 0) {
    solutions[iter] = triangle[0][0];
    iter = iter + 1 % solutions.size();
  }

  for ( int i=1; i<triangle.size(); i++ ) {
    std::vector<int>& elems = triangle[i];

    for ( int j=0; j<elems.size(); j++ ) {
      int parentL = (iter + solutions.size() - i - 1) % solutions.size();
      int parentR = (iter + solutions.size() - i) % solutions.size();
      if (j==0) {
        solutions[iter] = solutions[parentR];
      }
      else if (j==elems.size()-1) {
        solutions[iter] = solutions[parentL];
      }
      else {
        solutions[iter] = std::min(solutions[parentR], solutions[parentL]);
      }
      solutions[iter] += elems[j];
      iter = (iter + 1) % solutions.size();
    }
  }

  int minSum = solutions[0];

  int i = 1;
  while ( i < solutions.size() ) {
    if (minSum > solutions[i]) {
      minSum = solutions[i];
    }
    i++;
  }

  return minSum;
}
