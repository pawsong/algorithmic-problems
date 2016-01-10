
#include <cassert>

#include "solution.h"

std::vector<int> Solution::findMinHeightTrees(int n, std::vector< std::pair<int, int> >& edges) {

  // Special case.
  if ( n==1 && edges.size() == 0 ) {
    return std::vector<int>(1, 0);
  }

  std::vector< std::vector< int > > adjLists ( n );

  // Build adjacency lists of an undirected graph.
  for (const auto& it : edges) {
    adjLists[it.first].push_back( it.second );
    adjLists[it.second].push_back( it.first );
  }

  std::vector<int> leaves;
  for (int i=0; i<adjLists.size(); i++) {
    auto& list = adjLists[i];
    if ( list.size() == 1 ) {
      leaves.push_back(i);
    }
  }

  while ( n > 2 ) {
    n -= leaves.size();

    std::vector<int> newLeaves;

    // Remove all the leaves from the graph.
    for (const auto& leaf : leaves) {
      assert(adjLists[leaf].size() == 1);
      int parent = adjLists[leaf][0];

      auto& parentList = adjLists[parent];
      const auto& it = std::remove(parentList.begin(), parentList.end(), leaf);
      parentList.erase(it, parentList.end());

      if (parentList.size() == 1) {
        newLeaves.push_back(parent);
      }
    }

    leaves = newLeaves;
  }

  return leaves;
}
