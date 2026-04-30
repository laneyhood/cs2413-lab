/*
Question 5: Selection Sort

Description:
Implement selection sort for an integer array.

Selection sort repeatedly finds the smallest element from the unsorted
portion of the array and swaps it with the first element of the unsorted
portion.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
- Do not use any built-in sorting function.
*/

void selectionSort(int arr[], int size) {
    // TODO: implement selection sort
    for(int i = 0; i < size; i++)
    {
        int min = arr[i];
        int min_index = i;
        for(int j = i; j < size; j++)
        {
            if(arr[j] < min)
            {
                min = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    (void)arr;
    (void)size;
}

