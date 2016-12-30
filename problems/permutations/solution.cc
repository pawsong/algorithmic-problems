#include "solution.h"

class StackFrame {
public:
  std::vector<int> partialSolutions;
  std::vector<bool> bitVector;

  StackFrame(int n) : partialSolutions(), bitVector(n, false) {}
  StackFrame(const StackFrame& s) : partialSolutions(s.partialSolutions), bitVector(s.bitVector) {}

  int size() const {
    return partialSolutions.size();
  }

  bool find( int idx ) const {
    if ( idx < bitVector.size() ) {
      return bitVector[idx];
    }
    return false;
  }

  void add( int num, int idx ) {
    if ( idx < bitVector.size() && bitVector[idx] == false ) {
      partialSolutions.push_back(num);
      bitVector[idx] = true;
    }
  }
};

std::vector< std::vector<int> > Solution::permute( std::vector<int>& nums ) {
  std::vector< std::vector<int> > permutations;

  std::vector< StackFrame > stack;
  stack.emplace_back(nums.size());

  while ( stack.empty() == false ) {
    StackFrame frame = stack.back();
    stack.pop_back();

    int k = frame.size();
    int n = nums.size();

    if ( k == n ) {
      permutations.emplace_back(frame.partialSolutions);
    }
    else if ( k < n ) {
      // Total (n - k) candidates remaining.
      for ( int idx = 0; idx < n; idx++ ) {
        if ( frame.find(idx) == false ) {
          stack.emplace_back(frame);
          stack.back().add(nums[idx], idx);
        }
      }
    }
  }

  return permutations;
}
