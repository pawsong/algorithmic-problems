
#include <iostream>
#include <vector>

#include "solution.h"

int main(void) {
  std::cout << "Problem: Longest increasing subsequence" << std::endl;

  std::vector<int> input;
  input.push_back(5);
  input.push_back(2);
  input.push_back(8);
  input.push_back(6);
  input.push_back(3);
  input.push_back(6);
  input.push_back(9);
  input.push_back(7);

  std::cout << "Input:" << std::endl;
  for( int i=0; i<input.size(); i++ ) {
    std::cout << input[i] << " ";
  }
  std::cout << std::endl;

  Solution sol;
  std::vector<int> seq = sol.get_longest_increasing_subsequence(input);

  std::cout << "Solution:" << std::endl;
  for( int i=0; i<seq.size(); i++ ) {
    std::cout << seq[i] << " ";
  }
  std::cout << std::endl;
}
