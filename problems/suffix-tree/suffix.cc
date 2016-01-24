
#include "tree.h"

void SuffixTree::internalInsert( const std::string& str ) {
  for ( auto it = str.begin(); it < str.end(); it++ ) {
    std::string suffix (it, str.end());
    Trie<char>::insert( std::vector<char>(suffix.begin(), suffix.end()) );
  }
}

void SuffixTree::insert( const std::string& str ) {
  SuffixTree::internalInsert( str );
}

bool SuffixTree::contains( const std::string& substr ) const {
  std::vector<char> vec( substr.begin(), substr.end() );
  return Trie<char>::contains(vec, false);
}
