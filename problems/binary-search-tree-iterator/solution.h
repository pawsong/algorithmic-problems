
#include <cstddef>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class StackElement {
private:
  TreeNode* node;
  bool processed;

public:
  StackElement(TreeNode* n) : node(n), processed(false) {
  }
  StackElement(const StackElement& s) : node(s.node), processed(s.processed) {
  }
  TreeNode* left() const {
    return node->left;
  }
  TreeNode* right() const {
    return node->right;
  }
  int value() const {
    return node->val;
  }
  bool isProcessed() const {
    return processed;
  }
  void setProcessed() {
    processed = true;
  }
};

class BSTIterator {
private:
  std::vector<StackElement> stack;

  void traverseLeft(TreeNode* node) {
    stack.push_back(StackElement(node));

    if (node->left) {
      traverseLeft(node->left);
    }
  }

public:
  BSTIterator(TreeNode *root) : stack() {
    if ( root != NULL ) {
      traverseLeft(root);
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return stack.size() > 0;
  }

  /** @return the next smallest number */
  int next();
};
