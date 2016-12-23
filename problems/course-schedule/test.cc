#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(CourseSchedule, NoCycle1) {
  Solution sol;

  const int NUM_NODES = 1000;

  std::vector< std::pair<int, int> > vec;
  for ( int i = 0; i < NUM_NODES - 1; i++ ) {
    for ( int j = i+1; j < NUM_NODES - 1; j++ ) {
      vec.push_back( std::make_pair(i, j) );
    }
  }

  EXPECT_EQ(true, sol.canFinish(NUM_NODES, vec));
}

TEST(CourseSchedule, NoCycle2) {
  Solution sol;

  const int NUM_NODES = 1000;

  std::vector< std::pair<int, int> > vec;
  for ( int i = 0; i < NUM_NODES - 1; i++ ) {
    for ( int j = i+1; j < NUM_NODES - 1; j++ ) {
      vec.push_back( std::make_pair(j, i) );
    }
  }

  EXPECT_EQ(true, sol.canFinish(NUM_NODES, vec));
}

TEST(CourseSchedule, ShortCycle) {
  Solution sol;

  std::vector< std::pair<int, int> > vec;
  vec.push_back( std::make_pair(1, 0) );
  vec.push_back( std::make_pair(0, 1) );

  EXPECT_EQ(false, sol.canFinish(2, vec));
}

TEST(CourseSchedule, LongCycle) {
  Solution sol;

  const int NUM_NODES = 1000;

  std::vector< std::pair<int, int> > vec;
  for ( int i = 0; i < NUM_NODES - 1; i++ ) {
    vec.push_back( std::make_pair(i, i+1) );
  }

  // cycle
  vec.push_back( std::make_pair(NUM_NODES-1, 0) );

  EXPECT_EQ(false, sol.canFinish(NUM_NODES, vec));
}
