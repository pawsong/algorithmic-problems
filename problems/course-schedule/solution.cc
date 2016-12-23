#include "solution.h"

bool dfs( const std::vector< std::vector<bool> >& graph, int i, std::vector<bool>& discovered, std::vector<bool>& processed) {
  discovered[i] = true;

  for ( int j = 0; j < graph[i].size(); j++ ) {
    if ( graph[i][j] == true ) {
      if ( discovered[j] == false ) {
        if ( dfs( graph, j, discovered, processed ) == false ) {
          return false;
        }
      }
      else if ( processed[j] == false ) {
        return false; // BACK edge
      }
    }
  }

  processed[i] = true;
  return true;
}

bool topsort( std::vector< std::vector<bool> >& graph ) {
  std::vector<bool> discovered( graph.size(), false );
  std::vector<bool> processed( graph.size(), false );

  for ( int i=0; i<discovered.size(); i++ ) {
    if ( discovered[i] == false ) {
      if( dfs( graph, i, discovered, processed ) == false ) {
        return false;
      }
    }
  }

  return true;
}

bool Solution::canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
  std::vector<std::vector<bool>> graph( numCourses, std::vector<bool>( numCourses, false ) );

  for ( const auto &prereq : prerequisites ) {
    graph[prereq.second][prereq.first] = true;
  }

  return topsort( graph );
}
