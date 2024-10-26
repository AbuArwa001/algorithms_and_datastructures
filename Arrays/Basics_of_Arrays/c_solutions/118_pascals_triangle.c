#include "main.h"
/**
 * generate - Generates Pascals Triangle up to a given number of rows.
 * @numRows: The number of rows in Pascal's Triangle to generate.
 * @returnSize: Pointer to an integer where the function will store
 * the number of rows generated.
 * @returnColumnSizes: Pointer to an array where the function will
 * store the number of elements in each row.
 *
 * Description: This function allocates memory
 *			for a 2D array and fills it according to the rules of
 *			Pascal's Triangle.
 * Return: A pointer to a 2D array representing Pascal's Triangle.
 */

int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
	/*  Allocate memory for the outer array (array of arrays) */
	int **arrayOfArrays = malloc(sizeof(int *) * numRows);

	/* Allocate memory for column sizes */
	*returnColumnSizes = malloc(sizeof(int) * numRows);
	*returnSize = numRows; /* Set the return size to numRows */

	/* Loop to fill each row */
	for (int i = 0; i < numRows; i++)
	{
		/* Allocate memory for each row with `i + 1` elements */
		arrayOfArrays[i] = malloc(sizeof(int) * (i + 1));
		(*returnColumnSizes)[i] = i + 1;

		/*  Fill each row according to Pascal's triangle rules */
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				arrayOfArrays[i][j] = 1;
			else
				arrayOfArrays[i][j] = (
						arrayOfArrays[i - 1][j - 1] +
						arrayOfArrays[i - 1][j]
						);
		}
	}

	return (arrayOfArrays);
}
