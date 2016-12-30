#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(SymmetricTree, OnlyRoot) {
  TreeNode *root = new TreeNode(1);

  Solution sol;
  EXPECT_EQ( true, sol.isSymmetric( root ) );
}

TEST(SymmetricTree, RootWithLeftOnly) {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  root->left = left;

  Solution sol;
  EXPECT_EQ( false, sol.isSymmetric( root ) );
}

TEST(SymmetricTree, RootWithLeftRight) {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(2);
  root->left = left;
  root->right = right;

  Solution sol;
  EXPECT_EQ( true, sol.isSymmetric( root ) );
}

TEST(SymmetricTree, RootWithLeftRightAssymetric) {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  root->left = left;
  root->right = right;

  Solution sol;
  EXPECT_EQ( false, sol.isSymmetric( root ) );
}
