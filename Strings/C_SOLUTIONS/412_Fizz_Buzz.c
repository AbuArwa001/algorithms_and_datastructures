#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * fizzBuzz - Generates an array of strings representing the FizzBuzz sequence.
 * @n: The number of elements in the FizzBuzz sequence.
 * @returnSize: Pointer to an integer where the size of the returned array will be stored.
 *
 * Return: A pointer to an array of strings representing the FizzBuzz sequence.
 */

char **fizzBuzz(int n, int *returnSize)
{
    char **str = malloc(sizeof(char *) * n);
    if (!str)
        return (NULL);
    int i;
    *returnSize = n;

    for (int i = 0; i < n; i++)
    {
        str[i] = malloc(sizeof(char) * 9); // Allocate enough space for the longest string "FizzBuzz"
        if (((i + 1) % 3 == 0) && ((i + 1) % 5 == 0))
        {
            strcpy(str[i], "FizzBuzz");
        }
        else if ((i + 1) % 3 == 0)
        {
            strcpy(str[i], "Fizz");
        }
        else if ((i + 1) % 5 == 0)
        {
            strcpy(str[i], "Buzz");
        }
        else
        {
            sprintf(str[i], "%d", i + 1); // Store the number as a string
        }
    }
    return (str);
}
