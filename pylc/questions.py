"""
QUESTIONS
Answers to specific Leetcode questions

Stefan Wong 2019
"""

from typing import List, Optional

from pylc.tree import TreeNode

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


# leetcode 14
#https://leetcode.com/problems/longest-common-prefix/
def longest_common_prefix_14(strs:List[str]) -> str:
    # It turns out that scanning ahead to find the maximum length
    # the prefix could be is slightly faster on average. The reason
    # for this is that we don't know what order the strings will be
    # in the input, and therefore we might end uo checking more
    # characters than we need to. For example, if the shortest string
    # comes last and we test the string lengths as we go, we will have
    # checked all the characters in the longer strings when it wasn't
    # required

    prefix = ""
    if len(strs) == 0:
        return prefix

    max_prefix = 9999999
    for s in strs:
        if len(s) < max_prefix:
            max_prefix = len(s)

    # Now check each character at position n of string 0 against the
    # character in position n of all other strings (vertical scan)
    for n in range(max_prefix):
        for s in range(len(strs)-1):
            if strs[0][n] != strs[s+1][n]:
                return prefix
        prefix += strs[0][n]

    return prefix


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

# Question 62
# Unique paths
# https://leetcode.com/problems/unique-paths/
def unique_paths_62_brute_force(m: int, n:int) -> int:
    """
    Worst implementation. Each call generates 2 calls where one of row or col
    are decremented by one. Therefore, time complexity is O(2^(n+m)).
    Space complexity is O(n+m) via implied stack space.
    """

    def unique_paths(m:int, n:int, row:int, col:int) -> int:
        if row >= m or col >= n:
            return 0
        if row == m-1 and col == n-1:
            return 1

        return unique_paths(m, n, row+1, col) + unique_paths(m, n, row, col+1)

    return unique_paths(m, n, 0, 0)


# Question 62
# Unique paths
# https://leetcode.com/problems/unique-paths/
def unique_paths_62_memo(m:int, n:int) -> int:
    """
    Same as above but we memoize. We only gain in time complexity as we don't
    recalculate redundant values.

    Time: O(m*n)
    Space: O(m*n)   <- this is the final/worst case size of the cache.
    """

    cache = [[1 for _ in range(n)] for _ in range(m)]

    def unique_paths(m:int, n:int, row:int, col:int, cache:List[List[int]]) -> int:
        if row >= m or col >= n:
            return 0
        if row == m-1 and col == n-1:
            return 1

        cache[row][col] = unique_paths(m, n, row+1, col, cache) + unique_paths(m, n, row, col+1, cache)

        return cache[row][col]

    return unique_paths(m, n, 0, 0, cache)



# Question 64
# Minimum path sum
# https://leetcode.com/problems/minimum-path-sum/
def min_path_sum_64(grid: List[List[int]]) -> int:
    """
    Tabulation solution.
    """

    MAX_COST = 1000

    num_rows = len(grid)
    num_cols = len(grid[0])
    cost = [[0 for _ in range(num_cols)] for _ in range(num_rows)]
    cost[0][0] = grid[0][0]

    for row in range(num_rows):
        for col in range(num_cols):
            # tbh, this can go outside the loop
            if row == 0 and col == 0:
                cost[0][0] = grid[0][0]
                continue

            col_cost = cost[row][col-1] if col > 0 else MAX_COST
            row_cost = cost[row-1][col] if row > 0 else MAX_COST

            cost[row][col] = grid[row][col] + min(row_cost, col_cost)

    return cost[num_rows-1][num_cols-1]




# Question 102
# Binary Tree Level Order Traversal
# https://leetcode.com/problems/binary-tree-level-order-traversal/
def level_order_traversal_102(root: Optional[TreeNode]) -> List[List[int]]:
    pass

# Question 299
# Longest increasing subsequence
# https://leetcode.com/problems/longest-increasing-subsequence/
def lis_300(nums: List[int]) -> int:
    pass


# Question 322
# https://leetcode.com/problems/coin-change/
# You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
#
# Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
#
#You may assume that you have an infinite number of each kind of coin
def coin_change_322(coins:List[int], amount:int) -> int:
    # Time complexity here is  O(C * A) where C is the number of elements in coins
    # and A is the amount.
    #
    # Space complexity is O(A) as we are storing the min value for each value between
    # 0 -> amount in num_ways[].
    #
    # In this case amount+1 is effectively MAX_INT
    num_ways = [(amount+1) for _ in range(amount+1)]
    num_ways[0] = 0

    # Find values for each element in the cache ways
    for k in range(1, amount+1):
        for c in coins:
            if (k - c) >= 0:
                num_ways[k] = min(num_ways[k], num_ways[k - c] + 1)

    if num_ways[amount] < (amount + 1):
        return num_ways[amount]

    return -1


# question 322
# https://leetcode.com/problems/coin-change/
#
# an implementation using a depth-first search.
def coin_change_dfs_322(coins: List[int], amount:int) -> int:
    pass


# Question 416
# https://leetcode.com/problems/partition-equal-subset-sum/

# Question 714
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
def time_to_buy_stock_714(prices: List[int], fee: int) -> int:
    pass


# Question 842
# https://leetcode.com/problems/split-array-into-fibonacci-sequence/
def split_into_fib_seq_842(num:str) -> List[int]:
   """
   You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:

    0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
    f.length >= 3, and
    f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.

Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.
   """

   #
   # "1101111"
   #  ^       <- pointer to left-most digit (i)
   #   ^      <- pointer to current right-most digit (j)
   #   ^      <- pointer to next digit (k)
   #
   # "1101111"
   #  ^       <- pointer to left-most digit (i)
   #   ^      <- pointer to current right-most digit (j)
   #    ^     <- pointer to next digit (k)
   #
   #
   # "1101111"
   #  ^       <- pointer to left-most digit
   #   ^      <- pointer to current right-most digit
   #    ^     <- pointer to next digit.

   # 1, 1, 0  <- fails
   #



