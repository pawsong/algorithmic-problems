#include "solution.h"

static bool backtrack(std::vector<std::vector<char>> &board, int i, int j, std::string &word, int k, std::vector<std::vector<bool>> &discovered) {
  if ( i < 0 || i >= board.size() )
    return false;

  if ( j < 0 || j >= board[i].size() )
    return false;

  if ( k >= word.size() )
    return false;

  if ( word[k] != board[i][j] )
    return false;

  if ( discovered[i][j] )
    return false;

  if ( k == word.size() - 1 )
    return true;

  discovered[i][j] = true;

  bool ret = backtrack(board, i-1, j, word, k+1, discovered)
    || backtrack(board, i, j-1, word, k+1, discovered)
    || backtrack(board, i+1, j, word, k+1, discovered)
    || backtrack(board, i, j+1, word, k+1, discovered);

  if ( ret == false )
    discovered[i][j] = false;

  return ret;
}

bool Solution::exist(std::vector<std::vector<char>>& board, std::string word) {
  if ( word.size() == 0 ) {
    return false;
  }

  std::vector<std::vector<bool>> discovered( board.size(), std::vector<bool>(board[0].size(), false) );

  for ( int i = 0; i < board.size(); i++ ) {
    for ( int j = 0; j < board[i].size(); j++ ) {
      if ( backtrack(board, i, j, word, 0, discovered) ) {
        return true;
      }
    }
  }

  return false;
}
