#include <stdbool.h>

/**
 * numOfBits - Counts the number of 1 bits in an integer.
 * @num: The integer to count bits in.
 *
 * Return: The number of 1 bits in the integer.
 */
int numOfBits(int num)
{
    int count = 0;
    while (num)
    {
        count += num & 1; // Add the least significant bit
        num >>= 1;        // Right shift the number
    }
    return count;
}
/**
 * canSortArray - Determines if an array can be sorted by swapping elements
 *                with the same number of 1 bits in their binary representation.
 * @nums: The array of integers to be checked.
 * @numsSize: The size of the array.
 *
 * Return: true if the array can be sorted, false otherwise.
 */
bool canSortArray(int *nums, int numsSize)
{
    int i = 0;
    while (i < numsSize - 1)
    {
        int count = numOfBits(nums[i]);
        int count1 = numOfBits(nums[i + 1]);
        if ((nums[i] > nums[i + 1]) && (count == count1))
        {

            if (count == count1)
            {
                nums[i] = nums[i] ^ nums[i + 1];
                nums[i + 1] = nums[i] ^ nums[i + 1];
                nums[i] = nums[i] ^ nums[i + 1];
                i = 0;
                continue;
            }
            else
            {
                return false;
            }
        }
        else if ((nums[i] > nums[i + 1]) && (count != count1))
        {
            return false;
        }
        i++;
    }
    // printArray(nums, numsSize);
    return true;
}
