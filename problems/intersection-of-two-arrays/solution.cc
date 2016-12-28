#include <unordered_set>
#include "solution.h"

std::vector<int> Solution::intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
  if ( nums2.size() > nums1.size() ) {
    return intersection(nums2, nums1);
  }

  std::unordered_set<int> lookupTbl;
  std::vector<int> ret;

  for( int n : nums1 ) {
    lookupTbl.insert( n );
  }

  for( int n : nums2 ) {
    if ( lookupTbl.find( n ) != lookupTbl.end() ) {
      lookupTbl.erase(n);
      ret.push_back(n);
    }
  }

  return ret;
}
