#include <queue>
#include "solution.h"

static void markSurroundedRegion( std::vector<std::vector<char>>& board, int i, int j ) {
  std::vector<std::pair<int, int>> region;

  std::queue<std::pair<int, int>> q;
  q.emplace(i, j);

  while ( q.empty() == false ) {
    auto coord = q.front();
    q.pop();

    if ( coord.first < 0 || coord.second < 0 || coord.first >= board.size() || coord.second >= board[coord.first].size() ) {
      continue;
    }

    if ( board[coord.first][coord.second] != 'O' )
      continue;

    q.emplace(coord.first-1, coord.second);
    q.emplace(coord.first, coord.second-1);
    q.emplace(coord.first+1, coord.second);
    q.emplace(coord.first, coord.second+1);

    board[coord.first][coord.second] = 'B';
  }
}

void Solution::solve(std::vector<std::vector<char>>& board) {
  for ( int i=0; i<board.size(); i++ ) {
    if ( i == 0 || i == board.size() - 1 ) {
      for ( int j=0; j<board[i].size(); j++ ) {
        markSurroundedRegion( board, i, j );
      }
    }
    else {
      if ( board[i].size() > 0 ) {
        markSurroundedRegion( board, i, 0 );
        if ( board[i].size() > 1 ) {
          markSurroundedRegion( board, i, board[i].size() - 1 );
        }
      }
    }
  }

  for ( int i = 0; i < board.size(); i++ ) {
    for ( int j = 0; j < board[i].size(); j++ ) {
      if ( board[i][j] == 'O' ) {
        board[i][j] = 'X';
      }
      else if ( board[i][j] == 'B' ) {
        board[i][j] = 'O';
      }
    }
  }
}
