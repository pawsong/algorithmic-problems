#include <vector>
#include "solution.h"

bool Solution::isInterleave( std::string s1, std::string s2, std::string s3 ) {
  if ( s3.size() != s1.size() + s2.size() ) {
    return false;
  }

  std::vector< std::vector<bool> > dp( s1.size() + 1, std::vector<bool>(s2.size() + 1, true) );

  // base cases
  for ( int i = 1; i < s1.size() + 1; i++ ) {
    dp[i][0] = (s1[i-1] == s3[i-1]) && dp[i-1][0];
  }

  for ( int j = 1; j < s2.size() + 1; j++ ) {
    dp[0][j] = (s2[j-1] == s3[j-1]) && dp[0][j-1];
  }

  // subproblems
  for ( int i = 1; i < dp.size(); i++ ) {
    for ( int j = 1; j < dp[i].size(); j++ ) {
      dp[i][j] = (s1[i-1] == s3[i+j-1] && dp[i-1][j]) || (s2[j-1] == s3[i+j-1] && dp[i][j-1]);
    }
  }

  return dp.back().back();
}
