/**
 * islandPerimeter - Calculates the perimeter of an island in a 2D grid.
 * @grid: 2D array representing the grid.
 * @gridSize: Number of rows in the grid.
 * @gridColSize: Pointer to the number of columns in the grid.
 *
 * Description: This function iterates through the grid and calculates the
 * perimeter by checking the boundaries and adjacent cells of each land cell.
 *
 * Return: The perimeter of the island.
 *
 * Example:
 * Given the following grid:
 * [
 *     [0,1,0,0],
 *     [1,1,1,0],
 *     [0,1,0,0],
 *     [1,1,0,0]
 * ]
 * The function will return 16 as
 */
int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
	int i, j, param = 0;

	for (i = 0; i < gridSize; i++)
	{
		j = 0;
		while (j < *gridColSize)
		{
			if (grid[i][j] == 0)
			{
				j++;
				continue;
			}

			if (grid[i][j] == 1)
			{
				/* upperside i - 1 */
				if (i - 1 < 0)
					param++;
				else if (grid[i - 1][j] == 0)
					param++;

				/* rightside j + 1 */
				if (j + 1 >= *gridColSize)
					param++;
				else if (grid[i][j + 1] == 0)
					param++;
				/* lowerside i + 1 */
				if (i + 1 >= gridSize)
					param++;
				else if (grid[i + 1][j] == 0)
					param++;
				if (j - 1 < 0)
					param++;
				else if (grid[i][j - 1] == 0)
					param++;
			}
			j++;
		}
	}
	return (param);
}
