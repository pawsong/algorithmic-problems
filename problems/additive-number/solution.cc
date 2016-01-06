
#include <vector>

#include "solution.h"

class Descriptor {
public:
  int idx;
  int digits;
  Descriptor() : idx(-1), digits(0) {}
  Descriptor(int i, int d) : idx(i), digits(d) {}
  Descriptor(const Descriptor& n) : idx(n.idx), digits(n.digits) {}
};

long long parse(const std::string& num, const Descriptor& ds) {
  if ( ds.idx < num.size() && ds.digits <= ds.idx+1) {
    return std::stoll(num.substr(ds.idx - (ds.digits-1), ds.digits));
  }
  return -1;
}


template <class T>
class Pair {
private:
  std::vector<T> nums;
  int size;
public:
  Pair() : nums(2), size(0) {}
  Pair(const Pair& pair) : nums(pair.nums), size(pair.size) {}

  const T& at( int i ) const {
    return nums.at(i);
  }
  void push(T num) {
    nums[1] = nums[0];
    nums[0] = num;
    if (size<2) size++;
  }
  int getSize() const {
    return size;
  }
};

bool Solution::isAdditiveNumber(std::string num) {
  if (num.size() < 3) {
    return false;
  }

  std::vector< Pair<Descriptor> > stack (1);

  while ( stack.size() > 0 ) {
    Pair<Descriptor> pair = stack[stack.size() - 1];
    stack.pop_back();

    int pairSize = pair.getSize();

    if ( pairSize == 0 ) {
      int maxDigits = (num.size() - 1) / 2 + 1;
      int numDigits = 1;

      while ( numDigits <= maxDigits ) {
        Descriptor cur (num.size() - 1, numDigits);
        if (numDigits == 1 || num[cur.idx - cur.digits + 1] != '0') {
          stack.push_back(pair);
          stack[stack.size() - 1].push(cur);
        }
        numDigits++;
      }
    }
    else if ( pairSize == 1 ) {
      int maxDigits = pair.at(0).digits;
      int numDigits = 1;

      while ( numDigits <= maxDigits ) {
        Descriptor cur (pair.at(0).idx - pair.at(0).digits, numDigits);
        if (numDigits == 1 || num[cur.idx - cur.digits + 1] != '0') {
          stack.push_back(pair);
          stack[stack.size() - 1].push(cur);
        }
        numDigits++;
      }
    }
    else {
      long long target = ::parse(num, pair.at(1)) - ::parse(num, pair.at(0));

      int maxDigits = std::max(pair.at(0).digits, pair.at(1).digits);
      int numDigits = 1;

      while ( numDigits <= maxDigits ) {
        Descriptor cur (pair.at(0).idx-pair.at(0).digits, numDigits);
        if ( target == ::parse(num, cur) ) {
          if (cur.idx - cur.digits < 0) {
            return true;
          }
          stack.push_back(pair);
          stack[stack.size()-1].push(cur);
          break;
        }
        numDigits++;
      }
    }
  }

  return false;
}
