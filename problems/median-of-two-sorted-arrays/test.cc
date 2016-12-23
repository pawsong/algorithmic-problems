#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(MedianOfTwoSortedArrays, Example1) {
  int nums1[] = {1, 3};
  int nums2[] = {2};

  Solution sol;
  std::vector<int> vec1(nums1, nums1 + 2);
  std::vector<int> vec2(nums2, nums2 + 1);

  EXPECT_EQ(2.0, sol.findMedianSortedArrays(vec1, vec2));
}

TEST(MedianOfTwoSortedArrays, Example2) {
  int nums1[] = {1, 2};
  int nums2[] = {3, 4};

  Solution sol;
  std::vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(nums1[0]));
  std::vector<int> vec2(nums2, nums2 + sizeof(nums2) / sizeof(nums2[0]));

  EXPECT_EQ(2.5, sol.findMedianSortedArrays(vec1, vec2));
}

TEST(MedianOfTwoSortedArrays, Asymetric) {
  int nums1[] = {1, 2, 5, 6, 7, 8, 9, 10, 11, 12};
  int nums2[] = {3, 4};

  Solution sol;
  std::vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(nums1[0]));
  std::vector<int> vec2(nums2, nums2 + sizeof(nums2) / sizeof(nums2[0]));

  EXPECT_EQ(6.5, sol.findMedianSortedArrays(vec1, vec2));
}
