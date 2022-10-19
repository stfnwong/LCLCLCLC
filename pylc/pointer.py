# Questions that move pointers around an array

from typing import List



def two_sum_hashmap_1(nums: List[int], target:int) -> List[int]:
    """
    Version of two-sum using a hashmap. We know the the input array is not sorted in
    the original question, so simply moving two pointers along the array will not find
    the correct solution in general.
    """

    seen = dict()

    for n, elem in enumerate(nums):
        diff = target - elem
        if diff in seen:
            return [seen[diff], n]
        seen[elem] = n

    return []   # in the real question we are guaranteed there is an answer





def two_sum_sort_1(nums: List[int], target:int) -> List[int]:
    """
    Version of two sum where we sort the array first and then adjust two pointers to 
    converge on the solution
    """

    # Create a mapping of the original indicies 
    val_idx = sorted([(val, n) for n, val in enumerate(nums)])

    left = 0
    right = len(val_idx)-1

    while left < right:
        s = val_idx[left][0] + val_idx[right][0]
        if s == target:
            return [val_idx[left][1], val_idx[right][1]]
        elif s > target:    # too large, reduce max value 
            right = right - 1
        else:   # too small, increase min value
            left = left + 1

    return []


# This is an implementation of LC 167 - Two Sum II
def two_sum_ii_2p_lc_167(nums: List[int], target: int) -> List[int]:
    """
    LC 167 In this problem the array is sorted.
    """

    # Since the array is sorted we can use the pointer at each end method directly
    left = 0
    right = len(nums) -1

    while left < right:
        s = nums[left] + nums[right]
        if s == target:
            return [left+1, right+1]
        elif s > target:
            right = right - 1
        else:
            left = left + 1

    return []

