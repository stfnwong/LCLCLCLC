"""
DISTANCE
Various distance computations. For things like 'distance between integers in array' questions.

Stefan Wong 2019
"""

from typing import List

# NOTE: following this
# (https://medium.com/solvingalgo/solving-algorithmic-problems-max-distance-in-an-array-7e8c9f71c8b)
# Worst method - this just checkes all possible pairs. O(n^2)
def int_min_pair_brute(array:List[int], verbose:bool=False) -> tuple:
    cur_max = 0

    for i, ei in enumerate(array):
        for j, ej in enumerate(array):
            diff = ej - ei
            if (diff > cur_max) and (ei <= ej):
                cur_max = diff
                idx = (i, j)
                pair = (ei, ej)

    return (cur_max, idx, pair)

# Furthest distance in list of integers
def int_array_dist(array:List[int], verbose:bool=False) -> list:
    stack = []

    for n, elem in enumerate(array):
        if verbose:
            print('Processing element [%d / %d]' % (n+1, len(array)))

        if len(stack) == 0:
            stack.append(elem)
        else:
            pass

    return dist

