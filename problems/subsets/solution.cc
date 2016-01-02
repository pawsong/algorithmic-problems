
#include <algorithm>

#include "solution.h"

void processSolution(const std::vector<bool>& sol, const std::vector<int>& input, std::vector< std::vector<int> >& output) {
  std::vector<int> elem;
  for (int i=0; i<sol.size(); i++) {
    if (sol[i] == true) {
      elem.push_back(input[i]);
    }
  }
  output.push_back(elem);
}

std::vector< std::vector<int> > Solution::subsets(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());

  std::vector< std::vector<int> > subSets;

  std::vector< std::vector<bool> > stack ( 1 ); // Init stack with a single empty vector.

  while ( stack.empty() == false ) {
    std::vector<bool> sol = stack.back();
    stack.pop_back();

    if ( sol.size() == nums.size() ) {
      ::processSolution(sol, nums, subSets);
    }
    else if ( sol.size() < nums.size() ) {
      int candidates[] = {true, false};
      for ( int i=0; i<2; i++ ) {
        stack.push_back(sol);
        stack[stack.size()-1].push_back(candidates[i]);
      }
    }
  }

  return subSets;
}
