
#include "gmock/gmock.h"
#include "tree.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

static std::vector<char> alphabets() {
  std::vector<char> ret;
  char c = 'A';
  while ( c <= 'Z' ) {
    ret.push_back(c);
    c++;
  }
  return ret;
}

TEST(SuffixTreeTest, Input_NULLSTR) {
  SuffixTree tree( ::alphabets(), "" );
}

TEST(SuffixTreeTest, Input_BANANA) {
  SuffixTree tree( ::alphabets(), "BANANA" );

  std::vector< std::vector<char> > strings;
  tree.getStrings(strings);

  EXPECT_THAT(strings, UnorderedElementsAre(ElementsAre('A'),
                                            ElementsAre('N','A'),
                                            ElementsAre('A','N','A'),
                                            ElementsAre('N','A','N','A'),
                                            ElementsAre('A','N','A','N','A'),
                                            ElementsAre('B','A','N','A','N','A')));
}
