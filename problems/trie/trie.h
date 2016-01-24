
#include <cassert>
#include <cstddef>
#include <vector>

class TrieNode {
 private:
  std::vector< TrieNode* > edges;
  bool eof;

 public:
  TrieNode(int n, bool e) : edges(n, NULL), eof(e) {}
  ~TrieNode() {
    for ( auto* edge : edges ) {
      if ( edge != NULL ) {
        delete edge;
      }
    }
  }
  inline void markEOF(bool e) {
    eof = e;
  }
  inline bool isEOF() const {
    return eof;
  }
  TrieNode* insert( int, bool );
  bool contains( const std::vector<int>&, int, bool ) const;

  inline std::vector< TrieNode* >::iterator begin() {
    return edges.begin();
  }
  inline std::vector< TrieNode* >::iterator end() {
    return edges.end();
  }
  inline std::vector< TrieNode* >::const_iterator begin() const {
    return edges.begin();
  }
  inline std::vector< TrieNode* >::const_iterator end() const {
    return edges.end();
  }
};

template<typename T>
class Trie {
 private:
  std::vector<T> alphabets;
  TrieNode* root;

  void internalGetStrings(const TrieNode*, std::vector<T>&, std::vector< std::vector<T> >&) const;

 public:
  Trie<T>(const std::vector<T>& a) : root(NULL), alphabets(a) {}
  ~Trie<T>() {
    if (root != NULL) {
      delete root;
    }
  }

  inline TrieNode* rootNode() const {
    return root;
  }

  void insert( const std::vector<T>& );
  bool contains( const std::vector<T>&, bool full = true ) const;

  inline void getStrings( std::vector< std::vector<T> >& strings ) const {
    if (root != NULL) {
      std::vector<T> substr;
      internalGetStrings( root, substr, strings );
    }
  }
};
