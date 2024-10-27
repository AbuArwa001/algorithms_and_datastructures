
def island_perimeter(grid):
    """
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Add 4 for each land cell
                perimeter += 4

                # Subtract 2 for each adjacent land cell
                if i > 0 and grid[i - 1][j] == 1:  # check the cell above
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:  # check the cell to the left
                    perimeter -= 2

    return perimeter