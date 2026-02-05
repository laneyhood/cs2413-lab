#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // TODO: implement rwo sum solution for sorted arrays.

    // Initialize pointers
    // i starts at beginning of array, j starts at end
    int i = 0, j = n - 1;

    // Continue incrementing/decrementing until the pointers meet in the middle
    while(i != j)
    {
        // Check if sum equals target -> if so, store indeces and return 1
        if(nums[i] + nums[j] == target)
        {
            *out_i = i;
            *out_j = j;
            return 1;
        }
        // Increment i if sum is too small
        else if(nums[i] + nums[j] < target)
        {
            i++;
        }
        // Decrement j if sum is too big
        else
        {
            j--;
        }
    }
    
    // Once they meet, it has gone through all the pairs -> return 0
    return 0;
}
// think about the time complexity and space complexity of your solution

