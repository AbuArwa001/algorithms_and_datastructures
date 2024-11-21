
int countUnguarded(int m, int n, int** guards, int guardsSize,
                   int* guardsColSize, int** walls, int wallsSize,
                   int* wallsColSize)  {
    int* grid = calloc(m * n, sizeof(int));

    // Mark guards and walls on the grid
    for (int i = 0; i < guardsSize; i++) {
        int row = guards[i][0];
        int col = guards[i][1];
        grid[row * n + col] = 1; // Guard cell
    }
    for (int i = 0; i < wallsSize; i++) {
        int row = walls[i][0];
        int col = walls[i][1];
        grid[row * n + col] = 2; // Wall cell
    }

    // Mark cells guarded by guards
    for (int i = 0; i < guardsSize; i++) {
        int row = guards[i][0];
        int col = guards[i][1];

        // North
        for (int r = row - 1; r >= 0 && grid[r * n + col] != 2 && grid[r * n + col] != 1; r--) {
            grid[r * n + col] = 3;
        }
        // South
        for (int r = row + 1; r < m && grid[r * n + col] != 2 && grid[r * n + col] != 1; r++) {
            grid[r * n + col] = 3;
        }
        // West
        for (int c = col - 1; c >= 0 && grid[row * n + c] != 2 && grid[row * n + c] != 1; c--) {
            grid[row * n + c] = 3;
        }
        // East
        for (int c = col + 1; c < n && grid[row * n + c] != 2 && grid[row * n + c] != 1; c++) {
            grid[row * n + c] = 3;
        }
    }

    // Count unguarded cells
    int unguardedCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i * n + j] == 0) {
                unguardedCount++;
            }
        }
    }

    free(grid);
    return unguardedCount;
}
