"""
QUESTIONS
Answers to specific Leetcode questions

Stefan Wong 2019
"""

from typing import Dict, List, Optional, Tuple
import copy
import heapq        # can also use the internal heap structure, but its much slower
import random
from collections import defaultdict, deque

from pylc.tree import TreeNode, BinaryTreeNode, RPTreeNode



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


# Question 41
# First Missing Positive
# https://leetcode.com/problems/first-missing-positive/
def first_missing_positive_41(nums: List[int]) -> int:

    # The intuition here is that A[A[i]-1] should always equal A[i]
    #
    # For instance, in [1, 2, 0]
    #
    # The first two elements are correct because
    # A[0] = 1, A[1-1] = 1
    # A[1] = 2, A[2-1] = 2
    #
    # For a correctly sorted array this property holds. The A[A[i]-1] is
    # just offsetting the fact that the array is zero indexed.

    N = len(nums)
    for i in range(N):
        while nums[i] > 0 and nums[i] <= N and nums[nums[i]-1] != nums[i]:
            # NOTE: there is a one line swap trick, but it doesn't seem to be working
            # BECAUSE THE INDEX IS MODIFIED IN THE SWAP
            #nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]

            n1 = i
            n2 = nums[i]-1
            nums[n1], nums[n2] = nums[n2], nums[n1]

    # Now walk the array and check the first element
    for n in range(N):
        if nums[n] != n+1:
            return n+1

    return N + 1


def first_missing_positive_41_q(nums: List[int]) -> int:
    # Can we use a min queue here?
    # The answer is no, because we have to implement in constant space (so
    # no additional queue memory). This means that the input needs to be mutable
    # [3, 4, -1, 1]

    q = deque()   # ordered from low to high
    q.append(nums[0])

    for elem in nums[1:]:
        if elem <= 0:
            continue
        if elem >= q[0]:
            q.append(elem)
        else:
            q.appendleft(elem)

    if q[0] != 1:
        return 1

    # We check 1 separately above
    cur_min = 2
    for n in range(len(q)-1):
        if q[n+1] - q[n] != 1:
            return cur_min
        cur_min += 1

    return cur_min


# Question 49
# Group Anagrams
# https://leetcode.com/problems/group-anagrams
def group_anagrams_49(strs: List[str]) -> List[List[str]]:

    anagrams = defaultdict(list)

    for s in strs:
        k = "".join(sorted(s))
        anagrams[k].append(s)

    ans = []
    for group in anagrams.values():
        ans.append(group)

    return ans





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

    # Inner function - determine if we can jump to the end from here
    # NOTE: This function is much too slow. We have to try every possible jump from
    # index 0 and backtrack down.
    def can_jump(cur_pos:int, nums:list) -> bool:
        if cur_pos == len(nums)-1:
            return True

        if (cur_pos + nums[cur_pos]) > (len(nums)-1):
            max_jump = len(nums) - 1
        else:
            max_jump = cur_pos + nums[cur_pos]

        next_pos = cur_pos + 1
        while(next_pos <= max_jump):
            cj = can_jump(next_pos, nums)
            if cj:
                return True
            next_pos += 1

        return False

    return can_jump(0, nums)



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


# It should be possible to implement the tabulation method from top to bottom storing
# only the two most recent rows
def min_path_sum_64_tab_2_rows(grid: List[List[int]]) -> int:
    MAX_COST = 10000

    num_rows = len(grid)
    num_cols = len(grid[0])
    cur_row  = [0 for _ in range(num_cols)]
    prev_row = [0 for _ in range(num_cols)]

    cur_row[0] = grid[0][0]
    for row in range(num_rows):
        for col in range(num_cols):
            if row == 0 and col == 0:
                continue

            col_cost = cur_row[col-1] if col > 0 else MAX_COST
            row_cost = prev_row[col] if row > 0 else MAX_COST
            cur_row[col] = grid[row][col] + min(row_cost, col_cost)

        prev_row = cur_row

    return cur_row[-1]




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

        row_cost = sp(grid, row-1, col) + grid[row][col] if row > 0 else MAX_COST
        col_cost = sp(grid, row, col-1) + grid[row][col] if col > 0 else MAX_COST

        return min(row_cost, col_cost)

    return sp(grid, num_rows-1, num_cols-1)




def min_path_sum_64_top_down_memo(grid: List[List[int]]) -> int:
    """
    Same as above but memoized
    """
    MAX_COST = 1000

    num_rows = len(grid)
    num_cols = len(grid[0])

    # Memoize the results in this array
    memo = [[-1 for _ in range(num_cols)] for _ in range(num_rows)]

    def sp(grid:List[List[int]], memo: List[List[int]], row:int, col:int) -> int:
        # re-use the grid size from the outer scope
        if row == 0 and col == 0:
            return grid[0][0]
        if row >= num_rows or col >= num_cols:
            return MAX_COST

        if memo[row][col] != -1:
            return memo[row][col]

        row_cost = sp(grid, memo, row-1, col) + grid[row][col] if row > 0 else MAX_COST
        col_cost = sp(grid, memo, row, col-1) + grid[row][col] if col > 0 else MAX_COST
        memo[row][col] = min(row_cost, col_cost)

        return memo[row][col]

    return sp(grid, memo, num_rows-1, num_cols-1)


# Question 70
# https://leetcode.com/problems/climbing-stairs/
# Climbing stairs
def climbing_stairs_70(n: int) -> int:
    """
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
    """
    # Note that this is just standard fibonacci but re-worded

    one_step = 1
    two_step = 1

    for _ in range(n-1):
        temp = one_step
        one_step = one_step + two_step
        two_step = temp

    return one_step


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



# Question 113
# https://leetcode.com/problems/path-sum-ii/description/
def path_sum_ii_113(root: Optional[BinaryTreeNode], target_sum:int) -> List[List[int]]:
    """
    Given the root of a binary tree and an integer targetSum, return all root-to-leaf
    paths where the sum of the node values in the path equals targetSum. Each path
    should be returned as a list of the node values, not node references.

    A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
    """

    def dfs(node:Optional[BinaryTreeNode], path:List[int], valid_paths:List[List[int]], cur_sum:int) -> None:
        """
        DFS helper function
        """
        if node:
            path.append(node.val)
            cur_sum += node.val

            if node.right is None and node.left is None:
                if cur_sum == target_sum:
                    valid_paths.append(copy.copy(path))
            else:
                dfs(node.left, path, valid_paths, cur_sum)
                dfs(node.right, path, valid_paths, cur_sum)

            cur_sum -= node.val
            path.pop()


    results  = []
    if not root:
        return results

    dfs(root, [], results, 0)

    return results


def path_sum_ii_113_iter_bfs(root: Optional[BinaryTreeNode], target_sum:int) -> List[List[int]]:
    """
    Same as above but iterative (BFS).
    """
    results = []
    if not root:
        return results

    # (node, cur_path)
    q = [(root, [root.val])]     # Ends up with V log V nodes in worst case

    while q:
        cur_node, cur_path = q.pop(0)

        # Check and terminate
        if cur_node.left is None and cur_node.right is None:
            if sum(cur_path) == target_sum:
                results.append(copy.copy(cur_path))

        if cur_node.left:
            q.append((cur_node.left, cur_path + [cur_node.left.val]))

        if cur_node.right:
            q.append((cur_node.right, cur_path + [cur_node.right.val]))

        # q = [(n1, [n1]), (n2, [n1, n2]), (n3, [n1, n3])].....
        # q = [(n1, [n1]), (n2, [n1, n2]), (n3, [n1, n3])].....
        # n2, [n1, n2]  -> (n4, [n1, n2, n4])

    return results


def path_sum_ii_113_iter_dfs(root: Optional[BinaryTreeNode], target_sum:int) -> List[List[int]]:
    """
    What about if we record what level we are on and store in the queue?
    """

    results = []
    if not root:
        return results

    # Helper function - this is just to make debugging simpler
    path_sum = lambda path: sum([n.val for n in path])

    q = [(root, 0)]    # (cur_node, cur_depth)
    cur_path = []

    while q:
        cur_node, cur_level = q.pop(-1)

        if len(cur_path) > cur_level:
            cur_path = cur_path[:cur_level]

        cur_path.append(cur_node)

        if cur_node.left is None and cur_node.right is None:
            if path_sum(cur_path) == target_sum:
                results.append([n.val for n in cur_path])

        # If we don't go right first we end up with the results in the opposite
        # order than expected in the unit test. To save doing anything about that we
        # just flip the order here
        if cur_node.right:
            q.append((cur_node.right, cur_level + 1))

        if cur_node.left:
            q.append((cur_node.left, cur_level + 1))

    return results



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


# Question 121
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Best time to buy and sell stock
def best_time_to_buy_and_sell_stock_121(prices: List[int]) -> int:
    """
    Two pointers solution. Left pointer is buy time, right pointer is sell time.
    """

    left = 0
    right = 1
    max_prof = 0

    while right < len(prices):
        # Is this a potentially profitable stock?
        if prices[left] < prices[right]:
            prof = prices[right] - prices[left]
            max_prof = max(max_prof, prof)
        else:
            left += 1
        right += 1

    return max_prof


# Question 131
# https://leetcode.com/problems/palindrome-partitioning/
# Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
def palindrome_partitioning_131(s:str) -> List[List[str]]:
    """
    """
    pass


# Question 146
# https://leetcode.com/problems/lru-cache/


# Question 152
# https://leetcode.com/problems/maximum-product-subarray/
# Maximum product subarray
def maximum_product_subarray_152(nums: List[int]) -> int:
    """
    """




# Question 198
# https://leetcode.com/problems/house-robber/
# House Robber
def house_robber_198(nums: List[int]) -> int:
    # There are two edge cases
    if not nums:
        return 0
    if len(nums) < 3:
        return max(nums)

    dp = [0 for _ in range(len(nums))]
    dp[0] = nums[0]
    dp[1] = nums[1]

    for i in range(2, len(dp)):
        dp[i] = max(nums[i] + dp[i-2], dp[i-1])

    return dp[-1]


# Question 198
# You don't need to store the entire array here since it cumulative, you can just keep
# the last two values in memory as these are the only two values you look at anyway
def house_robber_198_no_array(nums: List[int]) -> int:
    if not nums:
        return 0

    if len(nums) < 3:
        return max(nums)

    max_minus_2 = nums[0]
    max_minus_1 = nums[1]

    new_max = 0  # shut linter up
    for i in range(2, len(nums)):
        new_max = max(nums[i] + max_minus_2, max_minus_1)
        max_minus_2 = max_minus_1
        max_minus_1 = new_max

    return new_max



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
    """
    This is the naive BFS version
    """

    if not grid:
        return 0

    n_rows = len(grid)
    n_cols = len(grid[0])

    visited = set()
    num_islands = 0

    def bfs(r: int, c: int):
        """
        Helper function to do the actual BFS. We add new grid positions to the queue
        and mark them as visited.
        """
        q = deque()
        q.append((r, c))
        visited.add((r, c))

        while q:
            cur_row, cur_col = q.popleft()
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

            for dir_row, dir_col in directions:
                rr = cur_row + dir_row
                cc = cur_col + dir_col
                if ((rr, cc) not in visited and
                     rr in range(n_rows) and
                     cc in range(n_cols) and
                     grid[rr][cc] == "1" and
                     (rr, cc) not in visited):
                   q.append((cur_row + dir_row, cur_col + dir_col))      # need to BFS on this cell also
                   visited.add((rr, cc))

    for r in range(n_rows):
        for c in range(n_cols):
            if grid[r][c] == "1" and (r, c) not in visited:    # Note that the elements are strings, not ints
                bfs(r, c)
                num_islands += 1

    return num_islands



# Question 207
# https://leetcode.com/problems/course-schedule/
def course_schedule_207(num_courses:int, prereqs:List[List[int]]) -> bool:
    """
    This is a graph traversal where we want to find if there are any cycles in the graph.
    We don't know that it is a complete graph. If we DFS the graph and visit the same node
    twice we can tell there is a cycle and that its impossible to take all the courses.
    """

    # adj list of graph
    graph = {i:[] for i in range(num_courses)}
    for vert, edge in prereqs:
        graph[vert].append(edge)

    # keep track of which nodes have been visited
    visited = set()

    def dfs(vert):
        if vert in visited:    # seen before
            return False
        if graph[vert] == []:   # this vert has no prereqs
            return True

        visited.add(vert)
        for edge in graph[vert]:
            if not dfs(edge):
                return False
        visited.remove(vert)
        #graph[vert] = []
        return True

    start_vert = 0
    return dfs(start_vert)



# TODO: should do a BFS version as well....
#def course_schedule_207_bfs(num_courses:int, prereqs:List[List[int]]) -> bool:


def course_schedule_207_topo(num_courses:int, prereqs:List[List[int]]) -> bool:
    graph = {i: [] for i in range(num_courses)}
    for v, e in prereqs:
        graph[v].append(e)

    # Construct mapping of indegree
    indegrees = {v: 0 for v in graph}
    for nb in graph.values():
        for n in nb:
            indegrees[n] += 1

    # Now find a node with 0 indegrees
    zero_id_nodes = [node for node in indegrees if indegrees[node] == 0]
    ordering = []       # topologically sorted ordering

    while len(zero_id_nodes) > 0:
        node = zero_id_nodes.pop()
        ordering.append(node)

        # remove from graph - to do this we decrement indegree of each neighbour 
        for nb in graph[node]:
            indegrees[nb] -= 1
            if indegrees[nb] == 0:
                zero_id_nodes.append(nb)

    # If the number of nodes in the ordering and graph are the same then we found 
    # a valid topological ordering of the graph.
    if len(ordering) == len(graph):
        return True

    return False



# Question 208
# https://leetcode.com/problems/implement-trie-prefix-tree/
# Implement Trie

class TrieNode:
    def __init__(self, c:str):
        self.char = c
        self.termination = False
        self.children = {}


class Trie:
    def __init__(self):
        pass

    def insert(self, word:str) -> None:
        pass

    def search(self, word:str) -> bool:
        pass

    def starts_with(self, word:str) -> bool:
        pass


# Question 210
# https://leetcode.com/problems/course-schedule/
# Course Schedule II
def course_schedule_ii_210(num_courses:int, prereqs:List[List[int]]) -> List[int]:
    # This question is effectively asking for a topological sort of a graph

    # Create a graph
    graph = {i: [] for i in range(num_courses)}
    for v, e in prereqs:
        graph[v].append(e)

    indeg = {v: 0 for v in graph}
    for nb in graph.values():
        for n in nb:
            indeg[n] += 1

    zero_q = [node for node in indeg if indeg[node] == 0]
    ordering = []

    while zero_q:
        cur_node = zero_q.pop()
        ordering.append(cur_node)

        # check neighbours 
        for nb in graph[cur_node]:
            indeg[nb] -= 1
            if indeg[nb] == 0:
                zero_q.append(nb)

    return ordering


# The other valid topological ordering is DFS ordering. This is the recursive implementation
def course_schedule_ii_210_dfs(num_courses:int, prereqs:List[List[int]]) -> List[int]:

    # Creating the graph is the same 
    graph = {i: [] for i in range(num_courses)}
    for v, e in prereqs:
        graph[v].append(e)

    # Since there are always N nodes in this question we can just use a list,
    # but we may prefer a dict if the numbering of the nodes wasn't just from 0 -> N-1
    # 0 = not visited, 1 = visited in this branch only, 2 = visited 
    visited = [0 for _ in range(num_courses)]
    ordering = []


    def dfs(vert:int) -> bool:
        # Return true if there is a valid DFS (no cycles)
        visited[vert] = 1       #  at the start of the branch we mark as semi-visited
        for nb in graph[vert]:
            if (visited[nb] == 0 and not dfs(nb)) or visited[nb] == 1:
                return False
        visited[vert] = 2       # "fully" visited 
        ordering.append(vert)
        return True


    # Now we DFS from the start, trying every unvisited node 
    for n in range(num_courses):
        # not dfs() indicates that we can't do a valid DFS from here 
        if visited[n] == 0 and not dfs(n):
            return []

    # The DFS ordering is the reverse of the BFS ordering
    print(f"ordering: {ordering}, ordering reversed {ordering[::-1]}")
    return ordering[::-1]



# Question 213
# https://leetcode.com/problems/house-robber-ii/
def house_robber_ii_213(nums: List[int]) -> int:
    """
    """

# Question 239
# https://leetcode.com/problems/sliding-window-maximum/
def max_sliding_window_239_brute(nums:List[int], k:int) -> List[int]:
    """
    You are given an array of integers nums, there is a sliding window of size k which
    is moving from the very left of the array to the very right. You can only see the
    k numbers in the window. Each time the sliding window moves right by one position.

    The shit implementation - this is an O(N^2) version with two loops.
    This one has Time Complexity O(N*K)
    We also need O(N-K+1) space to store the window
    """
    n = len(nums)
    if n * k == 0:
        return []

    # This is equivalent to
    #max_win = []
    #for i in range(len(nums)-k+1):
    #    max_win.append(nums[i:i+k])
    #return max_win
    return [max(nums[i:i+k]) for i in range(n-k+1)]


#def max_sliding_window_239_heap(nums:List[int], k:int) -> List[int]:
#    """
#    The brute force solution fails when N (or even K) is large. One alternative is
#    to use a heap. The idea is that the heap will allow fast access to the max within
#    the window. By removing the minimum elements from the heap we can track the maximum
#    without needing a nested loop.
#
#    Some ideas:
#    https://leetcode.com/problems/sliding-window-maximum/discuss/2193922/Python-Heap
#    https://leetcode.com/problems/sliding-window-maximum/discuss/871317/Clear-thinking-process-with-PICTURE-brute-force-to-mono-deque-pythonjavajavascript
#    """


def max_sliding_window_239_deque(nums:List[int], k:int) -> List[int]:
    """
    The brute approach is very slow when N (or K) is large. One approach is to use a
    monotonic queue. This is a queue where the elements are sorted in some monotonically
    increasing or decreasing order. In this data structure the elements from head to
    tail are in decreasing order.

    To make this possible we adjust the push operation so that before we push an
    element into the deque we first pop everything smaller than that element out of
    the deque.
    """
    q = deque()
    results = []

    for idx, cur_elem in enumerate(nums):
        while q and nums[q[-1]] <= cur_elem:
            # Get rid of all the smaller elements so that cur_elem is the smallest
            q.pop()

        q.append(idx)
        # Remove the first element if it falls outside the window
        if q[0] == (idx - k):
            q.popleft()

        # If the window as k elements then add this to the results
        # Remember that the first k-1 windows have less than k elements because we start
        # from an empty window
        if idx > k -1:
            results.append(nums[q[0]])

    return results


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


# Question 389
# https://leetcode.com/problems/find-the-difference
# Find The Difference
def find_the_difference_389(s1: str, s2: str) -> str:
    try:
        result = set(s1).symmetric_difference(set(s2)).pop()
    except KeyError:
        result = ''

    return result


# What if we require the use of a histogram?
def find_the_difference_389_no_set(s1: str, s2: str) -> str:

    if len(s2) > len(s1):
        long_str = s2
        short_str = s1
    else:
        long_str = s1
        short_str = s2

    for c in long_str:
        # NOTE: this comparison might itself be O(N)
        if c not in short_str:
            return c

    return ''


def find_the_difference_389_alpha_hist(s1: str, s2: str) -> str:
    alpha_hist = [0 for _ in range(26)]

    for c in s1:
        alpha_hist[ord(c) - ord('a')] -= 1

    for c in s2:
        alpha_hist[ord(c) - ord('a')] += 1

    for n, l in enumerate(alpha_hist):
        if l > 0:
            return chr(n + ord('a'))

    return ''


# This is actually the stupidest one yet
def find_the_difference_389_dict(s1: str, s2: str) -> str:
    hist = {c: 1 for c in s2}

    for c in s1:
        if c in hist:
            hist.pop(c)

    try:
        return list(hist.keys())[0]
    except IndexError:
        return ''


# Question 416
# https://leetcode.com/problems/partition-equal-subset-sum/


# Question 542
# 01 Matrix
# https://leetcode.com/problems/01-matrix/
def matrix_542(matrix: List[List[int]]) -> List[List[int]]:

    num_rows = len(matrix)
    num_cols = len(matrix[0])

    q = []
    dist = [[-1 for _ in range(num_cols)] for _ in range(num_rows)]

    # Find initial candidates
    for row in range(num_rows):
        for col in range(num_cols):
            if matrix[row][col] == 0:
                q.append((row, col))
                dist[row][col] = 0   # 0 has a distance of 0 (to itself)


    # Now BFS from all q positions
    row_dir = (1, -1, 0, 0)
    col_dir = (0, 0, 1, -1)

    while q:
        r, c = q.pop(0)

        for row_dx, col_dx in zip(row_dir, col_dir):
            nrow = r + row_dx
            ncol = c + col_dx

            # bounds check
            if (0 <= nrow and nrow < num_rows) and (0 <= ncol and ncol < num_cols) and dist[nrow][ncol] == -1:
                dist[nrow][ncol] = dist[r][c] + 1
                q.append((nrow, ncol))

    return dist


# Question 695
# Max Area of Island
# https://leetcode.com/proble
def max_area_of_island_695(grid: List[List[int]]) -> int:
    num_rows = len(grid)
    num_cols = len(grid[0])

    visited = [[0 for _ in range(num_cols)] for _ in range(num_rows)]

    def dfs(row:int, col:int) -> int:
        # bounds check
        if row < 0 or row >= num_rows or col < 0 or col >= num_cols:
            return 0

        # Is this water or land we have seen before?
        if visited[row][col] == 1 or grid[row][col] == 0:
            return 0

        visited[row][col] = 1
        # try each direction
        return dfs(row-1, col) + dfs(row+1, col) + dfs(row, col-1) + dfs(row, col+1) + 1


    # Find initial positions of islands
    max_area = 0
    for r in range(num_rows):
        for c in range(num_cols):
            if grid[r][c] == 1 and visited[r][c] == 0:     # some land
                area = dfs(r, c)
                max_area = max(max_area, area)

    return max_area


# Is an iterative solution possible?
def max_area_of_island_695_iter(grid: List[List[int]]) -> int:

    num_rows = len(grid)
    num_cols = len(grid[0])
    visited = [[0 for _ in range(num_cols)] for _ in range(num_rows)]


    def find_area(row:int, col:int) ->int:
        stack = [(r, c)]
        row_dirs = (1, -1, 0, 0)
        col_dirs = (0, 0, -1, 1)
        area = 0

        while stack:
            cur_row, cur_col = stack.pop()

            # find valid neighbours
            for rdx, cdx in zip(row_dirs, col_dirs):
                new_row = rdx + cur_row
                new_col = cdx + cur_col

                if (0 <= new_row and new_row < num_rows) and (0 <= new_col and new_col < num_cols):
                    if grid[new_row][new_col] == 1 and visited[new_row][new_col] == 0:
                        visited[new_row][new_col] = 1
                        area += 1
                        # try neighbours of this cell
                        stack.append((new_row, new_col))

        return area

    # We still have no idea where to start, so we need to try all possible paths
    max_area = 0
    for r in range(num_rows):
        for c in range(num_cols):
            if grid[r][c] == 1 and visited[r][c] == 0:
                area = find_area(r, c)     # dfs from here
                max_area = max(area, max_area)

    return max_area



def bl710_construct_map_without_boundary(N:int, blacklist:List[int]) -> Dict[int, int]:
    bl_2_wl = {}
    bl_set = set(blacklist)
    idx = N-1     # start at the top of the list and map backwards

    # This gives a better result in the sample case...
    # But why? The theory is that we map numbers from
    for elem in bl_set:
        while idx in bl_set:
            idx -= 1
        bl_2_wl[elem] = idx
        idx -= 1        # skip to the next smallest

    return bl_2_wl


def bl710_construct_map_with_boundary(N:int, blacklist:List[int]) -> Dict[int, int]:
    bl_2_wl = {}
    # implement the boundary condition using two sets
    bl_set = set(blacklist)
    sample_size = N - len(bl_set)

    #bl_greater = set([k for k in range(sample_size, N) if k not in bl_set])
    idx = N-1     # start at the top of the list and map backwards

    # Now we go over the blacklist and for each item less than N we map to a
    # non-blacklist number greater than N

    for elem in bl_set:
        if elem <= sample_size:
            while idx in bl_set:
                idx -= 1
            bl_2_wl[elem] = idx
            idx -= 1        # skip to the next smallest

    return bl_2_wl


# Question 710
# Random Pick with Blacklist
# https://leetcode.com/problems/random-pick-with-blacklist/
class RandomPickWithBlacklist:
    def __init__(self, N:int, blacklist:List[int]):
        #bl_map_1 = bl710_construct_map_with_boundary(N, blacklist)
        #print(f"Blacklist with boundary: ")
        #for k, v in bl_map_1.items():
        #    print(f"[{k}]: {v}")

        #bl_map_2 = bl710_construct_map_without_boundary(N, blacklist)
        #print(f"Blacklist without boundary: ")
        #for k, v in bl_map_2.items():
        #    print(f"[{k}]: {v}")

        self.N = N
        self.bl_2_wl = {}       # map blacklist digits to some whitelist digits

        bl_set = set(blacklist)
        idx = N-1
        self.sample_size = N - len(bl_set)
        #valid_nums = N - len(bl_set)  # TODO: what is the deal with this boundary line?

        for num in bl_set:
            while idx in bl_set:
                idx -= 1
            self.bl_2_wl[num] = idx
            idx -= 1

    def pick(self) -> int:
        #r = random.randint(0, self.sample_size)
        r = random.randint(0, self.N-1)
        return self.bl_2_wl[r] if r in self.bl_2_wl else r


class RandomPickWithBlacklist2:
    def __init__(self, N:int, blacklist:List[int]):
        self.N = N
        self.bl_2_wl = {}

        bl_set = set(blacklist)
        self.sample_size = N - len(bl_set)

        ridx = N-1
        lidx = 0

        for num in bl_set:
            if num < self.sample_size:
                while ridx in bl_set:
                    ridx -= 1
                self.bl_2_wl[num] = ridx
                ridx -= 1
            else:
                while lidx in bl_set:
                    lidx += 1
                self.bl_2_wl[num] = lidx
                lidx += 1

        print(f"Input:")
        print(f"self.N: {self.N}, blacklist: {blacklist}")
        print("Mapping:")
        for k, v in self.bl_2_wl.items():
            print(f"[{k}]: {v}")

        #to_remap = []

        #for n in blacklist:
        #    if n <= self.sample_size:
        #        to_remap.append(n)

        #r = 0
        #for i in range(self.sample_size, self.N):
        #    if i not in bl_set:
        #        self.bl_2_wl[to_remap[r]] = i
        #        r += 1

        #print(f"Remapping map:")
        #for k, v in self.bl_2_wl.items():
        #    print(f"[{k}]: {v}")

    def pick(self) -> int:
        r = random.randint(0, self.N-1)
        return self.bl_2_wl[r] if r in self.bl_2_wl else r



# Question 714
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
def time_to_buy_stock_714(prices: List[int], fee: int) -> int:
    pass


# Question 746
# https://leetcode.com/problems/min-cost-climbing-stairs/
# Min cost climbing stairs
def min_cost_climbing_stairs_746(cost: List[int]) -> int:

    costs = [0 for _ in range(len(cost))]   # in theory you can re-use the input list by appending to the front as you work backwards
    for idx in range(len(costs)-3, -1, -1):
        cost[idx] = min(cost[idx] + cost[idx+1], cost[idx] + cost[idx+2])

    # we only need to select from the starting positions
    return min(cost[0], cost[1])



# Question 779
# Kth symbol in grammar
# https://leetcode.com/problems/k-th-symbol-in-grammar
def kth_symbol_in_grammar_779(n: int, k:int) -> int:
    # The observation here is that there are only two combinations of solutions
    #
    #   0
    #  / \
    # 0   1
    #
    # and
    #
    #   1
    #  / \
    # 1   0
    #
    # and that combination of the parent value in the tree and the (1-indexed)
    # position k can uniquely identify the output value

    # This is the root element for all trees
    if n == 0:
        return 0

    # Each pair has a single parent, so every other k connects to a new k
    # on the row above.
    parent = kth_symbol_in_grammar_779(n-1, k // 2)

    if parent == 0:
        return 1 if (k % 2 == 0) else 0
    else:
        return 0 if (k % 2 == 1) else 1



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



# Question 994
# Rotting Oranges
# https://leetcode.com/problems/rotting-oranges/
def rotting_oranges_994(grid: List[List[int]]) -> int:
    num_rows = len(grid)
    num_cols = len(grid[0])

    row_dirs = (0, 0, -1, 1)
    col_dirs = (1, -1, 0, 0)
    # -1 = not visited, n = visited on turn n
    visited = [[-1 for _ in range(num_cols)] for _ in range(num_rows)]

    # BFS queue
    q = deque()

    # Find start positions - these are where there are rotting oranges
    for row in range(num_rows):
        for col in range(num_cols):
            if grid[row][col] == 2:
                visited[row][col] = 0
                q.append((row, col))

    # Now perform BFS from all starting points in queue.
    while q:
        r, c = q.popleft()

        for row_dir, col_dir in zip(row_dirs, col_dirs):
            new_row = r + row_dir
            new_col = c + col_dir

            # Bounds check
            if (0 <= new_row and new_row < num_rows) and (0 <= new_col and new_col < num_cols):
                if grid[new_row][new_col] == 1 and visited[new_row][new_col] == -1:
                    visited[new_row][new_col] = visited[r][c] + 1
                    q.append((new_row, new_col))

    # Now we've marked all nodes through time
    result = 0
    for row in range(num_rows):
        for col in range(num_cols):
            # If there is a fresh orange that we never reached then result is -1
            if grid[row][col] == 1 and visited[row][col] == -1:
                return -1

            # If there is a fresh orange here, then save the turn in which is turned bad
            if grid[row][col] == 1:
                result = max(result, visited[row][col])

    return result







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


# Question 1091
# https://leetcode.com/problems/shortest-path-in-binary-matrix/
def shortest_path_in_binary_matrix_1091(grid: List[List[int]]) -> int:
    """
    Given an n x n binary matrix grid, return the length of the shortest clear path
    in the matrix. If there is no clear path, return -1.

    A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0))
    to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    - All the visited cells of the path are 0.
    - All the adjacent cells of the path are 8-directionally connected (i.e., they are
        different and they share an edge or a corner).

    The length of a clear path is the number of visited cells of this path.
    """

    if not grid:
        return -1

    num_rows = len(grid)
    num_cols = len(grid[0])

    # If the start or end are blocked then we automatically can't move
    if grid[0][0] == 1 or grid[num_rows-1][num_cols-1] == 1:
        return -1

    end_pos = (num_rows-1, num_cols-1)
    # We can move 8-directionally, cache each direction here
    directions = [(-1, 0), (-1, -1), (-1, 1), (0, 1), (0, -1), (1, 0), (1, -1), (1, 1)]
    # Assume here that we can't modify the grid
    visited = set()

    # Perform BFS on all nodes in the grid.
    queue = deque()   # (x, y, dist)
    queue.append((0,0,1))

    while queue:
        row, col, dist = queue.popleft()
        # Don't revist positions on the grid
        if (row, col) in visited:
            continue

        # Check if we reached the end
        if (row, col) == end_pos:
            return dist

        visited.add((row, col))

        for r, c in directions:
            row_inc = row + r
            col_inc = col + c

            if (row_inc >= 0 and row_inc < num_rows) and \
               (col_inc >= 0 and col_inc < num_cols) and \
               grid[row_inc][col_inc] != 1 and \
               (row_inc, col_inc) not in visited:
                   queue.append((row_inc, col_inc, dist+1))


    return -1






# Question 1293
# https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
def shortest_path_in_grid_with_obstacle_1293(grid: List[List[int]], k:int) -> int:
    """
    You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1
    (obstacle). You can move up, down, left, or right from and to an empty cell in one
    step.

    Return the minimum number of steps to walk from the upper left corner (0, 0) to the
    lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles.
    If it is not possible to find such walk return -1.
    """





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



# Question 1642
# Furthest Building You Can Reach
# https://leetcode.com/problems/furthest-building-you-can-reach/
def furthest_building_you_can_reach_1642(heights: List[int], bricks: int, ladders: int) -> int:

    # TODO: could there be a DP solution? Since we don't know if we should pick bricks
    # or ladders to get the optimal result?
    # The answer for DP is basically no, because in practice the state space of the
    # problem is too big (for instance, you may get up to 10^9 bricks)
    N = len(heights)
    brick_heap = []

    bricks_used = 0
    for h in range(N-1):
        height_diff = heights[h+1] - heights[h]
        if height_diff <= 0:
            continue

        # Lets try the strategy of preferring to use bricks where possible
        bricks_used += height_diff
        heapq.heappush(brick_heap, -bricks_used)

        # If we run out of bricks, use a ladder instead
        if bricks_used >= bricks:
            if ladders > 0:
                ladders -= 1
                # Note the double negative due to the max heap property
                bricks_used -= (-heapq.heappop(brick_heap))
            else:
                return h
    return N-1



# Question 1971
# https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/
def find_if_path_exists_in_graph_1971(n: int, edges: List[List[int]], source: int, dest: int) -> bool:
    """
    Imagine this as a graph traversal (ie: DFS). This version is recursive
    """

    # First build a graph representation of all the nodes
    graph = defaultdict(list)

    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)    # not needed if we know the graph is unidirectional


    seen = set()

    def dfs(node_key:int) -> bool:
        # Anytime we manage to pick the dest node we are done
        if node_key == dest:
            return True

        seen.add(node_key)
        for v in graph[node_key]:
            if v not in seen:
                return dfs(v)

        return False

    return dfs(source)



# Question 1971
# https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/
def find_if_path_exists_in_graph_1971_iter(n: int, edges: List[List[int]], source: int, dest: int) -> bool:
    """
    Same, but now solve iteratively. It can be useful to say that Python sucks at
    recursion when the expected stack depth is ~1000 or more and therefore an iterative
    DFS might scale better.
    """

    # Construct the graph same way
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)


    seen = set()
    node_stack = [source]   # NOTE: just a stack of ints

    while node_stack:
        cur_node = node_stack.pop(0)

        if cur_node == dest:
            return True


        seen.add(cur_node)
        for v in graph[cur_node]:
            if v not in seen:
                node_stack.append(v)

    return False
