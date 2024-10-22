#include <stdlib.h>
#include <stdio.h>

struct st
{
    int ele;
    int count;
};

int singleNumber(int *nums, int numsSize)
{
    struct st *arraySt = (struct st *)malloc(numsSize * sizeof(struct st));
    for (int i = 0; i < numsSize; i++)
    {
        arraySt[i].ele = nums[i];
        arraySt[i].count = 0;
    }

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (arraySt[j].ele == nums[i])
            {
                arraySt[j].count++;
                break;
            }
        }
    }

    int ret = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if (arraySt[j].count == 1)
        {
            ret = arraySt[j].ele;
            break;
        }
    }

    free(arraySt);
    return ret;
}
