
#include <climits>

#include "gmock/gmock.h"
#include "path.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

template<typename T>
void setEdge(std::vector< std::vector<T> >& g, int i, int j, T weight) {
  g[i][j] = weight;
}

void construct(int N, std::vector< std::vector<int> >& distances, std::vector< std::vector<int> >& g) {
  g.resize(N, std::vector<int>(N, INT_MAX));

  for ( int i=0; i<N-1; i++ ) {
    ::setEdge(g, i, i+1, 1);
  }
}

TEST(AllPairsShortestPathsTest, VariousCases) {
  int N = 10;
  std::vector< std::vector<int> > distances;
  std::vector< std::vector<int> > graph;

  ::construct(N, distances, graph);

  AllPairsShortestPaths path;
  path.floyd(graph, distances);

  EXPECT_THAT(distances[0][N-1], N-1);

  // Add a shortcut from 0 to (N-1)
  ::setEdge(graph, 0, N-1, N/2);
  path.floyd(graph, distances);
  EXPECT_THAT(distances[0][N-1], N/2);

  // Disconnect (N/2) - 1 and (N/2)
  ::setEdge(graph, (N/2)-1, N/2, INT_MAX);
  path.floyd(graph, distances);
  EXPECT_THAT(distances[N/2-1][N-1], INT_MAX);
}

TEST(AllPairsShortestPathsTest, N50) {
  int N = 50;
  std::vector< std::vector<int> > distances;
  std::vector< std::vector<int> > graph;

  ::construct(N, distances, graph);

  AllPairsShortestPaths path;
  path.floyd(graph, distances);

  EXPECT_THAT(distances[0][N-1], N-1);
}

TEST(AllPairsShortestPathsTest, N100) {
  int N = 100;
  std::vector< std::vector<int> > distances;
  std::vector< std::vector<int> > graph;

  ::construct(N, distances, graph);

  AllPairsShortestPaths path;
  path.floyd(graph, distances);

  EXPECT_THAT(distances[0][N-1], N-1);
}

TEST(AllPairsShortestPathsTest, N200) {
  int N = 200;
  std::vector< std::vector<int> > distances;
  std::vector< std::vector<int> > graph;

  ::construct(N, distances, graph);

  AllPairsShortestPaths path;
  path.floyd(graph, distances);

  EXPECT_THAT(distances[0][N-1], N-1);
}
