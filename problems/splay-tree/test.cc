
#include <vector>

#include "gmock/gmock.h"
#include "tree.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

template< typename T >
static void traverse( const TreeNode<T>* tree, std::vector<T>& array ) {
  assert( tree != NULL );
  if ( tree->left() != NULL ) {
    ::traverse(tree->left(), array);
  }
  array.push_back(tree->value());
  if ( tree->right() != NULL ) {
    ::traverse(tree->right(), array);
  }
}

TEST(SplayTreeTest, ZIG_L) {
  SplayTree<int> tree;
  tree.insert(4);
  tree.insert(3);
  tree.insert(2);
  tree.insert(1);

  EXPECT_EQ( tree.rootNode()->value(), 1 );

  std::vector<int> arr;
  ::traverse(tree.rootNode(), arr);
  EXPECT_THAT(arr, ElementsAre(1,2,3,4));
}

TEST(SplayTreeTest, ZIG_R) {
  SplayTree<int> tree;
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);

  EXPECT_EQ( tree.rootNode()->value(), 4 );

  std::vector<int> arr;
  ::traverse(tree.rootNode(), arr);
  EXPECT_THAT(arr, ElementsAre(1,2,3,4));
}

TEST(SplayTreeTest, ZIGZIG_LL) {
  SplayTree<int> tree;
  tree.insert(1);
  tree.insert(3);
  tree.insert(4);
  tree.insert(2);

  EXPECT_EQ( tree.rootNode()->value(), 2 );

  std::vector<int> arr;
  ::traverse(tree.rootNode(), arr);
  EXPECT_THAT(arr, ElementsAre(1,2,3,4));
}

TEST(SplayTreeTest, ZIGZIG_RR) {
  SplayTree<int> tree;
  tree.insert(3);
  tree.insert(2);
  tree.insert(1);
  tree.insert(4);

  EXPECT_EQ( tree.rootNode()->value(), 4 );

  std::vector<int> arr;
  ::traverse(tree.rootNode(), arr);
  EXPECT_THAT(arr, ElementsAre(1,2,3,4));
}

TEST(SplayTreeTest, ZIGZIG_RL) {
  SplayTree<int> tree;
  tree.insert(4);
  tree.insert(2);
  tree.insert(1);
  tree.insert(3);

  EXPECT_EQ( tree.rootNode()->value(), 3 );

  std::vector<int> arr;
  ::traverse(tree.rootNode(), arr);
  EXPECT_THAT(arr, ElementsAre(1,2,3,4));
}

TEST(SplayTreeTest, ZIGZAG_LR) {
  SplayTree<int> tree;
  tree.insert(1);
  tree.insert(3);
  tree.insert(4);
  tree.insert(2);

  EXPECT_EQ( tree.rootNode()->value(), 2 );

  std::vector<int> arr;
  ::traverse(tree.rootNode(), arr);
  EXPECT_THAT(arr, ElementsAre(1,2,3,4));
}

TEST(SplayTreeTest, LargeInput) {
  SplayTree<int> tree;

  int N = 100;

  int direction = 1;
  int val;
  for (int i=0; i<N/10; i++) {
    for (int j=0; j<N/10; j++) {
      if ( direction > 0 ) {
        val = i*10 + j;
      }
      else {
        val = i*10 + 9 - j;
      }
      tree.insert( val );
    }
    direction *= -1;
  }

  EXPECT_EQ( tree.rootNode()->value(), val );

  std::vector<int> arr;
  ::traverse(tree.rootNode(), arr);

  std::vector<int> expected;
  for (int i=0; i<N; i++) {
    expected.push_back(i);
  }
  EXPECT_THAT(arr, ElementsAreArray(expected));
}
