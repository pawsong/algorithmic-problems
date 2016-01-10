
#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

template<int m>
void vectorizePairs( int (&arr)[m][2], std::vector< std::pair<int, int> >& vec ) {
  for (int i=0; i<m; i++) {
    vec.push_back( std::make_pair(arr[i][0], arr[i][1]) );
  }
}

TEST(MinimumHeightTreesTest, 1Leafs0Edges) {
  int n = 1;
  std::vector< std::pair<int, int> > edges;

  Solution sol;
  EXPECT_THAT(sol.findMinHeightTrees( n, edges ), UnorderedElementsAre(0));
}

TEST(MinimumHeightTreesTest, 2Leafs1Edges) {
  int n = 2;
  std::vector< std::pair<int, int> > edges;
  int arr[][2] = {
    {0, 1}
  };
  ::vectorizePairs(arr, edges);

  Solution sol;
  EXPECT_THAT(sol.findMinHeightTrees( n, edges ), UnorderedElementsAre(0, 1));
}

TEST(MinimumHeightTreesTest, 3Leafs3Edges) {
  int n = 4;
  std::vector< std::pair<int, int> > edges;
  int arr[][2] = {
    {1, 0},
    {1, 2},
    {1, 3}
  };
  ::vectorizePairs(arr, edges);

  Solution sol;
  EXPECT_THAT(sol.findMinHeightTrees( n, edges ), UnorderedElementsAre(1));
}

TEST(MinimumHeightTreesTest, 2Leafs3Edges) {
  int n = 4;
  std::vector< std::pair<int, int> > edges;
  int arr[][2] = {
    {0, 1},
    {1, 2},
    {2, 3}
  };
  ::vectorizePairs(arr, edges);

  Solution sol;
  EXPECT_THAT(sol.findMinHeightTrees( n, edges ), UnorderedElementsAre(1, 2));
}

TEST(MinimumHeightTreesTest, 2Leafs4Edges) {
  int n = 5;
  std::vector< std::pair<int, int> > edges;
  int arr[][2] = {
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 4}
  };
  ::vectorizePairs(arr, edges);

  Solution sol;
  EXPECT_THAT(sol.findMinHeightTrees( n, edges ), UnorderedElementsAre(2));
}

TEST(MinimumHeightTreesTest, 4Leafs5Edges) {
  int n = 6;
  std::vector< std::pair<int, int> > edges;
  int arr[][2] = {
    {0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}
  };
  ::vectorizePairs(arr, edges);

  Solution sol;
  EXPECT_THAT(sol.findMinHeightTrees( n, edges ), UnorderedElementsAre(3, 4));
}

TEST(MinimumHeightTreesTest, BinaryTree1) {
  int n = 5;
  std::vector< std::pair<int, int> > edges;
  int arr[][2] = {
    {0, 1}, {0, 4},
    {1, 2}, {1, 3},
  };
  ::vectorizePairs(arr, edges);

  Solution sol;
  EXPECT_THAT(sol.findMinHeightTrees( n, edges ), UnorderedElementsAre(0, 1));
}

TEST(MinimumHeightTreesTest, BinaryTree2) {
  int n = 6;
  std::vector< std::pair<int, int> > edges;
  int arr[][2] = {
    {0, 1}, {1, 2}, {2, 3},
    {1, 4},
    {0, 5}
  };
  ::vectorizePairs(arr, edges);

  Solution sol;
  EXPECT_THAT(sol.findMinHeightTrees( n, edges ), UnorderedElementsAre(1));
}

TEST(MinimumHeightTreesTest, BinaryTree3) {
  int n = 7;
  std::vector< std::pair<int, int> > edges;
  int arr[][2] = {
    {0, 1}, {0, 4},
    {1, 2}, {1, 3},
    {4, 5}, {4, 6}
  };
  ::vectorizePairs(arr, edges);

  Solution sol;
  EXPECT_THAT(sol.findMinHeightTrees( n, edges ), UnorderedElementsAre(0));
}
