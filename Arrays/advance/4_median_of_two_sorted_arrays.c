#include "main.h"
/**
 * find_median_sorted_arrays - Finds the median of two sorted arrays.
 * @nums1: Pointer to the first sorted array.
 * @nums1_size: Size of the first sorted array.
 * @nums2: Pointer to the second sorted array.
 * @nums2_size: Size of the second sorted array.
 *
 * Return: The median of the two sorted arrays.
 */
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size)
{
    int i = nums1Size - 1;
    int j = nums2Size - 1;
    int totalSize = nums1Size + nums2Size;
    int medianIndex = (totalSize - 1) / 2;
    bool isEven = (totalSize % 2 == 0);
    double MedEl = 0.0;

    /* We need to keep track of the two most recent values for even case */
    double lastEl = 0.0;

    while (i >= 0 && j >= 0 && totalSize > 0)
    {
        if (nums1[i] > nums2[j])
        {
            if (totalSize - 1 == medianIndex ||
                (isEven && totalSize - 2 == medianIndex))
            {
                lastEl = MedEl;
                MedEl = nums1[i];
            }
            i--;
        }
        else
        {
            if (totalSize - 1 == medianIndex ||
                (isEven && totalSize - 2 == medianIndex))
            {
                lastEl = MedEl;
                MedEl = nums2[j];
            }
            j--;
        }
        totalSize--;
    }

    while (i >= 0 && totalSize > 0)
    {
        if (totalSize - 1 == medianIndex ||
            (isEven && totalSize - 2 == medianIndex))
        {
            lastEl = MedEl;
            MedEl = nums1[i];
        }
        i--;
        totalSize--;
    }

    while (j >= 0 && totalSize > 0)
    {
        if (totalSize - 1 == medianIndex ||
            (isEven && totalSize - 2 == medianIndex))
        {
            lastEl = MedEl;
            MedEl = nums2[j];
        }
        j--;
        totalSize--;
    }

    if (isEven)
    {
        return (MedEl + lastEl) / 2;
    }
    else
    {
        return MedEl;
    }
}
