#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(ContainsDuplicate, 8ElemsDistinct) {
  std::vector<std::vector<char>> vec;
  int arr[][4] = {
    { 'X', 'X', 'X', 'X' },
    { 'X', 'O', 'O', 'X' },
    { 'X', 'X', 'O', 'X' },
    { 'X', 'O', 'X', 'X' }
  };

  for( int i=0; i<4; i++) {
    vec.emplace_back(arr[i], arr[i] + sizeof(arr[i])/sizeof(arr[i][0]));
  }

  Solution sol;
  sol.solve( vec );

  EXPECT_THAT(vec, ElementsAre( ElementsAre('X','X','X','X'),
                                ElementsAre('X','X','X','X'),
                                ElementsAre('X','X','X','X'),
                                ElementsAre('X','O','X','X') ));
}
