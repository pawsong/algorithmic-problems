
#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

class BinarySearchTree {
  TreeNode* root;
  void internalInsert( TreeNode* n, int elem ) {
    assert(n != NULL);
    if (n->val < elem) {
      if (n->left) {
        internalInsert(n->left, elem);
      }
      else {
        n->left = new TreeNode(elem);
      }
    }
    else {
      if (n->right) {
        internalInsert(n->right, elem);
      }
      else {
        n->right = new TreeNode(elem);
      }
    }
  }
public:
  BinarySearchTree() : root(NULL) {}
  ~BinarySearchTree() {
    std::vector< TreeNode* > nodes;
    nodes.push_back(root);
    while (nodes.size() > 0) {
      auto* n = nodes.back();
      nodes.pop_back();
      if (n->left) {
        nodes.push_back(n->left);
      }
      if (n->right) {
        nodes.push_back(n->right);
      }
      delete n;
    }
  }
  TreeNode* rootNode() const {
    return root;
  }
  void insert ( int elem ) {
    if ( root == NULL ) {
      root = new TreeNode(elem);
    }
    else {
      internalInsert(root, elem);
    }
  }
};

TEST(BinaryTreePathsTest, SmallTree) {
  BinarySearchTree t;
  t.insert(2);
  t.insert(3);
  t.insert(1);
  t.insert(4);

  Solution sol;
  EXPECT_THAT( sol.binaryTreePaths( t.rootNode() ),
               UnorderedElementsAre( "2->3->4", "2->1" ));
}
