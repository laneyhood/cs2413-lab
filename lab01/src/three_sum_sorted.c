#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here

    // i pointer goes from first element to second to last element
    for(int i = 0; i < n - 1; i++)
    {
        // Initiate 2 pointers
        int L = i + 1, R = n - 1;

        while(L != R)
        {
            // Check if sum is 0 -> if so, save i,j,k and return 1
            if(nums[i] + nums[L] + nums[R] == 0)
            {
                *out_i = i;
                *out_j = L;
                *out_k = R;
                return 1;
            }
            // If sum too small, increment left pointer
            else if(nums[i] + nums[L] + nums[R] < 0)
            {
                L++;
            }
            // If sum too big, decrement right pointer
            else
            {
                R++;
            }
        }
    }

    return 0;
}
