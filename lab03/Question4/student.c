// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // TODO: implement

    // Start pointers at beginning of list
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    // Increment fast pointer by 2 and slow pointer by 1
    // Once fast pointer reaches the end in an odd length, slow is pointing to middle element
    // Once fast pointer reaches second to last element in even length, slow is pointing to middle element
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->val;
}