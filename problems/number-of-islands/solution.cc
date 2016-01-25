
#include <cassert>

#include "solution.h"

static std::pair<int, int> find( std::vector< std::vector< std::pair<int, int> > >& parent, int i, int j ) {
  assert( i>-1 && j>-1 );

  auto elem = std::make_pair(i, j);

  while ( parent[ elem.first ][ elem.second ] != std::make_pair(-1, -1) ) {
    elem = parent[elem.first][elem.second];
  }

  return elem;
}

int Solution::numIslands( std::vector< std::vector<char> >& grid ) {

  int num = 0;

  std::vector< std::vector< std::pair<int, int> > > parent (grid.size());
  std::vector< std::vector< int > > size (grid.size());

  // First row.
  if ( grid.size() > 0 ) {
    parent[0].resize( grid[0].size(), std::make_pair(-1, -1) );
    size[0].resize( grid[0].size(), 1 );

    if ( grid[0].size() > 0 && grid[0][0] == '1' ) {
      num++;
    }

    for ( int j=1; j<grid[0].size(); j++ ) {
      if ( grid[0][j] == '0' ) {
        continue;
      }

      if ( grid[0][j-1] == '1' ) {
        auto subset = ::find( parent, 0 , j-1 );
        parent[0][j] = subset;
        ++size[ subset.first ][ subset.second ];
      }
      else {
        num++;
      }
    }
  }

  // First column.
  for ( int i=1; i<grid.size(); i++ ) {
    parent[i].resize( grid[i].size(), std::make_pair(-1, -1) );
    size[i].resize( grid[i].size(), 1);

    if ( grid[i].size() == 0 ) {
      break;
    }
    if ( grid[i][0] == '0' ) {
      continue;
    }

    if ( grid[i-1][0] == '1' ) {
      auto subset = ::find( parent, i-1, 0 );
      parent[i][0] = subset;
      ++size[ subset.first ][ subset.second ];
    }
    else {
      num++;
    }
  }

  // Inspect the rest of cells.
  for ( int i=1; i<grid.size(); i++ ) {
    for ( int j=1; j<grid[i].size(); j++ ) {
      if ( grid[i][j] == '0' ) {
        continue;
      }

      auto subsetA = ::find( parent, i-1, j );
      auto subsetB = ::find( parent, i, j-1 );
      auto& sizeA = size[subsetA.first][subsetA.second];
      auto& sizeB = size[subsetB.first][subsetB.second];

      if (grid[i-1][j] == '1' && grid[i][j-1] == '1' && subsetA != subsetB ) {
        // Union islands.
        if ( sizeA > sizeB ) {
          parent[i][j] = subsetA;
          parent[ subsetB.first ][ subsetB.second ] = subsetA;
          sizeA += sizeB;
        }
        else {
          parent[i][j] = subsetB;
          parent[ subsetA.first ][ subsetA.second ] = subsetB;
          sizeB += sizeA;
        }
        num--;
      }
      else if (grid[i-1][j] == '1') {
        parent[i][j] = subsetA;
        sizeA++;
      }
      else if (grid[i][j-1] == '1') {
        parent[i][j] = subsetB;
        sizeB++;
      }
      else {
        num++;
      }
    }
  }

  return num;
}
