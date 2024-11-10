#include <limits.h>

int min(int x, int y) { return y ^ ((x ^ y) & -(x < y)); }
void bits_update(int *bits, int num, int diff)
{
    unsigned int i = 0;
    for (i = 0; i < 32; i++)
    {
        if (num & (1U << i))
        {
            bits[i] += diff;
        }
    }
}
int bits_to_int(int *bits)
{
    int res = 0, i;

    for (i = 0; i < 32; i++)
    {
        if (bits[i] > 0)
            res += (1 << i);
    }
    return res;
}
int minimumSubarrayLength(int *nums, int numsSize, int k)
{
    // [1,2,3], k = 2
    int minLength = INT_MAX;
    int left = 0, right = 0;
    int *bits = calloc(32, sizeof(int));
    for (right = 0; right < numsSize; right++)
    {
        bits_update(bits, nums[right], 1);
        int curr = bits_to_int(bits);
        while (left <= right && curr >= k)
        {
            minLength = min(minLength, right - left + 1);
            bits_update(bits, nums[left], -1);
            curr = bits_to_int(bits);
            left += 1;
        }
    }

    return minLength = (minLength == INT_MAX) ? -1 : minLength;
}
