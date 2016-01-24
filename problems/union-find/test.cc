
#include "gmock/gmock.h"
#include "set.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(UnionFindTest, 2Elems) {
  Set set( 2 ); // Set of size 2 where elements are labeled 0 and 1, respectively.

  // Find subsets.
  EXPECT_EQ(set.contains(0), true);
  EXPECT_EQ(set.contains(1), true);
  EXPECT_EQ(set.find(0), 0);
  EXPECT_EQ(set.find(1), 1);
  EXPECT_EQ(set.connected(0, 1), false);

  // Union two subsets.
  set.merge(set.find(0), set.find(1));
  EXPECT_EQ(set.connected(0, 1), true);
}

TEST(UnionFindTest, 1000Elems) {
  int N = 1000;
  Set set( N );

  for (int i=1; i<100; i++) {
    EXPECT_EQ(set.connected(0, i), false);
  }

  for (int i=1; i<100; i++) {
    set.merge(i-1, i);
  }

  for (int i=1; i<100; i++) {
    EXPECT_EQ(set.connected(0, i), true);
    EXPECT_EQ(set.find(i), 0);
  }
}
