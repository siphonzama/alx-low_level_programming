#!/usr/bin/python3
'''Module'''


def island_perimeter(grid):
    '''returns the perimeter of the island described in grid'''
    cumm = 0
    for i, row in enumerate(grid):
        for j, cell in enumerate(row):
            if cell == 1:
                cumm += 4
                if j-1 >= 0 and row[j-1] == 1:
                    cumm -= 1
                if j+1 <= len(row) - 1 and row[j+1] == 1:
                    cumm -= 1
                if i-1 >= 0 and grid[i-1][j] == 1:
                    cumm -= 1
                if i+1 <= len(grid) - 1 and grid[i+1][j] == 1:
                    cumm -= 1
    return cumm
