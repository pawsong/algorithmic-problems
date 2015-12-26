
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

  Solution sol;
  std::vector<int> result;

  sol.longest_increasing_subsequence(input, result);
}
