
#include "gmock/gmock.h"
#include "path.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

enum {
  DIJKSTRA = 0,
  TOPSORT,
};

void test( int N, char algorithm ) {
  std::vector< std::vector <std::pair<int, float> > > graph ( N );
  for (int i=0; i<graph.size() - 1; i++) {
    graph[i].push_back(std::make_pair(i+1, 1.f));
  }

  std::vector<float> expected ( N );
  for (int i=0; i<graph.size(); i++) {
    expected[i] = i * 1.f;
  }

  ShortestPath shortestPath;

  std::vector<int> distances;

  switch (algorithm) {
  case DIJKSTRA:
    shortestPath.dijkstra(0, graph, distances);
    break;
  case TOPSORT:
    shortestPath.topsort(0, graph, distances);
  }

  EXPECT_THAT(distances, ElementsAreArray(expected));
}

TEST(ShortestPathTest, N1000_Dijkstra) {
  test(1000, DIJKSTRA);
}

TEST(ShortestPathTest, N1000_Topsort) {
  test(1000, TOPSORT);
}

TEST(ShortestPathTest, N10000_Dijkstra) {
  test(10000, DIJKSTRA);
}

TEST(ShortestPathTest, N10000_Topsort) {
  test(10000, TOPSORT);
}

TEST(ShortestPathTest, N100000_Topsort) {
  test(100000, TOPSORT);
}

TEST(ShortestPathTest, DAG_All) {
  int n = 100;

  std::vector< std::vector <std::pair<int, float> > > graph ( n );
  for (int i=0; i<graph.size() - 1; i++) {
    graph[i].push_back(std::make_pair(i+1, 1.f));
  }

  std::vector<float> expected ( n );
  for (int i=0; i<graph.size(); i++) {
    expected[i] = i * 1.f;
  }

  ShortestPath shortestPath;

  std::vector<int> distances;
  shortestPath.dijkstra(0, graph, distances);
  EXPECT_THAT(distances, ElementsAreArray(expected));

  shortestPath.topsort(0, graph, distances);
  EXPECT_THAT(distances, ElementsAreArray(expected));

  // Add a shortcut between the first and the last node.
  graph[0].push_back(std::make_pair(n-1, 1.f));
  expected[n-1] = 1.f;

  shortestPath.dijkstra(0, graph, distances);
  EXPECT_THAT(distances, ElementsAreArray(expected));

  shortestPath.topsort(0, graph, distances);
  EXPECT_THAT(distances, ElementsAreArray(expected));
}

TEST(ShortestPathTest, DAG_Topsort) {
  std::vector< std::vector <std::pair<int, float> > > graph ( 3 );

  graph[2].push_back(std::make_pair(0, 100.f));
  graph[2].push_back(std::make_pair(1, 10.f));
  graph[1].push_back(std::make_pair(0, 10.f));

  ShortestPath shortestPath;

  std::vector<int> distances;

  shortestPath.topsort(2, graph, distances);
  EXPECT_THAT(distances, ElementsAre(20.f, 10.f, 0.f));

  shortestPath.topsort(1, graph, distances);
  EXPECT_THAT(distances, ElementsAre(10.f, 0.f, -1.f));

  shortestPath.topsort(0, graph, distances);
  EXPECT_THAT(distances, ElementsAre(0.f, -1.f, -1.f));
}

TEST(ShortestPathTest, DCG_Dijkstra_1) {
  std::vector< std::vector <std::pair<int, float> > > graph ( 3 );

  graph[0].push_back(std::make_pair(1, 1.f));
  graph[0].push_back(std::make_pair(2, 10.f));
  graph[1].push_back(std::make_pair(0, 10.f));
  graph[1].push_back(std::make_pair(2, 100.f));
  graph[2].push_back(std::make_pair(0, 100.f));
  graph[2].push_back(std::make_pair(1, 1.f));

  ShortestPath shortestPath;

  std::vector<int> distances;

  shortestPath.dijkstra(0, graph, distances);
  EXPECT_THAT(distances, ElementsAre(0.f, 1.f, 10.f));

  shortestPath.dijkstra(1, graph, distances);
  EXPECT_THAT(distances, ElementsAre(10.f, 0.f, 20.f /* 1->0->2 */));

  shortestPath.dijkstra(2, graph, distances);
  EXPECT_THAT(distances, ElementsAre(11.f /* 2->1->0 */, 1.f, 0.f));
}

TEST(ShortestPathTest, DCG_Dijkstra_2) {

  std::vector< std::vector <std::pair<int, float> > > graph ( 6 );

  graph[0].push_back(std::make_pair(1, 7.f));
  graph[0].push_back(std::make_pair(2, 9.f));
  graph[0].push_back(std::make_pair(5, 14.f));
  graph[1].push_back(std::make_pair(2, 10.f));
  graph[1].push_back(std::make_pair(3, 15.f));
  graph[2].push_back(std::make_pair(3, 11.f));
  graph[2].push_back(std::make_pair(5, 2.f));
  graph[3].push_back(std::make_pair(4, 6.f));
  graph[4].push_back(std::make_pair(3, 6.f));
  graph[5].push_back(std::make_pair(4, 9.f));

  ShortestPath shortestPath;

  std::vector<int> distances;
  shortestPath.dijkstra( 0, graph, distances );

  EXPECT_THAT(distances, ElementsAre(0.f, 7.f, 9.f, 20.f, 20.f, 11.f));
}
