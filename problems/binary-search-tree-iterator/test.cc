
#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(BinarySearchTreeIteratorTest, Height5) {
  TreeNode* root = new TreeNode(5);

  int numNodes = 1;
  TreeNode* node = root;
  while ( numNodes < 5 ) {
    node->left = new TreeNode(5 - numNodes);
    node = node->left;
    numNodes++;
  }

  BSTIterator i = BSTIterator(root);

  int num = 1;
  std::vector<int> result;
  while (i.hasNext()) {
    result.push_back(i.next());
  }

  EXPECT_THAT(result, ElementsAre(1,2,3,4,5));

  node = root;
  while ( node != NULL ) {
    delete node;
    node = node->left;
  }
}
