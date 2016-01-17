
#include <cassert>
#include <string>
#include <sstream>

#include "solution.h"

class Number {
private:
  std::vector<char> digits;
public:
  Number() : digits() {}
  Number( int n ) : digits(1, n) {}
  Number( const Number& n ) : digits(n.digits) {}

  void push( int digit ) {
    digits.push_back(digit);
  }
  size_t size() const {
    return digits.size();
  }
  std::vector<int> vector() const {
    std::vector<int> ret;
    for (const auto& digit : digits) {
      ret.push_back(int(digit));
    }
    return ret;
  }
  std::string str() const{
    std::stringstream ss;
    for ( const auto& digit : digits ) {
      ss << digit;
    }
    return ss.str();
  }
  friend bool operator<(const Number& A, const Number& B) {
    if ( A.size() == B.size() ) {
      for (int i=0; i<A.size(); i++) {
        if (A.digits[i] == B.digits[i])
          continue;
        return A.digits[i] < B.digits[i];
      }
    }
    return A.size() < B.size();
  }
  friend bool operator>(const Number& A, const Number& B) {
    return !(A<B);
  }
};

std::vector<int> Solution::maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int K) {

  // Special cases.
  if ( K < 1 || nums1.size() + nums2.size() < K )
    return std::vector<int>();

  std::vector< std::vector< std::vector< Number > > > solutions ( 2, std::vector< std::vector< Number > > (nums1.size() + 1, std::vector< Number > (nums2.size() + 1, Number())) );

  // Base cases. ( k=1 )
  int k = 1;
  auto& matrix = solutions[k - 1];
  int max = -1;

  assert( matrix.size() == nums1.size() + 1 );
  for ( int i=1; i<matrix.size(); i++ ) {
    if ( max < nums1[i-1] ) {
      max = nums1[i-1];
    }
    matrix[i][0] = Number( max );
  }

  max = -1;
  assert (matrix[0].size() == nums2.size() + 1 );
  for ( int j=1; j<matrix[0].size(); j++ ) {
    if ( max < nums2[j-1] ) {
      max = nums2[j-1];
    }
    matrix[0][j] = Number( max );
  }

  for ( int i=1; i<matrix.size(); i++ ) {
    for ( int j=1; j<matrix[i].size(); j++ ) {
      matrix[i][j] = (matrix[i-1][j] > matrix[i][j-1]) ? matrix[i-1][j] : matrix[i][j-1];
    }
  }

  // Solve the rest of the subproblems. ( k=2, 3, ..., K )
  while ( ++k <= K ) {
    auto& prev = solutions[(k - 2) % solutions.size()];
    auto& matrix = solutions[(k - 1) % solutions.size()];

    for ( int i=0; i<matrix.size(); i++ ) {
      for ( int j=0; j<matrix[i].size(); j++ ) {
        if ( i + j  < k )
          continue;

        Number max;
        if ( i > 0 ) {
          Number num = prev[i-1][j];
          num.push(nums1[i-1]);
          if (max < num) {
            max = num;
          }

          if (max < matrix[i-1][j]) {
            max = matrix[i-1][j];
          }
        }
        if ( j > 0 ) {
          Number num = prev[i][j-1];
          num.push(nums2[j-1]);
          if (max < num) {
            max = num;
          }

          if (max < matrix[i][j-1]) {
            max = matrix[i][j-1];
          }
        }

        assert( max.size() > 0 );
        matrix[i][j] = max;
      }
    }
  }

  return solutions[(K-1) % solutions.size()].back().back().vector();
}
