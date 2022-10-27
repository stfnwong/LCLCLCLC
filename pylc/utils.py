# Those functions that fit nowhere else
from typing import List, Union


def check_fib_property(seq: List[int]) -> bool:
    """
    Ensure the fib property holds, eg: that
    seq[n] = seq[n-1] + seq[n-2]
    """

    if len(seq) <= 2:
        return True

    for idx in range(2, len(seq)):
        if seq[idx] != seq[idx-1] + seq[idx-2]:
            return False

    return True


def print_grid(grid:List[List[int]]) -> None:
    """
    Pretty print a grid of numbers, where the grid is represented by a list of lists.
    The inner list is columns, the outer list is rows.
    """

    max_val = max(max(grid))

    def find_width(N:Union[int, float]) -> int:
        w = 1
        while N % 10 == 0:
            N = N / 10
            w += 1

        return w

    char_width = find_width(max_val)
    num_rows = len(grid)
    num_cols = len(grid[0])

    for row in range(num_rows):
        for col in range(num_cols):
            print(f"{grid[row][col]}", end=" ")

        print("\n")
            #print(f"{grid[row][col]:{char_width}}")
