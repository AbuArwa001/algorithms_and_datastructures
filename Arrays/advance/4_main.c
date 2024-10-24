#include "main.h"

int main()
{
    int nums1[] = {1, 3};
    int nums2[] = {2, 2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    int nums3Size = sizeof(nums3) / sizeof(nums3[0]);
    int nums4Size = sizeof(nums4) / sizeof(nums4[0]);

    double result1 = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    double result2 = findMedianSortedArrays(nums3, nums3Size, nums4, nums4Size);
    ;

    printf("Median Element 1: %f\n", result1);
    printf("Median Element 2: %f\n", result2);
    return (0);
}
