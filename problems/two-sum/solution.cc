#include <unordered_map>
#include "solution.h"

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> hashTbl;

  for ( int i = 0; i < nums.size(); i++ ) {
    int n = nums[i];

    if ( hashTbl.find(target - n) == hashTbl.end() ) {
      hashTbl[n] = i;
    }
    else {
      std::vector<int> ret(2);
      ret[0] = hashTbl[target - n];
      ret[1] = i;
      return ret;
    }
  }

  return std::vector<int>(0);
}
