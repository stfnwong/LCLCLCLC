"""
QUESTIONS
Answers to specific Leetcode questions

Stefan Wong 2019
"""

from typing import List, Optional, Tuple
import heapq        # can also use the internal heap structure, but its much slower

from pylc.tree import TreeNode, BinaryTreeNode, RPTreeNode

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
# https://leetcode.com/problems/longest-common-prefix/
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

    Time complexity: O(N*M) where N and M are dimensions of grid.
    Space Complexity = O(N*M) to store the cost array, O(N*M) to store the grid.
    """

    MAX_COST = 1000

    num_rows = len(grid)
    num_cols = len(grid[0])
    cost = [[0 for _ in range(num_cols)] for _ in range(num_rows)]
    cost[0][0] = grid[0][0]

    for row in range(num_rows):
        for col in range(num_cols):
            if row == 0 and col == 0:
                cost[0][0] = grid[0][0]
                continue

            col_cost = cost[row][col-1] if col > 0 else MAX_COST
            row_cost = cost[row-1][col] if row > 0 else MAX_COST

            cost[row][col] = grid[row][col] + min(row_cost, col_cost)

    return cost[num_rows-1][num_cols-1]



def min_path_sum_64_top_down(grid: List[List[int]]) -> int:
    """
    For the sake of completness, here is a top-down solution to the same problem.
    TODO: add memoization.

    Time Complexity: O(2^(n+m))
    Space Complexity: O(n+m)
    """

    MAX_COST = 1000

    num_rows = len(grid)
    num_cols = len(grid[0])

    def sp(grid:List[List[int]], row:int, col:int) -> int:
        # re-use the grid size from the outer scope
        if row == 0 and col == 0:
            return grid[0][0]
        if row >= num_rows or col >= num_cols:
            return MAX_COST
        #if row == (num_rows-1) and col == (num_cols-1):
        #    return grid[row][col]

        # Wrong index here....
        row_cost = sp(grid, row-1, col) + grid[row][col] if row > 0 else MAX_COST
        col_cost = sp(grid, row, col-1) + grid[row][col] if col > 0 else MAX_COST

        return min(row_cost, col_cost)

    return sp(grid, num_rows-1, num_cols-1)





# Question 102
# Binary Tree Level Order Traversal
# https://leetcode.com/problems/binary-tree-level-order-traversal/
def level_order_traversal_102(root: Optional[BinaryTreeNode]) -> List[List[int]]:
    """
    Return a level-order traversal of some BinaryTreeNode. We want to the traversal
    returned as a List, where each element is a List of all the values at a given level.
    """

    if not root:
        return []

    q = [root]
    traversal = []

    #from pudb import set_trace; set_trace()
    while q:
        # Get any nodes from the queue. The nodes will have been added in "level" order
        # since we add all children to the queue at the end of the loop. In other words
        # we expect the length of the queue to double on each level, assuming that all
        # nodes are populated.

        level = []
        for _ in range(len(q)):
            # Add the value from this node to the traversal of this level
            cur_node = q.pop(0)
            if cur_node:
                level.append(cur_node.val)

                # Add any children to the queue, on the subsequent loop we will visit them
                # and their children in turn.
                if cur_node.left:
                    q.append(cur_node.left)
                if cur_node.right:
                    q.append(cur_node.right)

        traversal.append(level)

    return traversal

# Question 111
# https://leetcode.com/problems/minimum-depth-of-binary-tree/
# Minimum depth of binary tree
def min_depth_111(root:Optional[BinaryTreeNode]) -> int:
    """
    Return the minimum depth of a binary tree.
    """
    # Idea 1 - traverse depth first, when you find a node with no children
    # return the depth of that node

    if not root:
        return 0

    height = 0
    q = [root]

    while q:
        num_nodes = len(q)
        height += 1
        for _ in range(num_nodes):
            cur_node = q.pop(0)
            # NOTE: putting a check here on cur_node is actually slower on LC
            if not cur_node.left and not cur_node.right:
                return height

            if cur_node.left:
                q.append(cur_node.left)
            if cur_node.right:
                q.append(cur_node.right)

    return height


# Question 116
# Populating Next Right Pointers in Each Node
# https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#
# In this problem, imagine a perfect binary tree. Cast a line from the nodes on the left
# to the first node on the right. Create pointers to the next right-most node in the tree
def populate_next_right_pointers_116(root:Optional[RPTreeNode]) -> Optional[RPTreeNode]:
    """
    Note that we have a perfect binary tree.

    Time: O(n)
    Space: O(n)
    """

    # Idea 1: Traverse level wise, left to right. In each level make a left-to-right
    # list of nodes and assign pointer "backwards" (or a right-to-left and assign
    # forwards).

    if not root:
        return root

    q = [root]

    while q:
        num_nodes = len(q)
        next_node = None  # initially there are no next nodes
        for _ in range(num_nodes):
            cur_node = q.pop(0)
            cur_node.next_node = next_node
            next_node = cur_node
            # Append any children for traversal, but add to Q in right->left
            if cur_node.right:
                q.append(cur_node.right)
            if cur_node.left:
                q.append(cur_node.left)

    return root


# Question 116
# Populating Next Right Pointers in Each Node
# https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
def populate_next_right_pointers_116_perfect_tree(root:Optional[RPTreeNode]) -> Optional[RPTreeNode]:
    """
    Note that in the problem we are told that we are given a perfect tree. This means
    that any left node is assured to have a corresponding right node.
    """

    if not root:
        return root

    q:List[Tuple[Optional[RPTreeNode], int]] = [(root, 1)]
    prev_node:Optional[RPTreeNode] = None
    prev_level = 0     # what level was above this one
    cur_level = 1

    while q:
        cur_node, cur_level = q.pop(0)

        if cur_level == prev_level:
            # This level equal to previous level - we've seen this level before,
            # therefore this isn't the first node in this level.
            prev_node.next = cur_node
            prev_node = cur_node
        else:
            # Not equal, we are on a new level. The current nodes do not need updating
            prev_level = cur_level
            prev_node = cur_node

        # Because we are told this is a perfect binary tree, we can assume there is
        # a left and right node
        q.append((cur_node.left, cur_level+1))
        q.append((cur_node.right, cur_level+1))

    return root


# Question 103
# Binary Tree ZigZag Level Order Traversal
# https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
def level_order_zigzag_traversal_103(root:Optional[BinaryTreeNode]) -> List[List[int]]:
    """
    The zig-zag level order traversal is the traversal that goes in level order
    from left to right, then on the subsequent level right-to-left, then left-to-right
    and so on.
    """

    if not root:
        return []

    left_first = False
    q = [root]
    traversal = []

    while q:
        level = []
        for _ in range(len(q)):
            cur_node =  q.pop(0)
            if cur_node:
                level.append(cur_node.val)

                if left_first:
                    nodes = [cur_node.left, cur_node.right]
                else:
                    nodes = [cur_node.right, cur_node.left]

                q.extend(nodes)

        left_first = ~left_first
        if level:
            traversal.append(level)

    return traversal


# Question 114
# https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
def flatten_binary_tree_to_linked_list_114(root:Optional[BinaryTreeNode]) -> None:
    """
    Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.

    """
    if not root:
        return root

    stack = [root]
    while stack:
        cur_node = stack.pop(-1)
        # we want to flatten L->R, so push R->L
        if cur_node.right:
            stack.append(cur_node.right)
        if cur_node.left:
            stack.append(cur_node.left)
        # the current top of the stack is now the next node, so
        # we can set the pointers directly.
        cur_node.right = stack[-1]



# Question 114
# https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
# Turns out we can use the Morris Traversal here
# https://www.educative.io/answers/what-is-morris-traversal
def flatten_binary_tree_to_linked_list_114_morris(root:Optional[BinaryTreeNode]) -> None:
    pass


# Question 131
# https://leetcode.com/problems/palindrome-partitioning/
# Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
def palindrome_partitioning_131(s:str) -> List[List[str]]:
    pass


# Question 199
# Binary Tree Right Side View
# https://leetcode.com/problems/binary-tree-right-side-view/
def bt_right_side_199(root: Optional[BinaryTreeNode]) -> List[int]:
    """
    Given the root of a binary tree, return the values ordered from top to bottom on
    the right side only.
    """

    if not root:
        return []

    traversal = []
    q = [root]

    while q:
        num_nodes = len(q)
        # I always put the right node first in this queue
        traversal.append(q[0].val)
        for _ in range(num_nodes):
            cur_node = q.pop(0)
            # note that this check makes the function run way faster on leetcode
            if cur_node:
                if cur_node.right:
                    q.append(cur_node.right)
                if cur_node.left:
                    q.append(cur_node.left)

    return traversal


# Question 199
# Binary Tree Right Side View
# https://leetcode.com/problems/binary-tree-right-side-view/
def bt_right_side_199_rec(root: Optional[BinaryTreeNode]) -> List[int]:

    def solve(root:Optional[BinaryTreeNode], level:int, traversal:List[int]) -> None:
        if not root:
            return

        if len(traversal) == level:
            traversal.append(root.val)

        # go right first
        solve(root.right, level+1, traversal)
        # Then try to go left
        solve(root.left, level+1, traversal)

    t = []
    solve(root, 0, t)

    return t

# Question 200
# https://leetcode.com/problems/number-of-islands/
# Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
def number_of_islands_200(grid:List[List[str]]) -> int:
    pass



# Question 300
# Longest increasing subsequence
# https://leetcode.com/problems/longest-increasing-subsequence/
def lis_300(nums: List[int]) -> int:
    """
    This is the shitty solution

    Time complexity: O(n^2)
    Space complexity: O(n)   (for d array)
    """

    N = len(nums)
    # This is the array that tells us how long each subsequence is. The element d[i]
    # represents the length of the longest subsequence ENDING at nums[i].
    d = [1 for _ in range(N)]

    # Construct d
    #from pudb import set_trace; set_trace()
    ans = d[0]
    for i in range(N):
        for j in range(i):
            if nums[j] < nums[i]:
                d[i] = max(d[i], d[j]+1)
                ans = max(ans, d[i])

    return ans


def lis_300_recursive(nums: List[int]) -> int:
    """
    A recursive solution. This one looks at all pairs of elements in nums.

    Time Complexity: O(n^2)
    Space Complexity: O(n)  (stack)
    """

    MIN_VAL = int(-1e4)

    def solve(nums: List[int], idx: int, prev: int) -> int:
        # Base case - there are no more numbers to pick
        if idx >= len(nums):
            return 0
        dont_take = solve(nums, idx+1, prev) # value if we don't include this value in the subsequence
        if nums[idx] > prev:
            take = 1 + solve(nums, idx+1, nums[idx])   # value if we include this value in the subsequence
        else:
            take = 0

        return max(take, dont_take)

    return solve(nums, 0, MIN_VAL)


# TODO: do a proper DP version
def lis_300_alt(nums: List[int]) -> int:
    """
    This is version where the d array holds the element at which a subsequence of length
    i terminates. This version still has a runtime complexity of O(n^2).
    """

    MAX = 100000
    N = len(nums)
    d = [MAX for _ in range(N+1)]
    d[0] = -MAX

    for i in range(N):
        for j in range(1, N+1):
            if (d[j-1] < nums[i]) and (nums[i] < d[j]):
                d[j] = nums[i]

    ans = 0
    for elem in d:
        if elem < MAX:
            ans = elem

    return ans



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



# Question 931
# https://leetcode.com/problems/minimum-falling-path-sum/_931
#
# Given an n x n array of integers matrix, return the minimum sum of any falling
# path through matrix.
def min_falling_path_sum_931(matrix:List[List[int]]) -> int:
    """
    Do DFS through the list as if it were a graph.
    The terminating conditions are

    - out of bounds
    - last row
    """

    ROW_MAX = len(matrix)
    COL_MAX = len(matrix[0])
    LARGE_NUMBER = int(10e6)

    def dfs(row:int, col:int) -> int:
        if row < 0 or row > ROW_MAX:
            return LARGE_NUMBER


def min_falling_path_sum_931_tab(matrix:List[List[int]]) -> int:
    """
    Compute the cost of every cell in the matrix.
    """

    LARGE_NUMBER = int(1e9)
    dp = [[-1 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
    num_rows = len(matrix)
    num_cols = len(matrix[0])

    # Set the "top" row of dp to just be the values of the matrix.
    # We then walk down the matrix and compute the min value for each position
    for col in range(num_cols):
        dp[0][col] = matrix[0][col]

    # Now walk along the matrix from the next row down and find the min value for
    # each element in DP
    for row in range(1, num_rows):
        for col in range(num_cols):
            # now compute dp[row][col]
            if (col-1) >= 0:
                left = dp[row-1][col-1] + matrix[row][col]
            else:
                left = LARGE_NUMBER

            if col+1 < num_cols:
                right = dp[row-1][col+1] + matrix[row][col]
            else:
                right = LARGE_NUMBER

            up = dp[row-1][col] + matrix[row][col]
            dp[row][col] = min(up, left, right)

    return min(dp[num_rows-1])





# Question 1046
# Last Stone Weight
# https://leetcode.com/problems/last-stone-weight/
def last_stone_weight_1046(stones:List[int]) -> int:
    # One idea - because we always take the heaviest stone use a heap and sort the stones
    # turns out the heap in python is a min heap, so we invert the values here to get
    # a structure that is effectively a max heap
    #
    # The key thing to note here is that we always take the two largest stones, which
    # implies that the array should be sorted.

    stones = [-s for s in stones]
    heapq.heapify(stones)           # O(log N)

    while len(stones) > 1:     #O(N)
        first = heapq.heappop(stones)
        second = heapq.heappop(stones)

        if second != first:
            # this is the reverse of the "real" conditional because all numbers are negative
            new_stone = abs(second) - abs(first)
            heapq.heappush(stones, new_stone)

    if not stones:
        return 0

    return abs(stones[0])





# Question 1049
# Last Stone Weight II
# https://leetcode.com/problems/last-stone-weight-ii/
def last_stone_weight_ii_1049(stones:List[int]) -> int:
    # In this case, the problem isn't bounded by the requirement to take the two largest
    # stones. This means that its actually more like a knapsack problem.
    pass


# Question 1584
# https://leetcode.com/problems/min-cost-to-connect-all-points/
def min_cost_to_connect_all_points_1584(points:List[List[int]]) -> int:
    LARGE_NUMBER = int(10e6)

    def find_cost(p1:List[int], p2:List[int]) -> int:
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    N = len(points)
    min_cost = [LARGE_NUMBER for _ in range(N)]
    cost = 0
    idx = 0

    # THIS IS WRONG
    for _ in range(N):
        min_idx = idx
        for n, point in enumerate(points):
            if n == min_idx:
                continue

            min_cost[n] = min(min_cost[n], find_cost(point, points[min_idx]))
            min_idx = n if (min_cost[n] < min_cost[min_idx]) else min_idx

        cost += min_cost[min_idx]
        idx = min_idx

    return cost


# Question 1971
# https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/
#def find_if_path_exists_in_graph_1971(
