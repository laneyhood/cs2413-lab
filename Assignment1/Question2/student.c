#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
     // TODO: implement

     // Edge cases: nums is length 1 or 2
     if(numsSize <= 2)
     {
          return nums[0];
     }

     int majority = numsSize / 2;

     // Iterate through to have an element to compare next elements to
     for(int i = 0; i < numsSize - 1; i++)
     {
          // Set up a counter
          int count = 0;
          // Look at elements to the right of index i
          for(int j = i+1; j < numsSize; j++)
          {
               // If the element is the same as the ith element, increment counter
               if(nums[j] == nums[i])
               {
                    count++;
               }
          }
          // If the count has reached majority, return the majority element
          if(count >= majority)
          {
               return nums[i];
          }
     }
     return 0;
}
