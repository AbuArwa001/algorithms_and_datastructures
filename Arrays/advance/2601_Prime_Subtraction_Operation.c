

#include <stdbool.h>
/**
 * isPrime - Checks if a number is prime.
 * @n: The number to check.
 *
 * Return: true if the number is prime, false otherwise.
 */

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
/**
 * find_prime - Finds the largest prime number less than a given number.
 * @n: The number to find the prime less than.
 * @curr: The current value to compare with.
 *
 * Return: The largest prime number less than n.
 */

int find_prime(int n, int curr)
{
    int i = 0;
    for (i = n - 1; i >= 2; i--)
    {
        if (isPrime(i) && curr == 0)
            return i;
        if (isPrime(i) && curr >= (n - i))
            continue;
        if (isPrime(i))
            return i;
    }
    return 0;
}
/**
 * sorted_Nums - Checks if an array of numbers is sorted in ascending order.
 * @nums: The array of numbers.
 * @numsSize: The size of the array.
 *
 * Return: true if the array is sorted, false otherwise.
 */
bool sorted_Nums(int *nums, int numsSize)
{
    int curr = nums[0], i, sorted = 1;
    for (i = 1; i < numsSize; i++)
    {
        if (curr >= nums[i])
        {
            sorted = 0;
            break;
        }
        curr = nums[i];
    }
    if (sorted == 1)
        return true;
    return false;
}
/**
 * primeSubOperation - Performs the prime subtraction operation on an array.
 * @nums: The array of numbers.
 * @numsSize: The size of the array.
 *
 * Return: true if the array can be sorted using the prime subtraction operation, false otherwise.
 */
bool primeSubOperation(int *nums, int numsSize)
{
    int *numTr = malloc(sizeof(int) * numsSize);
    int i = 0, sorted = 1, current = 0;
    if (sorted_Nums(nums, numsSize))
        return true;
    for (i = 0; i < numsSize - 1; i++)
    {
        current = nums[i] - find_prime(nums[i], current);
        nums[i] = current;
        nums[i + 1] = nums[i + 1] - find_prime(nums[i + 1], current);
        current = nums[i + 1];
        if (sorted_Nums(nums, numsSize))
            return true;
    }
    return false;
}
