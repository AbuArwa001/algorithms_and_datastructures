#include <stdlib.h>
#include <math.h>

struct q_map
{
    int index;
    int ele;
};

// Comparison function for sorting `items` based on the first column.
int compareItems(const void *a, const void *b)
{
    int itemA = (*(int **)a)[0];
    int itemB = (*(int **)b)[0];
    return itemA - itemB;
}

// Comparison function for sorting `queries_map` based on the `ele` field.
int compareQueries(const void *a, const void *b)
{
    struct q_map *qA = (struct q_map *)a;
    struct q_map *qB = (struct q_map *)b;
    return qA->ele - qB->ele;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maximumBeauty(int **items, int itemsSize, int *itemsColSize, int *queries,
                   int queriesSize, int *returnSize)
{

    struct q_map *queries_map = malloc(sizeof(struct q_map) * queriesSize);
    int *result = malloc(sizeof(int) * queriesSize);
    int i, j = 0, maxB = 0;
    *returnSize = queriesSize;

    // Map queries to their original indices
    for (i = 0; i < queriesSize; i++)
    {
        queries_map[i].index = i;
        queries_map[i].ele = queries[i];
    }

    // Sort items and queries_map using qsort
    qsort(items, itemsSize, sizeof(int *), compareItems);
    qsort(queries_map, queriesSize, sizeof(struct q_map), compareQueries);

    // Find maximum beauty for each query
    for (i = 0; i < queriesSize; ++i)
    {
        while (j < itemsSize && items[j][0] <= queries_map[i].ele)
        {
            maxB = fmax(maxB, items[j][1]);
            j++;
        }
        result[queries_map[i].index] = maxB;
    }

    free(queries_map);
    return result;
}
