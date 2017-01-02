#include <unordered_map>
#include <vector>
#include "solution.h"

std::string Solution::frequencySort(std::string s) {
  std::unordered_map<char, int> charToCnt;
  std::vector<std::string> cntToStr( s.size() + 1, "" );

  for ( char c : s ) {
    if ( charToCnt.find( c ) == charToCnt.end() ) {
      charToCnt[ c ] = 0;
    }
    charToCnt[ c ]++;
  }

  for ( const auto &pair : charToCnt ) {
    cntToStr[pair.second].append( pair.second, pair.first );
  }

  std::string sorted;
  for ( int i = s.size(); i > 0; i-- ) {
    sorted.append( cntToStr[i] );
  }

  return sorted;
}
