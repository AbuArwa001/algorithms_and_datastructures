/**
 * Function to find two numbers in an array that add up to a specific target.
 *
 * @param nums Pointer to the array of integers.
 * @param numsSize The size of the array.
 * @param target The target sum to find in the array.
 * @param returnSize Pointer to an integer where the size of the returned array will be stored.
 * @return Pointer to an array of two integers representing the indices of the two numbers that add up to the target.
 *         If no such pair is found, returns NULL.
 *
 * The function allocates memory for the returned array, which should be freed by the caller.
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *indices = malloc(sizeof(int) * 2);
    int i = 0, j;

    *returnSize = 2;

    while (i < numsSize)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                indices[0] = i;
                indices[1] = j;
                return indices; // Return immediately after finding the result
            }
        }
        i++;
    }

    // In case no solution is found, return NULL
    free(indices);
    return NULL;
}