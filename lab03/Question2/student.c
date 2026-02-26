// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      
      // Create extra node to hold head's place
      struct ListNode extra;
      extra.val = 0;
      extra.next = head;

      struct ListNode* prev = &extra;

      // Check if there are 2 more nodes after prev to be swapped
      while(prev->next != NULL && prev->next->next != NULL)
      {
            struct ListNode* first = prev->next;
            struct ListNode* second = first->next;
            // Do the swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Set previous onto the next pair
            prev = first;
      }
      
      // Return the new head (whichever extra is pointing to)
      return extra.next;
}