#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxRegion function below.
def maxRegion(grid):
    maxRegion = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            maxRegion = max(maxRegion, countCells(grid, i, j))
    return maxRegion
            
def countCells(grid, i, j):
    if (not(i in range(len(grid)) and j in range(len(grid[0])))):
        return 0
    if (grid[i][j] == 0):
        return 0
    count = 1
    grid[i][j] = 0
    count += countCells(grid, i + 1, j)
    count += countCells(grid, i - 1, j)
    count += countCells(grid, i, j + 1)
    count += countCells(grid, i, j - 1)
    count += countCells(grid, i + 1, j + 1)
    count += countCells(grid, i - 1, j - 1)
    count += countCells(grid, i - 1, j + 1)
    count += countCells(grid, i + 1, j - 1)
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    m = int(input())

    grid = []

    for _ in range(n):
        grid.append(list(map(int, input().rstrip().split())))

    res = maxRegion(grid)

    fptr.write(str(res) + '\n')

    fptr.close()
