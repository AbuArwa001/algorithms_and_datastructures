#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * isCircularSentence - Checks if a given sentence is circular.
 * @sentence: The input sentence to be checked.
 *
 * Description: A sentence is considered circular if the last character of each
 * word matches the first character of the next word, and the last character of
 * the last word matches the first character of the first word.
 *
 * Return: true if the sentence is circular, false otherwise.
 */
bool isCircularSentence(char *sentence)
{

    // char *arrStr = malloc(sizeof(char *) * 1);
    int i = 0, firstSentence = 0;
    bool circular = false;
    char prev = '0', fl, lc;
    int len;

    char *sent = strtok(sentence, " ");
    fl = sent[0];

    while (sent)
    {
        len = strlen(sent);
        prev = sent[len - 1];
        lc = sent[len - 1];
        sent = strtok(NULL, " ");
        if (sent && (prev != sent[0]))
            return false;
    }
    if (fl != lc)
        return false;
    return true;
}
