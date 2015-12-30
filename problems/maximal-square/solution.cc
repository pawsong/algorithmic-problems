
#include <vector>

#include "solution.h"

int Solution::maximalSquare( std::vector< std::vector<char> >& matrix ) {

  std::vector< std::vector<int> > solutions;
  for ( int i=0; i<matrix.size(); i++ ) {
    std::vector<int> row (matrix[0].size(), 0);
    solutions.push_back(row);
  }

  int maximalWidth = 0;

  // Solutions for the base cases.
  for ( int i=0; i<matrix.size(); i++ ) {
    if (matrix[i][0] == '1') {
      solutions[i][0] = 1;
      if ( maximalWidth < 1 ) {
        maximalWidth = 1;
      }
    }
  }

  if ( matrix.size() > 0 ) {
    for ( int j=0; j<matrix[0].size(); j++ ) {
      if (matrix[0][j] == '1') {
        solutions[0][j] = 1;
        if ( maximalWidth < 1 ) {
          maximalWidth = 1;
        }
      }
    }
  }

  // Solutions for the rest of subproblems.
  for ( int i=1; i<matrix.size(); i++ ) {
    for ( int j=1; j<matrix[i].size(); j++ ) {
      if ( matrix[i][j] == '1' && solutions[i-1][j-1] > 0 && solutions[i-1][j] > 0 && solutions[i][j-1] > 0 ) {
        solutions[i][j] = std::min<int>(std::min<int>(solutions[i-1][j-1], solutions[i-1][j]), solutions[i][j-1]) + 1;
      }
      else {
        solutions[i][j] = matrix[i][j] == '1' ? 1 : 0;
      }

      // Update max.
      if ( maximalWidth < solutions[i][j] ) {
        maximalWidth = solutions[i][j];
      }
    }
  }

  return maximalWidth * maximalWidth;
}
