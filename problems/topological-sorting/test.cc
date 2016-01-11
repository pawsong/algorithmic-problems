
#include "gmock/gmock.h"
#include "topsort.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(TopologicalSortingTest, DFS_CyclicGraph) {
  TopologicalSorting topsort;

  int n = 100;
  std::vector< std::vector<int> > adjLists ( n );
  for( int i=0; i<n; i++ ) {
    adjLists[i].push_back( ( i + 1 ) % n );
  }

  std::vector<int> result;
  bool ret = topsort.dfs( n, adjLists, result );

  EXPECT_EQ(ret, false);
  EXPECT_THAT(result, ElementsAre());
}

TEST(TopologicalSortingTest, DFS_AcyclicGraph) {
  TopologicalSorting topsort;

  int n = 7;
  std::vector< std::vector<int> > adjLists ( n );
  adjLists[0].push_back(1);
  adjLists[0].push_back(2);
  adjLists[1].push_back(2);
  adjLists[1].push_back(3);
  adjLists[2].push_back(4);
  adjLists[2].push_back(5);
  adjLists[4].push_back(3);
  adjLists[5].push_back(3);
  adjLists[5].push_back(4);
  adjLists[6].push_back(0);
  adjLists[6].push_back(5);

  std::vector<int> result;
  bool ret = topsort.dfs( n, adjLists, result );

  EXPECT_EQ(ret, true);
  EXPECT_THAT(result, ElementsAre(6, 0, 1, 2, 5, 4, 3));
}

void test( int n ) {
  TopologicalSorting topsort;

  std::vector< std::vector<int> > adjLists ( n );
  for( int i=0; i<n-1; i++ ) {
    adjLists[i].push_back( i + 1 );
  }

  std::vector<int> result;
  bool ret = topsort.dfs( n, adjLists, result );

  EXPECT_EQ(ret, true);

  std::vector<int> expected ( n );
  for( int i=0; i<n; i++ ) {
    expected[i] = i;
  }
  EXPECT_THAT(result, ElementsAreArray(expected));
}

TEST(TopologicalSortingTest, DFS_AcyclicGraph_N1000) {
  int n = 1000;
  ::test( n );
}

TEST(TopologicalSortingTest, DFS_AcyclicGraph_N10000) {
  int n = 10000;
  ::test( n );
}

TEST(TopologicalSortingTest, DFS_AcyclicGraph_N100000) {
  int n = 100000;
  ::test( n );
}

TEST(TopologicalSortingTest, DFS_AcyclicGraph_WorstCase) {
  TopologicalSorting topsort;

  int n = 1000;
  std::vector< std::vector<int> > adjLists ( n );
  for( int i=n; i>0; i-- ) {
    for ( int j=i-1; j>0; j-- ) {
      adjLists[i-1].push_back(j-1);
    }
  }

  std::vector<int> result;
  bool ret = topsort.dfs( n, adjLists, result );

  EXPECT_EQ(ret, true);

  std::vector<int> expected ( n );
  for( int i=0; i<n; i++ ) {
    expected[i] = n - i - 1;
  }
  EXPECT_THAT(result, ElementsAreArray(expected));
}
