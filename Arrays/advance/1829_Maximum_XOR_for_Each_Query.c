/**
 * getMaximumXor - Computes the maximum XOR for each query.
 * @nums: Pointer to the array of integers.
 * @numsSize: Size of the nums array.
 * @maximumBit: The maximum number of bits to consider.
 * @returnSize: Pointer to an integer where the size of the returned array will be stored.
 *
 * Description: This function takes an array of integers and computes the maximum XOR
 * for each query. It returns an array of integers where each element is the result
 * of XORing the cumulative XOR of the input array with the maximum possible value
 * that can be represented with maximumBit bits.
 *
 * Return: Pointer to the array of integers containing the maximum XOR for each query.
 */
int *getMaximumXor(int *nums, int numsSize, int maximumBit, int *returnSize)
{
    int *answer = malloc(numsSize * sizeof(int));
    int i = 0, j = 0, fin, k = pow(2, maximumBit) - 1;
    int num = 0;
    *returnSize = numsSize;
    j = numsSize - 1;
    while (i < numsSize)
    {
        num ^= nums[i];
        *(answer + j) = num ^ k;
        i++;
        j--;
    }
    return answer;
}