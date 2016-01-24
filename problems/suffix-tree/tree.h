
#include <string>
#include <vector>

#include "../trie/trie.h"

class SuffixTree : public Trie<char> {
 private:
  void internalInsert( const std::string& );

 public:
  SuffixTree( const std::vector<char>& alphabets, const std::string& str ) : Trie<char>(alphabets) {
    SuffixTree::internalInsert( str );
  }
  virtual ~SuffixTree() {}

  void insert( const std::string& );
  bool contains( const std::string& ) const;
};
