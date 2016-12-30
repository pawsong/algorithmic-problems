#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(WordSearch, Example) {
  char arr[][4] = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };

  std::vector<std::vector<char>> vec;
  vec.emplace_back(arr[0], arr[0]+sizeof(arr[0])/sizeof(arr[0][0]));
  vec.emplace_back(arr[1], arr[1]+sizeof(arr[1])/sizeof(arr[1][0]));
  vec.emplace_back(arr[2], arr[2]+sizeof(arr[2])/sizeof(arr[2][0]));

  Solution sol;
  EXPECT_EQ(true, sol.exist(vec, "ABCCED"));
  EXPECT_EQ(true, sol.exist(vec, "SEE"));
  EXPECT_EQ(false, sol.exist(vec, "ABCB"));
}
