#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char **argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(Search2DMatrix, Example1) {
  int rows[][4] = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };

  std::vector< std::vector<int> > vec;
  vec.push_back( std::vector<int>(rows[0], rows[0] + sizeof(rows[0])/sizeof(rows[0][0])) );
  vec.push_back( std::vector<int>(rows[1], rows[1] + sizeof(rows[1])/sizeof(rows[1][0])) );
  vec.push_back( std::vector<int>(rows[2], rows[2] + sizeof(rows[2])/sizeof(rows[2][0])) );

  Solution sol;
  EXPECT_EQ(true, sol.searchMatrix( vec, 1 ) );
  EXPECT_EQ(false, sol.searchMatrix( vec, 2 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 3 ) );
  EXPECT_EQ(false, sol.searchMatrix( vec, 4 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 5 ) );
  EXPECT_EQ(false, sol.searchMatrix( vec, 6 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 7 ) );
  EXPECT_EQ(false, sol.searchMatrix( vec, 8 ) );
}


TEST(Search2DMatrix, Example2) {
  int rows[][2] = {
    {1,2},
    {3,4},
    {5,6},
    {7,8}
  };

  std::vector< std::vector<int> > vec;
  vec.push_back( std::vector<int>(rows[0], rows[0] + sizeof(rows[0])/sizeof(rows[0][0])) );
  vec.push_back( std::vector<int>(rows[1], rows[1] + sizeof(rows[1])/sizeof(rows[1][0])) );
  vec.push_back( std::vector<int>(rows[2], rows[2] + sizeof(rows[2])/sizeof(rows[2][0])) );
  vec.push_back( std::vector<int>(rows[3], rows[3] + sizeof(rows[3])/sizeof(rows[3][0])) );

  Solution sol;
  EXPECT_EQ(true, sol.searchMatrix( vec, 1 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 2 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 3 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 4 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 5 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 6 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 7 ) );
  EXPECT_EQ(true, sol.searchMatrix( vec, 8 ) );
}
