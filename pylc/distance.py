"""
DISTANCE
Various distance computations. For things like 'distance between integers in array' questions.

Stefan Wong 2019
"""

from typing import List

# debug
#from pudb import set_trace; set_trace()

# =============================================================
# PAIR DISTANCE
# =============================================================

# NOTE: following this
# (https://medium.com/solvingalgo/solving-algorithmic-problems-max-distance-in-an-array-7e8c9f71c8b)
# Worst method - this just checkes all possible pairs. O(n^2)
def int_min_pair_brute(array:List[int], verbose:bool=False) -> tuple:
    cur_max = 0
    idx = None
    pair = None

    for i, ei in enumerate(array):
        for j, ej in enumerate(array):
            # NOTE: in the original question we are subject to the constraint
            # that A[i] <= A[j]
            diff = j - i
            if (diff > cur_max) and (ei <= ej):
                cur_max = diff
                idx = (i, j)
                pair = (ei, ej)

    return (cur_max, idx, pair)


def int_min_pair_recursion(array:List[int], verbose:bool=False) -> tuple:
    cur_max = 0
    idx = None
    pair = None

    # Check the ends of the array
    if array[0] <= array[-1]:
        cur_max = len(array)-1
        idx     = (0, len(array)-1)
        pair    = (array[0], array[-1])
    else:
        pass


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


# =============================================================
# OCCURENCE DISTANCE
# =============================================================

def int_occurence_dist_brute(array:List[int], target_elem:int, verbose:bool=False) -> tuple:
    max_dist = 0
    dist_idx = None

    for i, ei in enumerate(array):
        for j, ej in enumerate(array):
            if (ei == target_elem) and (ei == ej):
                dist = j - i
                if dist > max_dist:
                    max_dist = dist
                    dist_idx = (i, j)

                    if verbose:
                        print('Found new max distance for value %d at %s' % (target_elem, dist_idx))

    return (max_dist, dist_idx)


def int_occurence_dist_hash(array:List[int], target_elem:int, verbose:bool=False) -> tuple:
    max_dist = 0
    dist_map = dict()
    dist_idx = None

    for n, elem in enumerate(array):
        if elem == target_elem:
            if target_elem not in dist_map:
                dist_map[target_elem] = n
            else:
                dist = n - dist_map[target_elem]
                if dist > max_dist:
                    max_dist = dist
                    dist_idx = (dist_map[target_elem], n)

                    if verbose:
                        print('Found new max distance for value %d at %s' % (target_elem, dist_idx))

    return (max_dist, dist_idx)



