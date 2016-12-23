#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main ( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(Combinations, 4C1) {
  Solution sol;

  auto ret = sol.combine(4, 1);

  EXPECT_THAT(ret, UnorderedElementsAre(UnorderedElementsAre(1),
                                        UnorderedElementsAre(2),
                                        UnorderedElementsAre(3),
                                        UnorderedElementsAre(4)));
}

TEST(Combinations, 4C2) {
  Solution sol;

  auto ret = sol.combine(4, 2);

  EXPECT_THAT(ret, UnorderedElementsAre(UnorderedElementsAre(2,4),
                                        UnorderedElementsAre(3,4),
                                        UnorderedElementsAre(2,3),
                                        UnorderedElementsAre(1,2),
                                        UnorderedElementsAre(1,3),
                                        UnorderedElementsAre(1,4)));
}

TEST(Combinations, 4C3) {
  Solution sol;

  auto ret = sol.combine(4, 3);

  EXPECT_THAT(ret, UnorderedElementsAre(UnorderedElementsAre(1,2,4),
                                        UnorderedElementsAre(1,3,4),
                                        UnorderedElementsAre(1,2,3),
                                        UnorderedElementsAre(2,3,4)));
}

TEST(Combinations, 4C4) {
  Solution sol;

  auto ret = sol.combine(4, 4);

  EXPECT_THAT(ret, UnorderedElementsAre(UnorderedElementsAre(1,2,3,4)));
}
