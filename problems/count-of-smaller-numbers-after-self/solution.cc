#include "solution.h"

class TreeNode {
public:
  int val;
  int sz;

  TreeNode *left;
  TreeNode *right;

  TreeNode(int v) : val(v), sz(1), left(nullptr), right(nullptr) {}

  int getLeftSz() const {
    return left == nullptr ? 0 : left->sz;
  }

  int getCnt() const {
    int cnt = sz;
    if ( left != nullptr )
      cnt -= left->sz;
    if ( right != nullptr )
      cnt -= right->sz;
    return cnt;
  }
};

std::vector<int> Solution::countSmaller(std::vector<int>& nums) {
  std::vector<int> cnts( nums.size(), 0 );

  TreeNode *root = nullptr;

  for ( int i = nums.size() - 1; i >= 0; i-- ) {
    // Search tree
    TreeNode **pn = &root;
    while ( pn != nullptr && *pn != nullptr ) {
      TreeNode *n = *pn;

      if ( n->val == nums[i] ) {
        cnts[i] += n->getLeftSz();
        pn = nullptr;
        n->sz++;
      }
      else if ( n->val <= nums[i] ) {
        cnts[i] += n->getLeftSz() + n->getCnt();
        pn = &(n->right);
        n->sz++;
      }
      else {
        pn = &(n->left);
        n->sz++;
      }
    }

    if ( pn != nullptr && *pn == nullptr ) {
      *pn = new TreeNode( nums[i] );
    }
  }

  return cnts;
}
