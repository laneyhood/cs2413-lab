#include "two_sum.h"

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) {

    // TODO: implement Two Sum.
    // Requirements:
    //  - find i < j such that nums[i] + nums[j] == target
    //  - store indices in *out_i and *out_j
    //  - return 1 if found; otherwise return 0

    // Traverse the array -- i is the first "pointer," ranges from first element to second-to-last element
    for(int i = 0; i < n - 1; i++)
    {
        // j is the second "pointer," ranges from the element right after the i-th element to the final element in the array
        for(int j = i + 1; j < n; j++)
        {
            // Check whether the sum of the i-th and j-th elements is equal to target -> return 1 and store the indeces if so
            if(nums[i] + nums[j] == target)
            {
                *out_i = i;
                *out_j = j;
                return 1;
            }
        }
    }
    // If end is reached, there is no pair -> return 0
    return 0;
}

//think about the time complexity and space complexity of your solution