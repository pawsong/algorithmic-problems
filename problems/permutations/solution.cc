
#include "solution.h"

class StackCell {
public:
  std::vector<int> partialSolutions;
  std::vector<bool> bitVectors;

  StackCell(int n) : partialSolutions(), bitVectors(n, false) {}
  StackCell(const StackCell& s) : partialSolutions(s.partialSolutions), bitVectors(s.bitVectors) {}

  int size() const {
    return partialSolutions.size();
  }
  bool find(const std::vector<int>& nums, int idx) const {
    if ( idx < bitVectors.size() ) {
      return bitVectors[idx];
    }
    return false;
  }
  void add(const std::vector<int>& nums, int idx) {
    if ( idx < bitVectors.size() && bitVectors[idx] == false ) {
      partialSolutions.push_back(nums[idx]);
      bitVectors[idx] = true;
    }
  }
};

std::vector< std::vector<int> > Solution::permute( std::vector<int>& nums ) {
  std::vector< std::vector<int> > permutations;

  std::vector< StackCell > stack;
  stack.push_back(StackCell(nums.size()));

  while ( stack.empty() == false ) {
    StackCell cell = stack.back();
    stack.pop_back();

    int k = cell.size();
    int n = nums.size();

    if ( k == n ) {
      permutations.push_back(cell.partialSolutions);
    }
    else if ( k < n ) {
      // Total (n - k) candidates remaining.
      for ( int idx = 0; idx < n; idx++ ) {
        if ( cell.find(nums, idx) == false ) {
          stack.push_back(cell);
          stack[stack.size() - 1].add(nums, idx);
        }
      }
    }
  }

  return permutations;
}
