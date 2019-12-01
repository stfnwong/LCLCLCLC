"""
QUESTIONS
Answers to specific Leetcode questions

Stefan Wong 2019
"""

# debug
#from pudb import set_trace; set_trace()


# leetcode 3
# https://leetcode.com/problems/longest-substring-without-repeating-characters/
def longest_unique_substring_3(s:str) -> int:
    # Lets try a sliding window. We keep incrementing a pointer along the
    # string checking if we have seen a character before. If not, we expand the
    # window
    start = 0
    end = 0
    max_ever = 0

    # Keep a map of any character that we have seen
    seen_chars = dict()

    while(end < len(s)):
        if s[end] not in seen_chars:
            seen_chars[s[end]] = True
            end += 1
            max_ever = max(max_ever, len(seen_chars))
        else:
            del seen_chars[s[start]]
            start += 1

    return max_ever


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
    print('input : %s' % str(nums))
    return jump_game_can_jump_basic(0, nums)


# Inner function - determine if we can jump to the end from here
# NOTE: This function is much too slow.
def jump_game_can_jump_basic(cur_pos:int, nums:list) -> bool:
    if cur_pos == len(nums)-1:
        return True

    if (cur_pos + nums[cur_pos]) > (len(nums)-1):
        max_jump = len(nums) - 1
    else:
        max_jump = cur_pos + nums[cur_pos]

    next_pos = cur_pos + 1
    while(next_pos <= max_jump):
        can_jump = jump_game_can_jump_basic(next_pos, nums)
        if can_jump:
            return True
        next_pos += 1

    return False

# The above solution is expensive, because we have to try every possible
# jump from index zero and backtracking down


# Question 322
# https://leetcode.com/problems/coin-change/
def coin_change_322(coins:list, amount:int) -> int:

    MAX_COST = amount + 1
    num_ways = [MAX_COST for _ in range(amount+1)]
    num_ways[0] = 0

    for k in range(1, amount+1):
        for c in coins:
            if (k - c) >= 0:
                num_ways[k] = min(num_ways[k], num_ways[k - c] + 1)

    if num_ways[amount] < (amount + 1):
        return num_ways[amount]

    return -1



# Question 416
# https://leetcode.com/problems/partition-equal-subset-sum/
