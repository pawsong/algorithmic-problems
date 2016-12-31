#include "solution.h"

ListNode* Solution::partition(ListNode* head, int x) {
  ListNode *root = head;
  ListNode *prev = nullptr;
  ListNode *cur = head;

  ListNode *lt_last = nullptr;
  ListNode *ge_last = nullptr;

  while ( cur != nullptr ) {
    if ( cur->val >= x ) {
      if ( prev && prev->val < x ) {
        if ( ge_last != nullptr ) {
          ListNode *ge_first = lt_last ? lt_last->next : root;
          if ( lt_last ) {
            lt_last->next = ge_last->next;
          }
          else {
            root = ge_last->next;
          }

          prev->next = ge_first;
          ge_last->next = cur;
        }
        lt_last = prev;
      }
    }
    else {
      if ( prev && prev->val >= x ) {
        ge_last = prev;
      }

      if ( cur->next == nullptr && ge_last != nullptr ) {
          ListNode *ge_first = lt_last ? lt_last->next : root;
          if ( lt_last ) {
            lt_last->next = ge_last->next;
          }
          else {
            root = ge_last->next;
          }

          cur->next = ge_first;
          ge_last->next = nullptr;
          cur = ge_last;
      }
    }

    prev = cur;
    cur = cur->next;
  }

  return root;
}
