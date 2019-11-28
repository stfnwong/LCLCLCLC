"""
QUESTIONS
Answers to specific Leetcode questions

Stefan Wong 2019
"""

# debug
#from pudb import set_trace; set_trace()

# leetcode 53
# https://leetcode.com/problems/maximum-subarray/
def maximum_subarray_53(nums:list) -> int:
    if len(nums) == 0:
        return 0

    max_ever = nums[0]
    max_here = 0

    for elem in nums:
        max_here = max_here + elem
        # Ints may be positive or negative
        if(max_here > max_ever):
            max_ever = max_here
        if(max_here < 0):
            max_here = 0

    return max_ever



# leetcode 55
# https://leetcode.com/problems/jump-game/
# The key insight of this question is to note that a good jump is one
# that allows you to land on position len(nums)-1. Therefore, if we are
# walking towards the end (right hand side) of the array, we can only
# terminate with a True (can reach) if the current position is at
# len(nums) - 1. If we terminate elsewhere, we must return False
def jump_game_55(nums:list) -> bool:

    return jump_game_can_jump_basic(0, nums)


# Inner function - determine if we can jump to the end from here
def jump_game_can_jump_basic(cur_pos:int, nums:list) -> bool:
    if cur_pos == len(nums)-1:
        return True

    if (cur_pos + nums[cur_pos]) > (len(nums)-1):
        max_jump = (cur_pos + nums[cur_pos]) - len(nums)-1
    else:
        max_jump = nums[cur_pos]

    for j in range(max_jump):
        can_jump = jump_game_can_jump_basic(cur_pos + max_jump - j, nums)
        if can_jump:
            return True

    return False