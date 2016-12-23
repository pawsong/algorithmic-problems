#include <vector>
#include "solution.h"

bool Solution::isValid(std::string s) {
  std::vector< char > stack;
  stack.reserve(s.size());

  for ( char c : s ) {
    switch( c ) {
    case '(':
    case '[':
    case '{':
      stack.push_back(c);
      break;
    case ')':
      if (stack.size() == 0 || stack.back() != '(')
        return false;
      stack.pop_back();
      break;
    case ']':
      if (stack.size() == 0 || stack.back() != '[')
        return false;
      stack.pop_back();
      break;
    case '}':
      if (stack.size() == 0 || stack.back() != '{')
        return false;
      stack.pop_back();
      break;
    default:
      return false;
    }
  }

  return stack.size() == 0 ? true : false;
}
