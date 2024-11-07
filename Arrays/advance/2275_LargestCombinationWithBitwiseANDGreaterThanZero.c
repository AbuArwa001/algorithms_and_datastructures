/**
 * largestCombination - Finds the largest combination of numbers
 *                      with a bitwise AND greater than zero.
 * @candidates: An array of integers representing the candidates.
 * @candidatesSize: The size of the candidates array.
 *
 * Description: This function iterates through the given array of candidates
 * and calculates the number of 1s in each bit position across all numbers.
 * It then determines the maximum count of 1s in any bit position, which
 * represents the largest combination of numbers with a bitwise AND greater
 * than zero.
 *
 * Return: The maximum count of 1s in any bit position.
 */
int largestCombination(int *candidates, int candidatesSize)
{
    int nums[24] = {0};
    int j = 0, i;
    int max = 0;
    for (i = 0; i < candidatesSize; i++)
    {
        int num = candidates[i];
        j = 0;
        while (num > 0)
        {
            int count = 0;
            count = (num & 1);
            nums[j] = count + nums[j];
            max = (max >= nums[j]) ? max : nums[j];
            num >>= 1;
            j++;
        }
    }
    return max;
}