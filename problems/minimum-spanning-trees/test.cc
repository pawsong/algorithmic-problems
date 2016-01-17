
#include <math.h>

#include "gmock/gmock.h"
#include "mst.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

class UndirectedWeightedGraph {
public:
  std::vector< std::vector<bool> > adjMatrix;
  std::vector< std::vector<float> > weights;

  UndirectedWeightedGraph(int N) : adjMatrix(N, std::vector<bool>(N, false)), weights(N, std::vector<float>(N, 0.f)) {}

  void addEdge(int i, int j, float weight) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
    weights[i][j] = weight;
    weights[j][i] = weight;
  }
};

TEST(MinimumSpanningTreesTest, Prim_4Vertices) {

  MinimumSpanningTrees mst;

  int N = 4;
  UndirectedWeightedGraph g ( N );
  g.addEdge(0, 1, 5.f);
  g.addEdge(0, 2, 7.f);
  g.addEdge(0, 3, 12.f);
  g.addEdge(1, 2, 7.f);
  g.addEdge(2, 3, 4.f);

  std::vector< std::vector<int> > tree;
  mst.prim(g.adjMatrix, g.weights, tree);

  EXPECT_THAT(tree, ElementsAre(UnorderedElementsAre(1, 2),
                                UnorderedElementsAre(0),
                                UnorderedElementsAre(3, 0),
                                UnorderedElementsAre(2)));
}

TEST(MinimumSpanningTreesTest, Prim_10Vertices) {
  int N = 10;
  UndirectedWeightedGraph g ( N );

  // Put the first (N - 1) vertices on the line: y = 1
  for ( int i=0; i<N-2; i++ ) {
    g.addEdge(i, i+1, 1.f);
  }

  // Put the last vertex at ((N-1)/2, 5)
  int x = (N-1) / 2;
  int y = 5;

  // Link every vertex to the last vertex with the weight as the geometric distance between them.
  for ( int i=0; i<N-1; i++ ) {
    float dist = sqrt( (x - i) * (x - i) + (y - 1) * (y - 1) );
    g.addEdge(i, N-1, dist);
  }

  MinimumSpanningTrees mst;

  std::vector< std::vector<int> > tree;
  mst.prim(g.adjMatrix, g.weights, tree);

  EXPECT_THAT(tree, ElementsAre(UnorderedElementsAre(1),
                                UnorderedElementsAre(0, 2),
                                UnorderedElementsAre(1, 3),
                                UnorderedElementsAre(2, 4),
                                UnorderedElementsAre(3, 5, 9),
                                UnorderedElementsAre(4, 6),
                                UnorderedElementsAre(5, 7),
                                UnorderedElementsAre(6, 8),
                                UnorderedElementsAre(7),
                                UnorderedElementsAre(4)));
}
