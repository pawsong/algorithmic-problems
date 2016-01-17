
#include <iostream>

#include "../topological-sorting/topsort.h"
#include "path.h"

bool ShortestPath::topsort( int initialNode,
                            const std::vector< std::vector< std::pair<int, float> > >& adjListsWithWeight,
                            std::vector<int>& distances ) {

  int n = adjListsWithWeight.size(); /* nodes are labeled from 0 to n-1 */

  TopologicalSorting topsort;

  // Convert the graph to an unweighted graph.
  std::vector< std::vector<int> > adjLists;
  for ( const auto& lists : adjListsWithWeight ) {
    adjLists.push_back( std::vector<int>() );
    for ( const auto& edges : lists ) {
      adjLists.back().push_back(edges.first);
    }
  }

  // Perform topological sorting.
  std::vector<int> sorted;
  bool ret = topsort.dfs(adjLists.size(), adjLists, sorted);

  // Check for cycles.
  if (ret == false) {
    return false;
  }

  // Process vertexes from left to right.
  distances.resize(0);

#define INFINITY -1
  distances.resize( n, INFINITY );

  bool foundInitialNode = false;

  std::vector< std::vector< std::pair<int, float> > > incomingEdges ( n );

  for ( const auto& cur : sorted ) {
    if (cur == initialNode) {
      foundInitialNode = true;
      distances[cur] = 0;
    }
    else if ( foundInitialNode ) {
      int prev = -1;
      float smallest = -1.f;
      for ( const auto& iter : incomingEdges[cur] ) {
        if (prev == -1 || smallest > distances[iter.first] + iter.second) {
          prev = iter.first;
          smallest = distances[prev] + iter.second;
        }
      }
      distances[cur] = smallest;
    }

    for ( const auto& edge : adjListsWithWeight[cur] ) {
      incomingEdges[edge.first].push_back(std::make_pair(cur, edge.second));
    }
  }

  return true;
}
