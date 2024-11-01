#include <stdbool.h>
/**
 * isPalindrome - Checks if a given string is a palindrome, considering only
 *                alphanumeric characters and ignoring cases.
 * @s: The input string to be checked.
 *
 * Description: This function takes a string as input and determines if it is
 *              a palindrome. It first filters out non-alphanumeric characters
 *              and converts all characters to lowercase. Then, it checks if
 *              the filtered string reads the same forwards and backwards.
 *
 * Return: true if the string is a palindrome, false otherwise.
 */

bool isPalindrome(char *s)
{
    int i, j = 0, len = 0;

    len = strlen(s);
    char *str = malloc(sizeof(char) * (len + 1));

    j = 0;
    for (i = 0; i < len; i++)
    {
        if (isalnum(s[i]))
        {
            str[j] = tolower(s[i]);
            j++;
        }
    }
    str[j] = '\0';
    int len2 = strlen(str);
    j = len2 - 1;
    for (i = 0; i < len2; i++)
    {
        if (str[i] != str[j])
        {
            free(str);
            return (false);
        }
        if (j == i)
        {
            free(str);
            return (true);
        }
        j--;
    }
    free(str);
    return (true);
}
