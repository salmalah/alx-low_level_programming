#!/usr/bin/python3
"""
Module defines the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    Initialise functions
    """
    per = 0
    gg = len(grid[0])
    g = len(grid)
    for r in range(g):
        for c in range(gg):
            if grid[r][c] == 1:
                per += 4
                if r > 0 and grid[r - 1][c] == 1:
                    per -= 2
                if grid[r][c - 1] == 1 and c > 0:
                    per -= 2
    return per
