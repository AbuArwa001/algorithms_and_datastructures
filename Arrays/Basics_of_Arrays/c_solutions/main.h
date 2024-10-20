#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

int *getConcatenation(int *nums, int numsSize, int *returnSize);
int *arrayRankTransform(int *arr, int arrSize, int *returnSize);
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
int *twoSum(int *nums, int numsSize, int target, int *returnSize);
#endif /*MAIN_H*/