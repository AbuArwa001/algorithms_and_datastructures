#include <limits.h>

/**
 * maximumSubarraySum - Calculates the maximum sum of distinct subarrays with length k
 * @nums: Pointer to the array of integers
 * @numsSize: Size of the array
 * @k: Length of the subarray
 *
 * Return: The maximum sum of distinct subarrays with length k
 *
 * This function iterates through the array to find subarrays of length k
 * and calculates their sums, ensuring that the elements within each subarray
 * are distinct. It returns the maximum sum found among these subarrays.
 */
long long maximumSubarraySum(int *nums, int numsSize, int k)
{
    if (k > numsSize)
        return 0; // Handle invalid case

    int left = 0;
    long long max = INT_MIN, sum = 0;
    int *occurrences = calloc(100001, sizeof(int));

    for (int right = 0; right < numsSize; right++)
    {

        sum += nums[right];
        occurrences[nums[right]] += 1;

        // If there are duplicates, slide the left pointer
        while (occurrences[nums[right]] > 1)
        {
            occurrences[nums[left]] -= 1;
            sum -= nums[left];
            left++;
        }

        // Check if the window size is exactly k
        if (right - left + 1 == k)
        {
            max = (sum > max) ? sum : max;
            // Slide the window forward
            occurrences[nums[left]] -= 1;
            sum -= nums[left];
            left++;
        }
    }

    free(occurrences);
    return (max == INT_MIN ? 0 : max);
}
