/**
 * compressedString - Compresses a given string using a simple RLE algorithm.
 * @word: The input string to be compressed.
 *
 * Description: This function takes a string as input and compresses it using
 * Run-Length Encoding (RLE). It counts consecutive occurrences of each character
 * and stores the count followed by the character in the compressed string.
 * The function allocates memory for the compressed string, which should be freed
 * by the caller to avoid memory leaks.
 *
 * Return: A pointer to the newly allocated compressed string.
 */
char *compressedString(char *word)
{
    int total_len = strlen(word) * 2;
    char *comp = malloc(sizeof(char) * (total_len) + 1);
    int j = 1, k = 0, i = 1;
    char curr;
    curr = word[0];
    // comp[k++] = curr;
    // for (i = 1; i < strlen(word); i++)
    while (*(word + i))
    {
        if (curr == word[i] && j < 9)
        {
            j++;
        }
        else
        {
            comp[k++] = j + '0';
            comp[k++] = curr;
            curr = *(word + i);
            j = 1;
        }
        i++;
    }
    comp[k++] = j + '0';
    comp[k++] = curr;
    comp[k] = '\0';
    return comp;
}
