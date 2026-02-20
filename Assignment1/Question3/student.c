#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // TODO: implement

    int* arr = (int*)malloc((size_t)(digitsSize) * sizeof(int));

    // Copy digits into new array
    for(int j = 0; j < digitsSize; j++)
    {
        arr[j] = digits[j];
    }
        
    int i = digitsSize - 1;

    arr[i]=digits[i]+1;

    // Go through all elements other than the first, and carry 1 to the next element to the left if the current element is 10
    while(i>0)
    {
        if(arr[i]==10)
        {
            arr[i]=0;
            arr[i-1]++;
        }
        i--;
    }

    // If the first element is 10, a bigger array is needed
    if(arr[0]==10)
    {
        int* bigger_arr = (int*)malloc((size_t)(digitsSize+1) * sizeof(int));
        // Put a 1 in the 1st element and a 0 in the second
        bigger_arr[0] = 1;
        bigger_arr[1] = 0;
        // Copy the rest of arr into bigger_arr
        for(int k = 2; k < digitsSize + 1; k++)
        {
            bigger_arr[k] = arr[k-1];
        }
        // Bigger array is a new size, so update returnSize
        *returnSize = digitsSize + 1;
        // Return bigger_arr
        return bigger_arr;
    }

    // Else, arr is the same size as digits -> return arr
    *returnSize = digitsSize;
    return arr;
}