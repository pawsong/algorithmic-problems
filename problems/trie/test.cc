
#include <string>

#include "gmock/gmock.h"
#include "trie.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

std::vector<char> conv( std::string str ) {
  std::vector<char> ret( str.begin(), str.end() );
  return ret;
}

TEST(TrieTest, Input_TheyThe) {
  std::vector<char> alphabets;

  char c = 'A';
  while ( c <= 'Z' ) {
    alphabets.push_back( c );
    c++;
  }

  EXPECT_EQ(alphabets.size(), 26);

  Trie<char> trie ( alphabets );
  trie.insert( ::conv("THEY") );
  trie.insert( ::conv("THE") );

  std::vector< std::vector<char> > strings;
  trie.getStrings(strings);
  EXPECT_THAT(strings, ElementsAre(ElementsAre('T','H','E'),
                                   ElementsAre('T','H','E','Y')));
}

TEST(TrieTest, LargeInput) {
  std::vector<char> alphabets;

  char c = 'A';
  while ( c <= 'Z' ) {
    alphabets.push_back( c );
    c++;
  }

  EXPECT_EQ(alphabets.size(), 26);

  std::vector< std::vector<char> > input;
  input.push_back( ::conv("A") );
  input.push_back( ::conv("ASTONISING") );
  input.push_back( ::conv("TO") );
  input.push_back( ::conv("T") );
  input.push_back( ::conv("TOWARD") );
  input.push_back( ::conv("TEA") );
  input.push_back( ::conv("TED") );
  input.push_back( ::conv("TEN") );
  input.push_back( ::conv("TENURE") );
  input.push_back( ::conv("TENABLE") );
  input.push_back( ::conv("I") );
  input.push_back( ::conv("IN") );
  input.push_back( ::conv("INN") );
  input.push_back( ::conv("INSPECT") );
  input.push_back( ::conv("INSPIRATION") );

  Trie<char> trie ( alphabets );
  for ( auto& str : input ) {
    trie.insert( str );
  }

  std::vector< std::vector<char> > strings;
  trie.getStrings(strings);
  EXPECT_THAT(strings, UnorderedElementsAreArray(input));

  for ( auto& str : input ) {
    EXPECT_EQ(trie.contains(str), true);
  }

  // Negative tests.
  EXPECT_EQ(trie.contains( ::conv("ASTO") ), false);
  EXPECT_EQ(trie.contains( ::conv("INNN") ), false);
  EXPECT_EQ(trie.contains( ::conv("INSPIRE") ), false);
}
