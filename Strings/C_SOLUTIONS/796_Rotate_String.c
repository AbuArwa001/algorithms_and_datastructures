#include <stdbool.h>
#include <stdlib.h>

/**
 * getsub - Extracts a substring from a given string starting from the beginning
 *          up to a specified length.
 * @s: The original string.
 * @start: The length of the substring to extract.
 *
 * Return: A pointer to the newly allocated substring, or NULL if memory
 *         allocation fails.
 */
char *getsub(const char *s, int start)
{
    int i = 0;
    // Allocate memory for the substring
    char *sub = malloc(sizeof(char) * start + 1); // +1 for null terminator
    if (sub == NULL)
    {
        return NULL; // Return NULL if allocation fails
    }
    for (i = 0; i < start; i++)
    {
        sub[i] = s[i];
    }
    sub[i] = '\0';
    return sub;
}
/**
 * rotateString - Checks if one string is a rotation of another string.
 * @s: The original string.
 * @goal: The target string to check against.
 *
 * Return: true if 'goal' is a rotation of 's', false otherwise.
 */
bool rotateString(char *s, char *goal)
{
    int comp, len = 0, i = 0;

    len = strlen(s);

    char str[len + 1];
    memset(str, 0, sizeof(str));

    comp = strcmp(s, goal);
    if (comp == 0)
    {
        return true;
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            char *substring = s + i + 1;
            strcpy(str, substring);
            char *sub = getsub(s, i + 1);
            if (sub != NULL)
                strcat(str, sub);
            comp = strcmp(str, goal);
            if (comp == 0)
                return true;
        }
        return false;
    }
}
