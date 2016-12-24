#include <map>
#include "solution.h"

std::string Solution::minWindow(std::string s, std::string t) {
  if (t.size() == 0) {
    return "";
  }

  std::map<char, int> cnt;
  for ( char c : t ) {
    cnt[c] = -1;
  }

  int numMissing = cnt.size();

  int start = 0;
  int end = 0;

  int S = 0;
  int E = 0;

  for( int i=0; i<s.size(); i++ ) {
    if ( cnt.find(s[i]) == cnt.end() ) {
      continue;
    }

    auto& curCnt = cnt[ s[i] ];
    curCnt++;
    end = i;

    if ( curCnt == 0 ) {
      numMissing--;
      E = end;
      continue;
    }

    if ( numMissing > 0 ) {
      continue;
    }

    for ( ; start < end; start++ ) {
      if ( cnt.find(s[start]) == cnt.end() ) {
        continue;
      }

      if( cnt[ s[start] ] > 0 ) {
        cnt[ s[start] ]--;
      }
      else {
        break;
      }
    }

    if ( end - start < E - S ) {
      S = start;
      E = end;
    }
  }

  return numMissing == 0 ? s.substr(S, E-S+1) : "";
}
