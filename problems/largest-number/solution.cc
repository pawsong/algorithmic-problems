#include "solution.h"

class Compare {
public:
  bool operator()( const int &A, const int& B ) {
    std::string strA = std::to_string(A).append( std::to_string(B) );
    std::string strB = std::to_string(B).append( std::to_string(A) );
    return strA > strB;
  }
};

std::string Solution::largestNumber(std::vector<int>& nums) {
  std::string ret;

  std::sort( nums.begin(), nums.end(), Compare() );

  for ( int n : nums ) {
    if ( ret.size() > 0 || n != 0 )
      ret.append( std::to_string(n) );
  }

  if ( nums.size() > 0 && ret.size() == 0 ) {
    ret.append(1, '0');
  }

  return ret;
}
