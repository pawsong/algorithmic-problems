
#include <cassert>
#include <algorithm>

#include "topsort.h"

bool TopologicalSorting::dfs( int n /* nodes labeled from 0 to n-1 */,
                              const std::vector< std::vector<int> >& adjLists,
                              std::vector<int>& sorted /* output */ ) {

  assert( n == adjLists.size() );

  std::vector< bool > discovered ( n, false );
  std::vector< bool > processed ( n, false );

  std::vector< int > stack;
  stack.push_back(0);
  discovered[0] = true;

  int undiscovered = 1;

  while ( sorted.size() < n ) {
    int numProcessed = 0;

    const auto& neighbors = adjLists[stack.back()];
    for (const auto& neighbor : neighbors) {
      assert ( neighbor < n );

      if ( discovered[neighbor] == false ) {
        stack.push_back(neighbor);
        discovered[neighbor] = true;
        break;
      }
      else if ( processed[neighbor] == true ) {
        numProcessed++;
      }
      else {
        // There is a back edge forming a cycle.
        return false;
      }
    }

    // If there is no neighbor node to process, process the current node.
    if ( neighbors.size() == numProcessed || neighbors.size() == 0 ) {
      int last = stack.back();
      stack.pop_back();

      sorted.push_back(last);
      processed[last] = true;
    }

    // Search unexplored partitions.
    if ( stack.size() == 0 ) {

      while ( undiscovered < n && discovered[undiscovered] ) {
        undiscovered++;
      }

      if ( undiscovered < n && discovered[undiscovered] == false ) {
        stack.push_back(undiscovered);
        discovered[undiscovered] = true;
      }
    }
  }

  std::reverse( sorted.begin(), sorted.end() );

  return true;
}
