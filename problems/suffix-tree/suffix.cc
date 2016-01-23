
#include "tree.h"

void SuffixTree::internalInsert( const std::string& str ) {
  for ( auto it = str.begin(); it < str.end(); it++ ) {
    std::string substr (it, str.end());
    Trie<char>::insert( std::vector<char>(substr.begin(), substr.end()) );
  }
}
