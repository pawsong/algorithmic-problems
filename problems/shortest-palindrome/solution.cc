#include <vector>
#include "solution.h"

static std::vector<int> buildKMPIndices( std::string s ) {
  std::vector<int> kmp( s.size(), 0 );

  int j = 0;
  for ( int i = 1; i < kmp.size(); i++ ) {
    while ( j > 0 && s[j] != s[i] ) {
      j = kmp[j-1];
    }

    if ( s[j] == s[i] ) {
      kmp[i] = j + 1;
      j++;
    }
  }

  return kmp;
}

std::string Solution::shortestPalindrome(std::string s) {
  std::string r( s );
  std::reverse(r.begin(), r.end());

  std::vector<int> kmp = buildKMPIndices(s + "#" + r);

  std::string prefix = s.substr( kmp.back(), s.size() - kmp.back() );
  std::reverse( prefix.begin(), prefix.end() );

  return prefix + s;
}
