
#include <iterator>

#include "gmock/gmock.h"
#include "solution.h"

int main(int argc, char** argv) {
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(CreateMaximumNumberTest, LargeInput) {
  Solution sol;

  int n1[] = {6,4,7,8,6,5,5,3,1,7,4,9,9,5,9,6,1,7,1,3,6,3,0,8,2,1,8,0,0,7,3,9,3,1,3,7,5,9,4,3,5,8,1,9,5,6,5,7,8,6,6,2,0,9,7,1,2,1,7,0,6,8,5,8,1,6,1,5,8,4};
  std::vector<int> nums1( std::begin(n1), std::end(n1) );

  int n2[] = {3,0,0,1,4,3,4,0,8,5,9,1,5,9,4,4,4,8,0,5,5,8,4,9,8,3,1,3,4,8,9,4,9,9,6,6,2,8,9,0,8,0,0,0,1,4,8,9,7,6,2,1,8,7,0,6,4,1,8,1,3,2,4,5,7,7,0,4,8,4};
  std::vector<int> nums2( std::begin(n2), std::end(n2) );

  int k = 70;
  int expected[] = {9,9,9,9,9,9,9,9,9,9,9,9,9,5,6,5,7,8,6,6,2,0,9,7,1,2,1,7,0,8,0,6,8,5,8,1,6,1,5,8,4,0,0,0,1,4,8,9,7,6,2,1,8,7,0,6,4,1,8,1,3,2,4,5,7,7,0,4,8,4};

  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAreArray(expected));
}

TEST(CreateMaximumNumberTest, InvalidInput) {
  Solution sol;
  int n[] = {1};
  std::vector<int> nums1 (std::begin(n), std::end(n));
  std::vector<int> nums2 (std::begin(n), std::end(n));

  int k = nums1.size() + nums2.size() + 1;
  std::vector<int> maximumNumber = sol.maxNumber(nums1, nums2, k);
  EXPECT_EQ(maximumNumber.size(), 0);
}

TEST(CreateMaximumNumberTest, Case1) {
  Solution sol;

  int n1[] = {3, 4, 6, 5};
  std::vector<int> nums1 (std::begin(n1), std::end(n1));
  int n2[] = {9, 1, 2, 5, 8, 3};
  std::vector<int> nums2 (std::begin(n2), std::end(n2));

  int k = 10;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(9, 3, 4, 6, 5, 1, 2, 5, 8, 3));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(9, 3, 4, 6, 5, 1, 2, 5, 8, 3));

  k--;
  k--;
  k--;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(9, 8, 3, 4, 6, 5, 3));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(9, 8, 3, 4, 6, 5, 3));

  k--;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(9, 8, 4, 6, 5, 3));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(9, 8, 4, 6, 5, 3));

  k--;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(9, 8, 6, 5, 3));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(9, 8, 6, 5, 3));

  k--;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(9, 8, 6, 5));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(9, 8, 6, 5));

  k--;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(9, 8, 6));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(9, 8, 6));
}

TEST(CreateMaximumNumberTest, Case2) {
  Solution sol;

  int n1[] = {6, 0, 4};
  std::vector<int> nums1 (std::begin(n1), std::end(n1));
  int n2[] = {6, 7};
  std::vector<int> nums2 (std::begin(n2), std::end(n2));

  int k = 5;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(6, 7, 6, 0, 4));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(6, 7, 6, 0, 4));
}

TEST(CreateMaximumNumberTest, Case3) {
  Solution sol;

  int n1[] = {6, 0, 4};
  std::vector<int> nums1 (std::begin(n1), std::end(n1));
  int n2[] = {6, 7};
  std::vector<int> nums2 (std::begin(n2), std::end(n2));

  int k = 4;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(7, 6, 0, 4));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(7, 6, 0, 4));
}

TEST(CreateMaximumNumberTest, Case4) {
  Solution sol;

  int n1[] = {3, 9};
  std::vector<int> nums1 (std::begin(n1), std::end(n1));
  int n2[] = {8, 9};
  std::vector<int> nums2 (std::begin(n2), std::end(n2));

  int k = 3;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(9, 8, 9));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(9, 8, 9));
}

TEST(CreateMaximumNumberTest, Case5) {
  Solution sol;

  int n1[] = {5, 4, 3, 2, 1};
  std::vector<int> nums1 (std::begin(n1), std::end(n1));
  int n2[] = {4, 3, 2};
  std::vector<int> nums2 (std::begin(n2), std::end(n2));

  int k = nums1.size() + nums2.size();
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(5, 4, 4, 3, 3, 2, 2, 1));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(5, 4, 4, 3, 3, 2, 2, 1));

  k = 6;
  EXPECT_THAT(sol.maxNumber(nums1, nums2, k), testing::ElementsAre(5, 4, 4, 3, 3, 2));
  EXPECT_THAT(sol.maxNumber(nums2, nums1, k), testing::ElementsAre(5, 4, 4, 3, 3, 2));
}

