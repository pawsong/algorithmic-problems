#include <set>
#include "solution.h"

bool Solution::containsDuplicate(std::vector<int>& nums) {
  std::set<int> numsDistinct;

  for( const int &n : nums ) {
    auto it = numsDistinct.find(n);
    if (it != numsDistinct.end()) {
      return true;
    }
    numsDistinct.insert(n);
  }

  return false;
}
