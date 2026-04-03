/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) {
    /* Write your code here */

    // Create a heap
    int* heap = (int*)malloc(k*sizeof(int));
    int heap_size = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        // Keep adding elements of nums until heap_size reaches k
        if(heap_size < k)
        {
            heap[heap_size] = nums[i];
            heapifyUp(heap, heap_size);
            heap_size++;
        }
        // Once heap has size of k, check the rest of the elements of nums
        // If next element of nums is larger than minimum value of heap, don't need min anymore so
        // replace root with element of nums and heapify down
        else if(nums[i] > heap[0])
        {
            heap[0] = nums[i];
            heapifyDown(heap, heap_size, 0);
        }
        
    }
    return heap[0];
    return 0;
}

/*
Optional helper: swap two integers.
*/
static void swap(int* a, int* b) {
    /* Write your code here if you use this helper */
    int temp = *b;
    *b = *a;
    *a = temp;
}

/*
Optional helper: restore min-heap order from a node upward.
*/
static void heapifyUp(int* heap, int index) {
    /* Write your code here if you use this helper */
    while(index > 0 && heap[(index - 1)/2] > heap[index])
    {
        swap(&heap[index], &heap[(index-1)/2]);
        index = (index-1)/2;
    }
}

/*
Optional helper: restore min-heap order from a node downward.
*/
static void heapifyDown(int* heap, int size, int index) {
    /* Write your code here if you use this helper */
    while(1)
    {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index;
        if (left_child < size && heap[left_child] < heap[smallest]) 
        {
            smallest = left_child;
        }
        if (right_child < size && heap[right_child] < heap[smallest]) 
        {
            smallest = right_child;
        }
        if (smallest != index) 
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else break;        
    }
}