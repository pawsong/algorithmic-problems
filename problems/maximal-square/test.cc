
#include "gmock/gmock.h"
#include "solution.h"

int main(int argc, char** argv) {
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

template<int m, int n>
std::vector< std::vector<char> > createMatrix(char (&elems)[m][n]) {
  std::vector< std::vector<char> > matrix;

  for ( int i=0; i<m; i++ ) {
    std::vector<char> row;
    for ( int j=0; j<n; j++ ) {
      row.push_back(elems[i][j]);
    }
    matrix.push_back(row);
  }
  return matrix;
}

TEST(MaximalSquareTest, 0by0) {
  std::vector< std::vector<char> > matrix;
  Solution sol;
  int sqr = sol.maximalSquare( matrix );
  EXPECT_EQ(sqr, 0);
}

TEST(MaximalSquareTest, 1by1) {
  std::vector< std::vector<char> > matrix;
  char elems[1][1] = {
    {'1'},
  };
  matrix = createMatrix(elems);

  Solution sol;
  int sqr = sol.maximalSquare( matrix );
  EXPECT_EQ(sqr, 1*1);
}  

TEST(MaximalSquareTest, 1by5) {
  std::vector< std::vector<char> > matrix;
  char elems[1][5] = {
    {'1','0','1','0','0'},
  };
  matrix = createMatrix(elems);

  Solution sol;
  int sqr = sol.maximalSquare( matrix );
  EXPECT_EQ(sqr, 1*1);
}  

TEST(MaximalSquareTest, 5by1) {
  std::vector< std::vector<char> > matrix;
  char elems[5][1] = {
    {'1'},
    {'0'},
    {'1'},
    {'1'},
    {'1'}
  };
  matrix = createMatrix(elems);

  Solution sol;
  int sqr = sol.maximalSquare( matrix );
  EXPECT_EQ(sqr, 1*1);
}

TEST(MaximalSquareTest, 5by4) {
  std::vector< std::vector<char> > matrix;
  char elems[5][4] = {
    {'0','0','0','1'},
    {'1','1','0','1'},
    {'1','1','1','1'},
    {'0','1','1','1'},
    {'0','1','1','1'},
   };
  matrix = createMatrix(elems);

  Solution sol;
  int sqr = sol.maximalSquare( matrix );
  EXPECT_EQ(sqr, 3*3);
}  

TEST(MaximalSquareTest, 4by5) {
  std::vector< std::vector<char> > matrix;
  char elems[4][5] = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
  };
  matrix = createMatrix(elems);

  Solution sol;
  int sqr = sol.maximalSquare( matrix );
  EXPECT_EQ(sqr, 2*2);
}

TEST(MaximalSquareTest, 10by10) {
  std::vector< std::vector<char> > matrix;
  char elems[10][10] = {
    {'1','0','1','0','0','1','1','1','1','1'},
    {'1','0','1','1','1','1','1','1','1','1'},
    {'1','1','1','1','1','1','1','1','1','1'},
    {'1','0','0','1','0','1','1','1','1','1'},
    {'1','0','0','0','0','0','1','1','1','1'},
    {'1','0','1','0','0','0','1','1','1','1'},
    {'1','0','1','1','1','1','1','1','1','1'},
    {'1','1','1','1','1','1','1','1','1','1'},
    {'1','0','0','1','0','1','1','1','1','1'},
    {'1','0','0','0','0','1','1','1','1','1'},
  };
  matrix = createMatrix(elems);

  Solution sol;
  int sqr = sol.maximalSquare( matrix );
  EXPECT_EQ(sqr, 4*4);
}
