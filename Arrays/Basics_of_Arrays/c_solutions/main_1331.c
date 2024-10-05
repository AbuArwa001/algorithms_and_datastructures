#include "main.h"

int main()
{
    int arr[] = {40, 10, 20, 30};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int returnSize;
    int i = 0;

    int *result = arrayRankTransform(arr, arrSize, &returnSize);

    printf("Ranked array: ");
    for (i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
