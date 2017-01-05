#include <climits>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  int maxValue;

public:
  Solution() : maxValue(INT_MIN) {}
  int maxPathSum(TreeNode* root);
};
