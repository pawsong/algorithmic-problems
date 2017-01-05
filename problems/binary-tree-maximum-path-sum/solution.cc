#include <algorithm>
#include "solution.h"

int internalMaxPathSum(TreeNode *node, int &maxValue) {
  if ( node == nullptr ) {
    return 0;
  }

  int leftSum = 0, rightSum = 0;
  if ( node->left != nullptr )
    leftSum = internalMaxPathSum(node->left, maxValue);

  if ( node->right != nullptr )
    rightSum = internalMaxPathSum(node->right, maxValue);

  maxValue = std::max( maxValue, node->val );
  maxValue = std::max( maxValue, node->val + rightSum );
  maxValue = std::max( maxValue, node->val + leftSum );
  maxValue = std::max( maxValue, node->val + leftSum + rightSum );

  int ret = std::max(leftSum, rightSum);

  return ret > 0 ? ret + node->val : node->val;
}

int Solution::maxPathSum(TreeNode* root) {
  internalMaxPathSum( root, maxValue );
  return maxValue;
}
