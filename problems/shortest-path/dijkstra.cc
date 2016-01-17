
#include "path.h"

void ShortestPath::dijkstra( int initialNode /* an initial node to start search from */,
                             const std::vector< std::vector< std::pair<int, float> > >& adjLists /* adjacency lists with weights */,
                             std::vector<int>& distances /* (output) shortest distances to every other node */ ) {

  int n = adjLists.size(); /* nodes are labeled from 0 to n-1 */

  std::vector<bool> visited ( n, false );

#define INFINITY -1
  distances.resize( 0 );
  distances.resize( n, INFINITY );

  distances[initialNode] = 0;
  int next = initialNode;

  while ( next > -1 ) {
    // Update distances of neighbors.
    for (const auto& neighbor : adjLists[next]) {
      int dist = distances[next] + neighbor.second;
      if ( distances[neighbor.first] == INFINITY || dist < distances[neighbor.first] ) {
        distances[neighbor.first] = dist;
      }
    }

    // Mark the node visited after updating distances to neighbors.
    visited[next] = true;

    // Find the next unvisited node having the lowest-distance.
    // (TODO: need to optimize the search using min-heap)
    next = -1;
    int smallest = INFINITY;

    for ( int i=0; i<n; i++ ) {
      if ( visited[i] || distances[i] == INFINITY ) {
        continue;
      }

      if ( smallest == INFINITY || smallest > distances[i] ) {
        next = i;
        smallest = distances[next];
      }
    }
  }
}
