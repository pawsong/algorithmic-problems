
#include "mst.h"

void MinimumSpanningTrees::prim( const std::vector< std::vector< bool > >& adjMatrix,
                                 const std::vector< std::vector< float > >& weights,
                                 std::vector< std::vector<int> >& tree /* (output) MST */ ) {
  int N = adjMatrix.size();

  if ( N == 0 )
    return;

  tree.resize(0);
  tree.resize(N);

  std::vector<bool> intree ( N );
  std::vector<int> parent ( N, -1 );

#define INFINITY -1.f
  std::vector<float> distances ( N, INFINITY );

  int node = 0;
  distances[node] = 0.f;

  while ( node > -1 ) {
    if (parent[node] > -1) {
      tree[parent[node]].push_back(node);
      tree[node].push_back(parent[node]);
    }
    intree[node] = true;

    // After every insertion, update distances of its neighbors.
    for (int i=0; i<N; i++) {
      if (adjMatrix[node][i] == false || intree[i] == true)
        continue;

      float distance = weights[node][i];
      if ( distances[i] == INFINITY || distances[i] > distance ) {
        distances[i] = distance;
        parent[i] = node;
      }
    }

    // Find the smallest.
    node = -1;
    float smallest = -1.f;
    for (int i=0; i<N; i++) {
      if (intree[i] == true || distances[i] == INFINITY)
        continue;

      if (node == -1 || smallest > distances[i]) {
        node = i;
        smallest = distances[i];
      }
    }
  }
}
