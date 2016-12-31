#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(PartitionList, Example) {
  int arr[] = { 3, 1, 4, 3, 2, 5, 2, 1, 0, -1, 8, 3, 9, -2, 10 };

  ListNode *root = nullptr;
  ListNode *prev = nullptr;

  for ( int i=0; i<sizeof(arr)/sizeof(arr[0]); i++ ) {
    ListNode *nn = new ListNode(arr[i]);
    if ( prev == nullptr ) {
      root = nn;
    }
    else {
      prev->next = nn;
    }

    prev = nn;
  }

  Solution sol;
  ListNode *nn = sol.partition(root, 3);

  int expected[] = { 1, 2, 2, 1, 0, -1, -2, 3, 4, 3, 5, 8, 3, 9, 10 };

  int i = 0;
  while ( nn != nullptr ) {
    EXPECT_EQ(expected[i], nn->val);
    nn = nn->next;
    i++;
  }

  EXPECT_EQ(i, sizeof(expected)/sizeof(expected[0]));
}
