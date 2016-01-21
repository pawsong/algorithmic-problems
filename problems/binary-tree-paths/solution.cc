
#include <cassert>

#include "solution.h"

static void dfs( TreeNode* tn, std::string& str, std::vector<std::string>& ret ) {
  assert( tn != NULL );

  str += std::to_string(tn->val);

  if (tn->left) {
    std::string strleft = str + "->";
    dfs( tn->left, strleft, ret );
  }

  if (tn->right) {
    std::string strright = str + "->";
    dfs( tn->right, strright, ret );
  }

  // Reached a leaf node.
  if (tn->left == NULL && tn->right == NULL) {
    ret.push_back(str);
  }
}

std::vector<std::string> Solution::binaryTreePaths( TreeNode* root ) {
  std::vector<std::string> ret;

  if ( root == NULL ) {
    return ret;
  }

  std::string str;
  ::dfs( root, str, ret );

  return ret;
}
