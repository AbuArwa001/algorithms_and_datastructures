/**
 * minChanges - Calculates the minimum number of changes required to make
 *              a binary string beautiful. A binary string is considered
 *              beautiful if there are no two consecutive characters that
 *              are the same.
 * @s: The input binary string.
 *
 * Return: The minimum number of changes required.
 *
 * Description: This function iterates through the input binary string and
 *              checks pairs of consecutive characters. If a pair of
 *              consecutive characters are the same, it increments the
 *              min_change counter and changes the second character to
 *              make the string beautiful.
 */
int minChanges(char *s)
{
    int len = strlen(s);
    int i = 0, j = 0, min_change = 0;
    char current;
    while (j < len)
    {
        i = j;
        current = s[i];
        for (i = j; i < j + 1; i++)
            if (current != s[i + 1])
            {
                min_change += 1;
                s[i] = current;
            }
        j += 2;
    }
    return min_change;
}
