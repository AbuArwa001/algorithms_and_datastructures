#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getConcatenation(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize * 2;
    int j = 0;
    int *returnArr = malloc(*returnSize * sizeof(int));
    // int length = sizeof(nums) / sizeof(nums[0]);
    for (int i; i <= *returnSize - 1; i++)
    {
        if (i > numsSize - 1)
        {
            returnArr[i] = nums[j];
            j++;
        }
        else
        {
            returnArr[i] = nums[i];
        }
    }
    return returnArr;
}