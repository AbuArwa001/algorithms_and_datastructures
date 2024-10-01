#include "main.h"

// Function prototype
// int *getConcatenation(int *nums, int numsSize, int *returnSize);

int main()
{
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    // Call the function
    int *result = getConcatenation(nums, numsSize, &returnSize);

    // Print the result
    printf("Concatenated array: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(result);

    return 0;
}