#include <stdlib.h>

/**
 * getConcatenation - Concatenates the given array with itself
 * @nums: The array to concatenate
 * @numsSize: The size of the array
 * @returnSize: The size of the concatenated array
 * Return: The concatenated array
 * Description: Given an integer array nums of length n,
 * you want to create an array ans of length 2n where
 * ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n.
 *
 * Note: The returned array must be malloced, assume caller calls free().te an array ans of length 2n where
 * ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n.
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getConcatenation(int *nums, int numsSize, int *returnSize)
{
	*returnSize = numsSize * 2;
	int j = 0;
	/*Allocate memory for the concatenated array*/
	int *finArr = malloc(*returnSize * sizeof(int));

	if (finArr == NULL)
	{
		/*Handle memory allocation failure*/
		return (NULL);
	}

    /*Concatenate the array*/
	for (int i = 0; i < *returnSize; i++)
	{
		if (i >= numsSize)
		{
			finArr[i] = nums[j];
			j++;
		}
		else
		{
			finArr[i] = nums[i];
		}
	}
	return (finArr);
}
