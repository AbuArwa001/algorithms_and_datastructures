/**
 * merge - Merges two sorted arrays into one sorted array.
 *
 * This file contains the implementation of the merge
 * function which takes two sorted arrays
 * and merges them into a single sorted array.
 * The merged array is stored in the first array.
 *
 * @nums1: Pointer to the first sorted array,
 * which has enough space to hold the elements of both arrays.
 * @nums1Size: The total size of the nums1 array.
 * @m: The number of initialized elements in nums1.
 * @nums2: Pointer to the second sorted array.
 * @nums2Size: The total size of the nums2 array.
 * @n: The number of initialized elements in nums2.
 */
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}