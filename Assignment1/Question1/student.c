#include "Student.h"

//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

 // TODO: implement
    (void)nums1Size;
    (void)n;

    // For each element in nums2
    for(int i = 0; i < nums2Size; i++)
    {
        // Iterate through nums1 until you reach the first nums1 element greater than nums2[i]
        int j = 0;
        while(nums1[j] < nums2[i])
        {
            // If j has passed the values in num1, break out of while loop
            if(j==m) break;
            // Increment j
            j++;
        }
        // If j is pointing to m-th element, just add new element m-th position
        if(j==m)
        {
            nums1[j] = nums2[i];
        }
        // Otherwise, shift all elements (starting at j) right one
        else
        {
            // Start at (m-1) and end at j
            for(int k = m; k > j; k--)
            {
                // Move k-1 element to index k
                nums1[k] = nums1[k-1];
            }
            // Insert nums2[i] in index j
            nums1[j] = nums2[i];
        }

        // Increment m to account for new element added in nums1
        m++;
    }

}
