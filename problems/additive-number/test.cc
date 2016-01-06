
#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main(int argc, char** argv) {
  InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(AdditiveNumberTest, 0) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("0"), false);
}

TEST(AdditiveNumberTest, 1) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("1"), false);
}

TEST(AdditiveNumberTest, 11) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("11"), false);
}

TEST(AdditiveNumberTest, 111) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("111"), false);
}

TEST(AdditiveNumberTest, 112) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("112"), true);
}

TEST(AdditiveNumberTest, 101) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("101"), true);
}

TEST(AdditiveNumberTest, 100001000) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("100001000"), true);
}

TEST(AdditiveNumberTest, 1122) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("1122"), false);
}

TEST(AdditiveNumberTest, 112358) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("112358"), true);
}

TEST(AdditiveNumberTest, 199100199) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("199100199"), true);
}

TEST(AdditiveNumberTest, 1189100189) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("1189100189"), true);
}

TEST(AdditiveNumberTest, 1991000199299498797) {
  Solution sol;
  EXPECT_EQ(sol.isAdditiveNumber("1991000199299498797"), false);
}
