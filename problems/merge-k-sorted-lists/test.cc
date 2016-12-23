#include "gmock/gmock.h"
#include "solution.h"

using namespace testing;

int main( int argc, char** argv ) {
  InitGoogleMock( &argc, argv );
  return RUN_ALL_TESTS();
}

TEST(MergeKSortedLists, EmptyLists) {
  Solution sol;

  std::vector<ListNode*> lists;

  EXPECT_EQ(NULL, sol.mergeKLists(lists));
}

TEST(MergeKSortedLists, 1Lists) {
  Solution sol;

  std::vector<ListNode*> lists;

  int i = 1;
  ListNode *node = new ListNode(i++);
  lists.push_back(node);

  for(int j=i; j<10; j++ ) {
    node->next = new ListNode(j);
    node = node->next;
  }

  ListNode *sorted = sol.mergeKLists(lists);
  for ( int k=1; k<10; k++ ) {
    EXPECT_EQ(sorted->val, k);
    sorted = sorted->next;
  }
}

TEST(MergeKSortedLists, 2Lists) {
  Solution sol;

  std::vector<ListNode*> lists;

  int i = 1;
  ListNode *node = new ListNode(i++);
  lists.push_back(node);

  while ( i < 10 ) {
    node->next = new ListNode(i++);
    node = node->next;
  }

  node = new ListNode(i++);
  lists.push_back(node);

  while ( i < 20 ) {
    node->next = new ListNode(i++);
    node = node->next;
  }

  ListNode *sorted = sol.mergeKLists(lists);
  for ( int k=1; k<20; k++ ) {
    EXPECT_NE(NULL, sorted->val);
    EXPECT_EQ(sorted->val, k);
    sorted = sorted->next;
  }
}

TEST(MergeKSortedLists, 3Lists) {
  Solution sol;

  std::vector<ListNode*> lists;

  int i = 1;
  ListNode *nodeA = new ListNode(i++);
  lists.push_back(nodeA);

  ListNode *nodeB = new ListNode(i++);
  lists.push_back(nodeB);

  ListNode *nodeC = new ListNode(i++);
  lists.push_back(nodeC);

  while ( i < 30 ) {
    ListNode *newNode = new ListNode(i++);
    if ( i % 3 == 0 ) {
      nodeC->next = newNode;
      nodeC = nodeC->next;
    }
    else if ( i % 3 == 1 ) {
      nodeB->next = newNode;
      nodeB = nodeB->next;
    }
    else {
      nodeA->next = newNode;
      nodeA = nodeA->next;
    }
  }

  ListNode *sorted = sol.mergeKLists(lists);

  for ( int k=1; k<30; k++ ) {
    EXPECT_NE(NULL, sorted->val);
    EXPECT_EQ(sorted->val, k);
    sorted = sorted->next;
  }
}

TEST(MergeKSortedLists, NullList) {
  Solution sol;

  std::vector<ListNode*> lists;
  lists.push_back(NULL);
  lists.push_back(new ListNode(1));

  ListNode *sorted = sol.mergeKLists(lists);

  //EXPECT_NE(NULL, sorted);
  //EXPECT_EQ(NULL, sorted->next);
  //EXPECT_EQ(1, sorted->val);
}
