#include <stdlib.h>
#include <stdio.h>

/**
 * arr_copy - copy array elements
 * @arr_src: source array
 * @arrSize: size of the array
 * @arr_dest: destination array
 * description: copy elements from source array to destination array
 */
void arr_copy(int *arr_src, int arrSize, int *arr_dest)
{
	for (int i = 0; i < arrSize; i++)
	{
		arr_dest[i] = arr_src[i];
	}
}

/**
 * compare - compare function for qsort
 * @a: first element
 * @b: second element
 * Return: difference between the two elements
 */
int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

/**
 * arrayRankTransform - transform array elements to ranks
 * @arr: array of integers
 * @arrSize: size of the array
 * @returnSize: size of the returned array
 * Return: array of ranks
 * description:
 * 1. Create a copy of the array and sort it
 * 2. Create a rank map
 * 3. Assign ranks to the sorted array
 * 4. Map ranks to the original array
 * 5. Return the ranks
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *arrayRankTransform(int *arr, int arrSize, int *returnSize)
{
	if (arrSize == 0)
	{
		*returnSize = 0;
		return (NULL);
	}
	int *ranks = malloc(arrSize * sizeof(int));
	int *rankings = malloc(arrSize * sizeof(int));
	int *arrCopy = malloc(arrSize * sizeof(int));

	if (!ranks || !arrCopy)
	{
		free(ranks);
		free(arrCopy);
		return (NULL);
	}
	*returnSize = arrSize;
	arr_copy(arr, arrSize, arrCopy);
	qsort(arrCopy, arrSize, sizeof(int), compare);
	/* // Create rank_map (dynamic mapping using qsort on sorted unique values) */
	int rank = 1;
	/* // Assign ranks using sorted array */
	ranks[0] = rank; /* // The first element always gets rank 1 */
	for (int i = 1; i < arrSize; i++)
	{
		(arrCopy[i] != arrCopy[i - 1]) ? rank += 1 : rank;
		ranks[i] = rank;
	}
	for (int i = 0; i < arrSize; i++)
	{
		int *pos = (int *)bsearch(&arr[i], arrCopy, arrSize, sizeof(int), compare);

		if (pos != NULL)
		{
			int index = (pos -
						 arrCopy);		/* // Find index of the element in the sorted array */
			rankings[i] = ranks[index]; /* // Map the original value to its rank */
		}
	}
	free(arrCopy);
	free(ranks);
	return (rankings); /* // The original array is now transformed into the ranks */
}
