"""
QUESTIONS
Answers to specific Leetcode questions

Stefan Wong 2019
"""

def maximum_subarray_53(nums:list) -> int:

    max_ever = 0
    max_here = 0

    for elem in nums:
        max_here = max_here + nums
        # Ints may be positive or negative
        if(max_here < 0):
            max_here = 0
        if(max_ever < max_here):
            max_ever = max_here

    return max_ever
