#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(ValidPerfectSquare, 100000000) {
  Solution sol;
  EXPECT_EQ(true, sol.isPerfectSquare(100000000));
}

TEST(ValidPerfectSquare, UpTo1000000) {
  Solution sol;

  for ( int i = 1; i <= 1000; i++ ) {
    EXPECT_EQ(true, sol.isPerfectSquare(i * i));

    if ( i > 2 ) {
      for ( int j = (i-1)*(i-1) + 1; j < i*i; j++ )
        EXPECT_EQ(false, sol.isPerfectSquare(j));
    }
  }
}
