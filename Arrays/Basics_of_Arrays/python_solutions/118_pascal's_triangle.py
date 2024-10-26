from typing import List


class Solution:
    """
    A class used to generate Pascal's Triangle.
    Methods
    -------
    generate(numRows: int) -> List[List[int]]:
        Generates the first `numRows` of Pascal's Triangle.
        Parameters:
        numRows (int): The number of rows of Pascal's Triangle to generate.
        Returns:
        List[List[int]]: A list of lists, where each inner list represents a row of Pascal's Triangle.
    """
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = []
        for i in range(numRows):
            row = [1] * (i + 1)
            for j in range(1, i):
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
            
            triangle.append(row)
        return triangle