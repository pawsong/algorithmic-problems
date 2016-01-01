
#include <iostream>

#include "solution.h"

void backtrack(std::vector<int>& a, int k, std::vector< std::vector<int> >& solutionSet, const std::vector<int>& input, int target) {

  int sum = 0;
  for (int i=0; i<k; i++) {
    sum += input[i] * a[i];
  }

  if (sum == target) {
    std::vector<int> solution;
    for (int i=0; i<k; i++) {
      for (int j=0; j<a[i]; j++) {
        solution.push_back(input[i]);
      }
    }
    std::sort(solution.begin(), solution.end());
    solutionSet.push_back(solution);
  }
  else if ( k < a.size() ) {
    std::vector<int> candidates;
    int c = 0;
    while ( c * input[k] <= target - sum ) {
      candidates.push_back(c);
      c++;
    }

    for (int i=0; i<candidates.size(); i++) {
      a[k] = candidates[i];
      ::backtrack(a, k+1, solutionSet, input, target);
    }
  }
}

std::vector< std::vector<int> > Solution::combinationSum(std::vector<int>& candidates, int target) {

  std::vector< std::vector<int> > solutionSet;

  std::vector<int> a ( candidates.size(), 0 );
  ::backtrack(a, 0, solutionSet, candidates, target);

  return solutionSet;
}
