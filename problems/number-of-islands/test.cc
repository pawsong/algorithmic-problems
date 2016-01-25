
#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

template<int m, int n>
static void vectorize(int (&in)[m][n], std::vector< std::vector<char> >& out) {
  for (int i=0; i<m; i++) {
    std::vector<char> row;
    for (int j=0; j<n; j++ ) {
      row.push_back( in[i][j] == 1 ? '1' : '0' );
    }
    out.push_back(row);
  }
}

TEST(NumberOfIslandsTest, 1by4) {
  int input[][4] = {
    1,
    1,
    0,
    1
  };

  std::vector< std::vector<char> > islands;
  ::vectorize(input, islands);

  Solution sol;
  EXPECT_EQ(sol.numIslands(islands), 2);
}

TEST(NumberOfIslandsTest, 4by1) {
  int input[][1] = {
    1, 1, 0, 1
  };

  std::vector< std::vector<char> > islands;
  ::vectorize(input, islands);

  Solution sol;
  EXPECT_EQ(sol.numIslands(islands), 2);
}

TEST(NumberOfIslandsTest, 4by4) {
  int input[][4] = {
    0, 1, 0, 1,
    1, 1, 1, 1,
    0, 1, 1, 1,
    1, 1, 0, 1
  };

  std::vector< std::vector<char> > islands;
  ::vectorize(input, islands);

  Solution sol;
  EXPECT_EQ(sol.numIslands(islands), 1);
}
