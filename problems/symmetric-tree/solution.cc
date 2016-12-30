#include <queue>
#include "solution.h"

bool Solution::isSymmetric(TreeNode* root) {

  std::queue<std::pair<TreeNode*, bool>> q;

  if ( root != nullptr ) {
    q.emplace(root->left, false);
    q.emplace(root->right, true);
  }

  std::vector<TreeNode *> leftHalf;

  bool rightSubtree = false;
  while ( q.empty() == false ) {
    const auto &cur = q.front();

    // Left subtree
    if ( cur.second == false ) {
      if ( rightSubtree ) {
        if ( leftHalf.size() > 0 ) {
          return false;
        }
      }
      leftHalf.push_back( cur.first );
    }
    // Right subtree
    else {
      if ( leftHalf.size() > 0 ) {
        if (leftHalf.back() == nullptr && cur.first != nullptr)
          return false;
        if (leftHalf.back() != nullptr && cur.first == nullptr)
          return false;
        if (leftHalf.back() != nullptr && cur.first != nullptr && leftHalf.back()->val != cur.first->val)
          return false;

        leftHalf.pop_back();
      }
      else {
        return false;
      }
    }

    rightSubtree = cur.second;

    if ( cur.first != nullptr ) {
      q.emplace(cur.first->left, cur.second);
      q.emplace(cur.first->right, cur.second);
    }
    q.pop();
  }

  return leftHalf.empty() ? true : false;;
}
