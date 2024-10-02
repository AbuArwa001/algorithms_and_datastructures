void bubbleSort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            // Swap if the element is greater than the next element
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *arrayRankTransform(int *arr, int arrSize, int *returnSize)
{
    int *ranks = malloc(arrSize * sizeof(int));
    int rank = arrSize;
    int j;
    for (int i = 0; i < arrSize; i++)
    {
        j = 0;
        rank = arrSize;
        while (j < arrSize)
        {
            if (i != j && arr[i] <= arr[j])
            {
                rank -= 1;
            }
            j++;
        }
        ranks[i] = rank;
    }
    // for (int i = 0; i < arrSize; i++) {
    //     printf("%d", ranks[i]);
    //     // ranks[i] = rank;
    // }
    return (ranks);
}
