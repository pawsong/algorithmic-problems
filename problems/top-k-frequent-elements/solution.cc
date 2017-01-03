#include <unordered_map>
#include "solution.h"

std::vector<int> Solution::topKFrequent(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> cntOf;
  for ( int n : nums ) {
    if ( cntOf.find(n) == cntOf.end() ) {
      cntOf[ n ] = 0;
    }
    cntOf[ n ]++;
  }

  std::vector<std::vector<int>> bucket( nums.size() + 1 );
  for ( const auto &pair : cntOf ) {
    bucket[ pair.second ].push_back( pair.first );
  }

  std::vector<int> ret;
  for ( int i = bucket.size() - 1; i >= 0; i-- ) {
    if ( ret.size() < k ) {
      ret.insert( ret.end(), bucket[i].begin(), bucket[i].end() );
    }
  }

  return ret;
}
