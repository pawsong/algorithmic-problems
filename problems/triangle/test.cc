
#include "gmock/gmock.h"
#include "solution.h"

int main(int argc, char** argv) {
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

template<int n>
void vectorize(const int (&arr)[n], std::vector< std::vector<int> >& vec) {
  int i=0;
  int size = 1;
  std::vector<int> row;
  while ( i<n ) {
    row.push_back(arr[i]);
    i++;
    if (row.size()==size) {
      vec.push_back(row);
      size++;
      row.clear();
    }
  }
}

TEST(TriangleTest, 1Row) {
  Solution sol;

  int arr[] = {
    -10
  };
  std::vector< std::vector<int> > vec;
  vectorize(arr, vec);

  EXPECT_EQ(sol.minimumTotal(vec), vec[0][0]);
}

TEST(TriangleTest, 2Rows) {
  Solution sol;

  int arr[] = {
    2,
    -5, 10
  };
  std::vector< std::vector<int> > vec;
  vectorize(arr, vec);

  EXPECT_EQ(sol.minimumTotal(vec), vec[0][0] + vec[1][0]);
}

TEST(TriangleTest, 3Rows) {
  Solution sol;

  int arr[] = {
    2,
    1, 50,
    10, 5, -50
  };
  std::vector< std::vector<int> > vec;
  vectorize(arr, vec);

  EXPECT_EQ(sol.minimumTotal(vec), vec[0][0] + vec[1][1] + vec[2][2]);
}

TEST(TriangleTest, 4Rows) {
  Solution sol;

  int arr[] = {
    2,
    3, 4,
    6, 5, 7,
    4, 1, 8, 3
  };
  std::vector< std::vector<int> > vec;
  vectorize(arr, vec);

  EXPECT_EQ(sol.minimumTotal(vec), vec[0][0] + vec[1][0] + vec[2][1] + vec[3][1]);
}
