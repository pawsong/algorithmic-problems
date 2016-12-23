#include <queue>
#include "solution.h"

class Compare {
public:
  bool operator() (ListNode *A, ListNode *B) {
    return A->val > B->val;
  }
};

ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {
  if ( lists.size() == 0 ) {
    return NULL;
  }

  std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;

  for ( auto root : lists ) {
    if ( root != NULL )
      pq.push(root);
  }

  if ( pq.size() == 0 ) {
    return NULL;
  }

  ListNode *list = pq.top();
  pq.pop();

  if ( list->next )
    pq.push(list->next);

  ListNode *cur = list;
  while ( pq.size() > 0 ) {
    auto top = pq.top();
    pq.pop();

    cur->next = top;
    cur = cur->next;

    if ( top->next != NULL ) {
      pq.push(top->next);
    }
  }

  return list;
}
