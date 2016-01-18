
#include <cassert>
#include <climits>

#include "path.h"

void AllPairsShortestPaths::floyd(const std::vector< std::vector<int> >& weights, /* adjacency matrix */
                                  std::vector< std::vector<int> >& distances) {

  assert( weights.size() > 0 );
  assert( weights.size() == weights[0].size() );

  int N = weights.size();

  distances.resize(0);
  distances.resize( N, std::vector<int>( N, INT_MAX ) );

  // Maintain two distance buffers.
  std::vector< std::vector< std::vector<int> >* > buffers;
  std::vector< std::vector<int> > distances2 ( N, std::vector<int>( N, INT_MAX ) );

  if (N % 2 == 0 ) {
    buffers.push_back(&distances2);
    buffers.push_back(&distances);
  }
  else {
    buffers.push_back(&distances);
    buffers.push_back(&distances2);
  }

  // Base cases.
  auto& first = *buffers[0];
  for ( int i=0; i<N; i++ ) {
    for ( int j=0; j<N; j++ ) {
      first[i][j] = weights[i][j];
    }
  }

  // The rest of subproblems.
  for ( int k=1; k<N; k++ ) {
    auto& prev = *buffers[ (k-1) % 2 ];
    auto& cur = *buffers[ k % 2 ];
    for ( int i=0; i<N; i++ ) {
      for ( int j=0; j<N; j++ ) {
        if (prev[i][k] != INT_MAX && prev[k][j] != INT_MAX) {
          cur[i][j] = std::min(prev[i][k] + prev[k][j], prev[i][j]);
        }
        else {
          cur[i][j] = prev[i][j];
        }
      }
    }
  }
}
