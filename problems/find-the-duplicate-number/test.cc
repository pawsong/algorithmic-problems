#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(FindDuplicateNumber, Example1) {
  int arr[] = {1,3,2,2};
  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  Solution sol;
  EXPECT_EQ( 2, sol.findDuplicate(vec) );
}

TEST(FindDuplicateNumber, Example2) {
  Solution sol;
  for ( int i = 1; i <= 100; i++ ) {
    std::vector<int> vec;
    for( int j = 1; j <= i; j++ ) {
      vec.push_back(j);
    }
    vec.push_back((i+1)/2);

    EXPECT_EQ( (i+1)/2, sol.findDuplicate(vec) );
  }
}

TEST(FindDuplicateNumber, Example3) {
  Solution sol;
  for ( int i = 1; i <= 100; i++ ) {
    std::vector<int> vec;
    for( int j = 1; j <= i; j++ ) {
      vec.push_back(j);
    }
    vec.push_back(1);

    EXPECT_EQ( 1, sol.findDuplicate(vec) );
  }
}

TEST(FindDuplicateNumber, Example4) {
  Solution sol;
  for ( int i = 1; i <= 100; i++ ) {
    std::vector<int> vec;
    for( int j = 1; j <= i; j++ ) {
      vec.push_back(j);
    }
    vec.push_back(i);

    EXPECT_EQ( i, sol.findDuplicate(vec) );
  }
}

TEST(FindDuplicateNumber, Example5) {
  Solution sol;
  int arr[] = {1,1,3,2};
  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  EXPECT_EQ(1, sol.findDuplicate( vec ));
}

TEST(FindDuplicateNumber, Example6) {
  Solution sol;
  int arr[] = {2,2,2,2,2};
  std::vector<int> vec( arr, arr + sizeof(arr)/sizeof(arr[0]) );

  EXPECT_EQ(2, sol.findDuplicate( vec ));
}
