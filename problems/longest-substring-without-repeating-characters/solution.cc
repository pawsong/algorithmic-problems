#include <unordered_map>
#include "solution.h"

int Solution::lengthOfLongestSubstring(std::string s) {
  std::unordered_map<char, int> lastIndexOf;

  int i = 0;
  int maxLength = 0;

  for ( int j = 0; j < s.size(); j++ ) {
    if ( lastIndexOf.find( s[j] ) != lastIndexOf.end() ) {
      i = std::max( i, lastIndexOf[ s[j] ] + 1 );
    }

    lastIndexOf[ s[j] ] = j;
    maxLength = std::max( maxLength, j - i + 1 );
  }

  return maxLength;
}
