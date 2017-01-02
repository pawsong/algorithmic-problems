#include <unordered_map>
#include "solution.h"

int Solution::longestPalindrome(std::string s) {
  std::unordered_map<char, int> cntOf;

  for ( char c : s ) {
    if ( cntOf.find( c ) == cntOf.end() ) {
      cntOf[ c ] = 0;
    }
    cntOf[ c ]++;
  }

  int pLen = 0;
  bool hasResidual = false;
  for ( const auto &pair : cntOf ) {
    int residual = pair.second % 2;
    hasResidual |= (residual == 1);
    pLen += pair.second - residual;
  }

  return hasResidual ? pLen + 1 : pLen;
}
