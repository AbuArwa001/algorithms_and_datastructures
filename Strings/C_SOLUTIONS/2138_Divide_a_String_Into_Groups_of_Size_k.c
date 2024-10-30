int strSize(char *s)
{
    if (!s)
        return 0;
    return strlen(s);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *  s = "abcdefghij", k = 3, fill = 'x'
 */
char **divideString(char *s, int k, char fill, int *returnSize)
{
    int arrSize = strSize(s);
    *returnSize = (arrSize + k - 1) / k; // Calculate the number of subarrays needed

    char **arrStr = malloc(*returnSize * sizeof(char *));
    for (int j = 0; j < *returnSize; j++)
    {
        arrStr[j] = malloc((k + 1) * sizeof(char)); // Allocate k + 1 for null terminator
    }

    int i = 0, j = 0, l = 0;
    for (i = 0; i < arrSize; i++)
    {
        if (l == k)
        {
            arrStr[j][l] = '\0'; // Null-terminate the current substring
            l = 0;
            j++;
        }
        arrStr[j][l] = s[i];
        l++;
    }

    // Fill the rest of the last substring with the fill character if needed
    while (l < k)
    {
        arrStr[j][l] = fill;
        l++;
    }
    arrStr[j][l] = '\0'; // Null-terminate the last substring

    return arrStr;
}