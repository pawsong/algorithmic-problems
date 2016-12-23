#include "solution.h"

static void internalPartition( const std::string& s, int idx, std::vector<std::string>& p, std::vector<std::vector<std::string>>& ret ) {
  for ( int i = idx; i < s.size(); i++ ) {
    std::vector<std::string> partitions = p;

    int l = idx, r = i;
    while ( l < r && s[l] == s[r] ) {
      l++;
      r--;
    }

    if ( l >= r ) {
      partitions.push_back(s.substr(idx, i - idx + 1));

      if ( i == s.size() - 1 ) {
        ret.push_back(partitions);
      }
      else {
        internalPartition(s, i+1, partitions, ret);
      }
    }
  }
}

std::vector<std::vector<std::string>> Solution::partition(std::string s) {
  std::vector<std::vector<std::string>> ret;
  std::vector<std::string> partitions;
  internalPartition(s, 0, partitions, ret);
  return ret;
}
