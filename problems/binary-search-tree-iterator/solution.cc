
#include "solution.h"

int BSTIterator::next() {
  StackElement& cur = stack[stack.size() - 1];

  int ret = cur.value();
  cur.setProcessed();

  if (cur.right() != NULL) {
    traverseLeft(cur.right());
  }
  else {
    while (stack[stack.size() - 1].isProcessed()) {
      stack.pop_back();
    }
  }

  return ret;
}

