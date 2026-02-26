// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement
    // Create slow and fast pointers
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // If head has no elements or one element, it cannot have a loop
    if(head == NULL || head->next == NULL)
    {
        return false;
    }

    // Check if next two are valid for fast pointer (since it will be ahead of slow)
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow)
        {
            return true;
        }
    }
    return false;
}