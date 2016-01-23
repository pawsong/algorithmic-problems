
#include <algorithm>

#include "trie.h"

TrieNode* allocTrieNode( int n, bool eof ) {
  return new TrieNode(n, eof);
}

// TrieNode
TrieNode* TrieNode::insert( int i, bool eof ) {
  TrieNode* ret = NULL;

  if ( i > -1 && i < edges.size() ) {
    if (edges[i] == NULL) {
      edges[i] = ::allocTrieNode(edges.size(), eof);
    }
    assert( edges[i] != NULL );

    if (edges[i]->isEOF() == false) {
      edges[i]->markEOF(eof);
    }
    ret = edges[i];
  }
  return ret;
}

// Trie
template<typename T>
void Trie<T>::insert( const std::vector<T>& string ) {

  if ( root == NULL ) {
    root = ::allocTrieNode( alphabets.size(), false );
  }

  assert( root != NULL );

  auto* node = root;
  for ( int i=0; i<string.size(); i++ ) {
    assert( node != NULL );

    auto it = std::find(alphabets.begin(), alphabets.end(), string[i]);
    if ( it != alphabets.end() ) {
      bool eof = (i == string.size() - 1) ? true : false;
      node = node->insert( it - alphabets.begin(), eof );
    }
  }
}

template<typename T>
void Trie<T>::internalGetStrings( const TrieNode* node, std::vector<T>& substr, std::vector< std::vector<T> >& strings ) const {
  assert( node != NULL );

  if (node->isEOF() == true) {
    strings.push_back(substr);
  }

  for( auto it = node->begin(); it != node->end(); it++ ) {
    if ( *it != NULL ) {
      std::vector<T> newstr (substr);
      newstr.push_back( alphabets[it - node->begin()] );
      Trie<T>::internalGetStrings( *it, newstr, strings );
    }
  }
}

template class Trie<char>;
