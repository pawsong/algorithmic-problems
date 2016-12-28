#include <cmath>
#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(PowX_N, Base2) {
  Solution sol;

  for ( int i = -10; i <= 10; i++ ) {
    EXPECT_EQ(std::pow(2, i), sol.myPow(2, i));
  }
}
