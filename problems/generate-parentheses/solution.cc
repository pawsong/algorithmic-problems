#include "solution.h"

std::vector<std::string> Solution::generateParenthesis(int n) {
  std::vector<std::vector<std::string>> solutions;
  solutions.push_back(std::vector<std::string>(1, ""));

  for ( int i = 1; i <= n; i++ ) {
    solutions.push_back(std::vector<std::string>());
    for ( int j = 0; j < i; j++ ) {
      for ( auto solA : solutions[j] ) {
        for ( auto solB : solutions[i-j-1] ) {
          solutions.back().push_back( "(" + solA + ")" + solB );
        }
      }
    }
  }

  return solutions.back();
}
