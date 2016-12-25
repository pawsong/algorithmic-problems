#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char **argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(PartitionEqualSubsetSum, Example1) {
  Solution sol;

  int arr[] = { 1, 5, 11, 5 };

  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  EXPECT_EQ( true, sol.canPartition( vec ) );
}

TEST(PartitionEqualSubsetSum, Example2) {
  Solution sol;

  int arr[] = { 1, 2, 3, 5 };

  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  EXPECT_EQ( false, sol.canPartition( vec ) );
}

TEST(PartitionEqualSubsetSum, SameNumbersEven) {
  Solution sol;

  int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2 };

  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  EXPECT_EQ( true, sol.canPartition( vec ) );
}

TEST(PartitionEqualSubsetSum, SameNumbersOdd) {
  Solution sol;

  int arr[] = { 2, 2, 2, 2, 2, 2, 2 };

  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  EXPECT_EQ( false, sol.canPartition( vec ) );
}

TEST(PartitionEqualSubsetSum, 2x5Equals10) {
  Solution sol;

  int arr[] = { 2, 2, 2, 2, 2, 10 };

  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  EXPECT_EQ( true, sol.canPartition( vec ) );
}

TEST(PartitionEqualSubsetSum, 2x4Equals4x2) {
  Solution sol;

  int arr[] = { 2, 2, 2, 2, 4, 4 };

  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  EXPECT_EQ( true, sol.canPartition( vec ) );
}

TEST(PartitionEqualSubsetSum, LongSequence) {
  int arr[] = {18,40,62,33,83,64,10,92,67,31,42,51,10,97,41,7,82,71,80,81,41,38,88,25,38,89,24,89,90,12,97,21,22,85,11,59,83,6,51,47,32,82,83,100,29,78,36,32,1,31,36,19,35,3,36,21,24,93,42,33,10,26,2,39,36,62,85,24,41,5,66,53,7,1,59,53,40,59,41,95,7,67,20,29,80,59,49,49,51,90,13,52,6,90,5,6,31,81,95,26};

  std::vector<int> vec( arr, arr + sizeof(arr) / sizeof(arr[0]) );

  Solution sol;

  EXPECT_EQ(true, sol.canPartition(vec));
}
