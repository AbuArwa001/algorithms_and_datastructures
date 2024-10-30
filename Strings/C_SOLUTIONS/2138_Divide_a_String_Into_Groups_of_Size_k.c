#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strSize - Calculate the size of a string.
 * @s: The input string.
 *
 * Return: The size of the string, or 0 if the string is NULL.
 */
int strSize(char *s)
{
    if (!s)
        return (0);
    return (strlen(s));
}

/**
 * divideString - Divide a string into groups of size k.
 * @s: The input string.
 * @k: The size of each group.
 * @fill: The character to fill the last group if it is not complete.
 * @returnSize: Pointer to an integer where the size of the returned array will be stored.
 *
 * Return: A pointer to an array of strings, where each string is a group of size k.
 *         The returned array must be freed by the caller.
 */
char **divideString(char *s, int k, char fill, int *returnSize)
{
    int arrSize = strSize(s);
    int i, j, l;
    char **arrStr;

    *returnSize = (arrSize + k - 1) / k; /* Calculate the number of subarrays needed */

    arrStr = malloc(*returnSize * sizeof(char *));
    if (!arrStr)
        return (NULL);

    for (j = 0; j < *returnSize; j++)
    {
        arrStr[j] = malloc((k + 1) * sizeof(char)); /* Allocate k + 1 for null terminator */
        if (!arrStr[j])
        {
            while (j--)
                free(arrStr[j]);
            free(arrStr);
            return (NULL);
        }
    }

    i = 0;
    j = 0;
    l = 0;
    for (i = 0; i < arrSize; i++)
    {
        if (l == k)
        {
            arrStr[j][l] = '\0'; /* Null-terminate the current substring */
            l = 0;
            j++;
        }
        arrStr[j][l] = s[i];
        l++;
    }

    /* Fill the rest of the last substring with the fill character if needed */
    while (l < k)
    {
        arrStr[j][l] = fill;
        l++;
    }
    arrStr[j][l] = '\0'; /* Null-terminate the last substring */

    return (arrStr);
}