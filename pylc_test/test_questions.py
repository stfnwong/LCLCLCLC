"""
TEST_QUESTIONS
Unit tests for LC questions

Stefan Wong 2019
"""

from typing import List

import time
import unittest
from pylc import questions
from pylc.tree import TreeNode, repr_to_tree
from pylc.utils import check_fib_property



def test_longest_unique_substring_3():
    inputs = ["abcabcbb", "bbbbb", "pwwkew"]
    exp_outputs = [3, 1, 3]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.longest_unique_substring_3(inp)
        assert out == exp_out


def test_longest_common_prefix_14():
    inputs = [
        ["flower", "flow", "flight"],
        ["dog", "racecar", "car"]
    ]
    exp_outputs = [
        "fl",
        ""
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.longest_common_prefix_14(inp)
        assert out == exp_out


# Question 41
# First Missing Positive
# https://leetcode.com/problems/first-missing-positive/
def test_first_missing_positive_41():
    inputs = [
        [3, 4, -1, 1],
        [1, 2, 0],
        [7, 8, 9, 11, 12]
    ]
    exp_outputs = [2, 3, 1]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.first_missing_positive_41(inp)
        #out = questions.first_missing_positive_41_q(inp)
        assert out == exp_out


# Question 49
# Group Anagrams
# https://leetcode.com/problems/group-anagrams
def test_group_anagrams_49():
    inputs = [
        ["eat", "tea", "tan", "ate", "nat", "bat"],
        [""],
        ["a"]
    ]
    exp_outputs = [
        [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]],
        [[""]],
        [["a"]],
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.group_anagrams_49(inp)
        assert len(out) == len(exp_out)    # check we have the correct number of groups
        out_set = set(map(tuple, [sorted(g) for g in out]))
        exp_set = set(map(tuple, [sorted(g) for g in exp_out]))

        assert out_set == exp_set


# leetcode 53
# https://leetcode.com/problems/maximum-subarray/
def test_maximum_subarray_53():
    inputs = [
        [-2, 1, -3, 4, -1, 2, 1, -5, 4],
        [-2],
    ]
    exp_outputs = [6, -2]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.maximum_subarray_53(inp)
        assert out == exp_out


# leetcode 55
# https://leetcode.com/problems/jump-game/
def test_jump_game_55():
    inputs = [
        [2, 3, 1, 1, 4],
        [3, 2, 1, 0, 4],
        [1, 5, 2, 1, 0, 2, 0],
        [2, 0]
    ]
    exp_outputs = [True, False, True, True]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.jump_game_55(inp)
        assert out == exp_out



# Question 62
# Unique paths
# https://leetcode.com/problems/unique-paths/
def test_unique_paths_62():
    inputs = [
        (3, 3),
        (3, 7),
        (3, 2)
    ]
    exp_outputs = [6, 28, 3]
    functions = [
        questions.unique_paths_62_brute_force,
        questions.unique_paths_62_dp,
        questions.unique_paths_62_dp_2,
    ]

    for func in functions:
        print(f"Testing {func.__name__}")
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp[0], inp[1])
            assert out == exp_out


# Question 63
# Unique paths II 
# https://leetcode.com/problems/unique-paths-ii/
def test_unique_paths_ii_63():
    inputs = [
        [[0,0], [1,1], [0,0]],
        [[0, 0, 0], [0, 1, 0], [0, 0, 0]],
        [[0,1], [0,0]],
    ]
    exp_outputs = [0, 2, 1]
    functions =[
        questions.unique_paths_ii_63,
        questions.unique_paths_ii_63_less_mem,
        questions.unique_paths_ii_63_rec_from_end,
    ]

    for func in functions:
        print(f"\nTesting function [{func.__name__}]")
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp)
            assert out == exp_out


# Question 64
# Minimum path sum
# https://leetcode.com/problems/minimum-path-sum/
def test_min_path_sum_64():
    inputs = [
        [[1,3,1],[1,5,1],[4,2,1]],
        [[1,2,3],[4,5,6]]
    ]

    exp_outputs = [7, 12]
    functions = [
        questions.min_path_sum_64,
        questions.min_path_sum_64_top_down,
        questions.min_path_sum_64_top_down_memo,
        questions.min_path_sum_64_tab_2_rows
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp)
            assert out == exp_out



# Question 70
# https://leetcode.com/problems/climbing-stairs/
# Climbing stairs
def test_climbing_stairs_70():
    inputs = [2, 3]
    exp_outputs = [2, 3]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.climbing_stairs_70(inp)
        assert out == exp_out


# Question 84
# Largest Rectangle in Histogram
# https://leetcode.com/problems/largest-rectangle-in-histogram/
def test_largest_rectangle_in_histogram_84():
    inputs = [
        #[2, 1, 5, 6, 2, 3],
        [2, 4],
        [2, 3, 5, 6, 3, 3],
        [5, 5, 5, 5],
    ]
    exp_outputs = [4, 15, 20]
    #exp_outputs = [10, 4, 15, 20]

    #from pudb import set_trace; set_trace()
    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.largest_rectangle_in_histogram_84(inp)
        assert out == exp_out


# Question 102
# Binary Tree Level Order Traversal
# https://leetcode.com/problems/binary-tree-level-order-traversal/
def test_level_order_traversal_102():
    inputs = [
        "[3, 9, 20, null, null, 15, 7]",
        "[1]",
        "[]",
        "[1,2,3,4,null,null,5]",
    ]
    exp_outputs = [
        [[3], [9, 20], [15, 7]],
        [[1]],
        [],
        [[1],[2,3],[4,5]]
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        print(f"Converting tree [{inp}]", end=" ")
        root = repr_to_tree(inp)
        out = questions.level_order_traversal_102(root)
        print(f" ...traversal was {out}")
        assert out == exp_out


# Question 103
# Binary Tree ZigZag Level Order Traversal
# https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
def test_level_order_zigzag_traversal_103():
    inputs = [
        "[3, 9, 20, null, null, 15, 7]",
        "[1]",
        "[]",
        #"[1,2,3,4,null,null,5]",
    ]
    exp_outputs = [
        [[3], [20, 9], [15, 7]],
        [[1]],
        [],
        #[[1],[3, 2],[4,5]]
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        print(f"Converting tree [{inp}]", end=" ")
        root = repr_to_tree(inp)
        out = questions.level_order_zigzag_traversal_103(root)
        print(f" ...traversal was {out}")
        assert out == exp_out




# Question 111
# https://leetcode.com/problems/minimum-depth-of-binary-tree/
# Minimum depth of binary tree
def test_min_depth_binary_tree_111():
    inputs = [
        "[3,9,20,null,null,15,7]",
        "[2,null,3,null,4,null,5,null,6]"
    ]
    exp_outputs = [2, 5]
    functions = [questions.min_depth_111]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            tree = repr_to_tree(inp)
            depth = func(tree)
            assert depth == exp_out


# Question 113
# https://leetcode.com/problems/path-sum-ii/description/
def test_path_sum_ii_113():
    inputs = [
        # (tree_repr, target_sum)
        ("[5,4,8,11,null,13,4,7,2,null,null,5,1]", 22),
        ("[1, 2, 3]", 5),
        ("[1, 2]", 0)
    ]
    exp_outputs = [
        [[5, 4, 11, 2], [5, 8, 4, 5]],
        [],
        []
    ]
    functions = [
        questions.path_sum_ii_113,
        questions.path_sum_ii_113_iter_bfs,
        questions.path_sum_ii_113_iter_dfs,
    ]

    #from pudb import set_trace; set_trace()
    for func in functions:
        print(f"Testing function [{func.__name__}]")
        for inp, exp_out in zip(inputs, exp_outputs):
            tree = repr_to_tree(inp[0])
            out = func(tree, inp[1])
            assert out == exp_out


# Question 114
# https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
def test_flatten_binary_tree_to_linked_list():
    inputs = [
        "[1,2,5,3,4,null,6]",
        "[]",
        "[0]"
    ]

    exp_outputs = [
        [1,None,2,None,3,None,4,None,5,None,6],
        [],
        [0]
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.flatten_binary_tree_to_linked_list_114(inp)
        print(out)




# Question 116
# Populating Next Right Pointers in Each Node
# https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#def test_populate_next_right_pointers_116():
#    inputs = [
#        "[1,2,3,4,5,6,7]",
#        "[]"
#    ]
#    exp_output = []
#


# Question 121
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Best time to buy and sell stock
def test_best_time_to_buy_and_sell_stock_121():
    inputs = [
        [7, 1, 5, 3, 6, 4],
        [7, 6, 4, 3, 1]
    ]
    exp_outputs = [5, 0]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.best_time_to_buy_and_sell_stock_121(inp)
        assert out == exp_out


# Question 131
# https://leetcode.com/problems/palindrome-partitioning/
# Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
def test_palindrome_partitioning_131():
    inputs = [
        "aab",
        "a"
    ]
    exp_outputs = [
        [["a","a","b"],["aa","b"]],
        [["a"]]
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.palindrome_partitioning_131(inp)
        assert out == exp_out


# Question 146
# https://leetcode.com/problems/lru-cache/
def test_lru_cache_146():
    inputs = [
        [("put", [1, 1]), ("get", [1]), ("put", [3, 3]), ("get", [2]), ("put", [4, 4]), ("get", [1]), ("get", [3]), ("get", [4])]
    ]

    exp_outputs = [
        [None, 1, None, None, None, 1, 3, 4]
    ]

    test_size = 2       # This is the size in the example case
    test_cache = questions.LRUCache(test_size)
    for inp_sequence, out_sequence in zip(inputs, exp_outputs):
        # Each input/output pair is a sequence of operations to give to the cache object
        for (op, inp), exp_out in zip(inp_sequence, out_sequence):
            # You could use getattr here but you still have to know that you need to split
            # the [k, v] into k and v arguments. An alternative is to accept a [k, v]
            # as a single argument in the cache API, but I will leave that exercise
            # for later.
            if op == "get":
                out = test_cache.get(inp[0])
            elif op == "put":
                out = test_cache.put(inp[0], inp[1])
            else:
                raise AssertionError(f"Invalid instruction {op} in input")

            assert out == exp_out

# Question 152
# https://leetcode.com/problems/maximum-product-subarray/
# Maximum product subarray
def test_maximum_product_subarray_152():
    inputs = [
        [2, 3, -2, 4],
        [-2, 0, -1]
    ]
    exp_outputs = [6, 0]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.maximum_product_subarray_152(inp)
        assert out == exp_out


# Question 198
# https://leetcode.com/problems/house-robber/
# House Robber
def test_house_robber_198():
    inputs = [
        [1, 2, 3, 1],
        [2, 7, 9, 3, 1]
    ]
    exp_outputs = [4, 12]
    functions = [
        questions.house_robber_198,
        questions.house_robber_198_no_array
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            out =  func(inp)
            assert out == exp_out


# Question 199
# Binary Tree Right Side View
# https://leetcode.com/problems/binary-tree-right-side-view/
def test_binary_tree_right_side_199():
    inputs = [
        "[1,2,3,null,5,null,4]",
        "[1,null,3]",
        "[]",
        "[1,2]"
    ]
    exp_outputs = [
        [1,3,4],
        [1,3],
        [],
        [1,2]
    ]
    functions = [
        questions.bt_right_side_199,
        questions.bt_right_side_199_rec,
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            print(f"Converting tree [{inp}]", end=" ")
            root = repr_to_tree(inp)
            out = func(root)
            print(f" ...traversal was {out}")
            assert out == exp_out



# Question 200
# https://leetcode.com/problems/number-of-islands/
# Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
def test_number_of_islands_200():
    inputs = [
        [
            ["1","1","1","1","0"],
            ["1","1","0","1","0"],
            ["1","1","0","0","0"],
            ["0","0","0","0","0"]
        ],
        [
            ["1","1","0","0","0"],
            ["1","1","0","0","0"],
            ["0","0","1","0","0"],
            ["0","0","0","1","1"]
        ]
    ]

    exp_outputs = [1, 3]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.number_of_islands_200(inp)
        assert out == exp_out


# Question 207
# https://leetcode.com/problems/course-schedule/
# Course Schedule
def test_course_schedule_207():
    inputs = [
        (2, [[1, 0]]),
        (2, [[1,0], [0,1]]),
        (5, [[0, 1], [0, 2], [1, 3], [1, 4], [3, 4]]),
        (3, [[0, 1], [1, 2], [2, 0]]),
    ]
    exp_outputs = [True, False, True, False]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.course_schedule_207_topo(inp[0], inp[1])
        #out = questions.course_schedule_207(inp[0], inp[1])
        assert out == exp_out


# Question 208
# https://leetcode.com/problems/implement-trie-prefix-tree/
# Implement Trie
def test_implement_trie():
    inputs = [
        (
            ["insert", "search", "search", "starts_with", "insert", "search"],
            ["apple", "apple", "app", "app", "app", "app"]
        )
    ]

    exp_outputs = [
        [None, None, True, False, True, None, True]
    ]



# Question 210
# https://leetcode.com/problems/course-schedule/
# Course Schedule II
def test_course_schedule_ii_210():
    inputs = [
        (2, [[1, 0]]),
        (2, [[1,0], [0,1]]),
        (5, [[0, 1], [0, 2], [1, 3], [1, 4], [3, 4]]),
        (3, [[0, 1], [1, 2], [2, 0]]),
    ]
    exp_outputs = [
        [1, 0],
        [],
        [0, 2, 1, 3, 4],  # [0, 1, 2, 3, 4] should also be a valid ordering
        []
    ]
    functions = [
        questions.course_schedule_ii_210,
        questions.course_schedule_ii_210_dfs,
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp[0], inp[1])
            assert len(out) == len(exp_out)
            print(f"out: {out}, exp_out: {exp_out}")
            for o, e in zip(out, exp_out):
                assert o == e


# Question 213
# https://leetcode.com/problems/house-robber-ii/
def test_house_robber_ii_213():
    inputs = [
        [2, 3, 2],
        [1, 2, 3, 1]
    ]
    exp_outputs = [3, 4]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.house_robber_ii_213(inp)
        assert out == exp_out




# Question 239
# https://leetcode.com/problems/sliding-window-maximum/
def test_max_sliding_window_239():
    inputs = [
        # Tuple of (nums, wsize)
        ([1,3,-1,-3,5,3,6,7], 3),
        ([1], 1)
    ]

    exp_outputs = [
        [3,3,5,5,6,7],
        [1]
    ]
    functions = [
        questions.max_sliding_window_239_brute,
        questions.max_sliding_window_239_deque,
        questions.max_sliding_window_239_deque_2,
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            start_time = time.time()
            out = func(inp[0], inp[1])
            end_time = time.time()
            print(f"Execution of [{func.__name__}] took {end_time - start_time} seconds on {len(inp[0])} elements")
            assert out == exp_out


# Question 300
# Longest increasing subsequence
# https://leetcode.com/problems/longest-increasing-subsequence/
def test_lis_300():
    inputs = [
        [1, 2, 3, 4, 1],
        [0, 1, 0, 3, 2, 3],
        [7, 7, 7, 7, 7, 7, 7],
        [10, 9, 2, 5, 3, 7, 101, 18],
    ]

    exp_outputs = [4, 4, 1, 4]
    functions = [
        questions.lis_300_recursive,
        questions.lis_300,
        #questions.lis_300_alt
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            print(f"Checking sequence {inp}", end=" ")
            out = func(inp)
            assert out == exp_out
            print("....[OK]")


# Question 322
# https://leetcode.com/problems/coin-change/
def test_coin_change_332():
    inputs = [
        [1, 2, 5],
        [1, 3, 4, 5],
        [2],
        [1],
    ]

    amounts = [11, 7, 3, 0]
    exp_outputs = [3, 2, -1, 0]

    functions = [
        questions.coin_change_322,
        questions.coin_change_dfs_322,
    ]

    for func in functions:
        for inp, amt, exp_out in zip(inputs, amounts, exp_outputs):
            out = func(inp, amt)
            # TODO: fix
            #assert out == exp_out


# Question 323
# Number of connected components in undirected graph
# https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/


# Question 389
# https://leetcode.com/problems/find-the-difference
# Find The Difference
def test_find_the_difference_389():
    inputs = [
        ("abcd", "abcde"),
        ("", "y"),
        ("", "")
    ]
    exp_outputs = ['e', 'y', '']
    functions = [
        questions.find_the_difference_389,
        questions.find_the_difference_389_no_set,
        questions.find_the_difference_389_alpha_hist,
        questions.find_the_difference_389_dict,
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp[0], inp[1])
            assert out == exp_out



# Question 496
# Next Greater Element
# https://leetcode.com/problems/next-greater-element-i/
def test_next_greater_element_496():
    inputs = [
        # (nums1, nums2)
        ([4, 1, 2], [1, 3, 4, 2]),
        ([2, 4], [1, 2, 3, 4]),
    ]
    exp_outputs = [
        [-1, 3, -1],
        [3, -1]
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.next_greater_element_496(inp[0], inp[1])
        assert out == exp_out



# Question 542
# 01 Matrix
# https://leetcode.com/problems/01-matrix/
def test_matrix_542():

    inputs = [
        [[0, 0, 0], [0, 1, 0], [0, 0, 0]],
        [[0, 0, 0], [0, 1, 0], [1, 1, 1]]
    ]
    exp_outputs = [
        [[0, 0, 0], [0, 1, 0], [0, 0, 0]],
        [[0, 0, 0], [0, 1, 0], [1, 2, 1]]
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.matrix_542(inp)
        assert out == exp_out


# Question 630
# Course Schedule III
# https://leetcode.com/problems/course-schedule-iii/
def test_course_schedule_iii_630():
    inputs = [
        [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]],
        [[1, 2]],
        [[3, 2], [4, 3]]
    ]
    exp_outputs = [3, 1, 0]
    functions = [
        questions.course_schedule_iii_630_dp,   # this is TLE on leetcode since its O(n^2)
        questions.course_schedule_iii_630_pq,
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp)
            assert out == exp_out


# Question 695
# Max Area of Island
# https://leetcode.com/problems/max-area-of-island
def test_max_area_of_island_695():
    inputs = [
        [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]],
        [[0, 0, 0, 0, 0, 0, 0]]
    ]
    exp_outputs = [6, 0]
    functions = [
        questions.max_area_of_island_695,
        questions.max_area_of_island_695_iter,
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp)
            assert out == exp_out


# Question 710
# Random Pick with Blacklist
# https://leetcode.com/problems/random-pick-with-blacklist/
def test_random_pick_with_blacklist_710():
    inputs = [
        (7, [2, 3, 5]),
        (8, [1, 6, 7]),
        (5, [2, 1, 0]),
    ]
    num_picks = 64

    from pudb import set_trace; set_trace()
    for inp in inputs:
        #picker = questions.RandomPickWithBlacklist(inp[0], inp[1])
        picker = questions.RandomPickWithBlacklist2(inp[0], inp[1])
        picks = [picker.pick() for _ in range(num_picks)]
        print(picks)

        for p in picks:
            assert p not in inp[1]
            assert p >= 0



# Question 714
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
# TODO: review
def test_time_to_buy_stock_714():

    input_prices = [
        [1, 3, 2, 8, 4, 9],
        [1, 3, 7, 5, 10, 3],
    ]
    input_fees = [2, 3]

    expected_outputs = [8, 6]

    for price, fee, exp_profit in zip(input_prices, input_fees, expected_outputs):
        max_profit = questions.time_to_buy_stock_714(
            price, fee
        )

        # TODO: fix
        #assert max_profit == exp_profit


# Question 746
# https://leetcode.com/problems/min-cost-climbing-stairs/
# Min cost climbing stairs
def test_min_cost_climbing_stairs_746():
    inputs = [
        [10, 15, 20],
        [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    ]
    exp_outputs = [15, 6]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.min_cost_climbing_stairs_746(inp)
        assert out == exp_out



# Question 743
# https://leetcode.com/problems/network-delay-time 
# Network Delay Time
def test_network_delay_time_743():
    inputs = [
        # (times, n, k), times is a list of (u, v, w) tuples (source, sink, weight)
        ([[4,2,76],[1,3,79],[3,1,81],[4,3,30],[2,1,47],[1,5,61],[1,4,99],[3,4,68],[3,5,46],[4,1,6],[5,4,7],[5,3,44],[4,5,19],[2,3,13],[3,2,18],[1,2,0],[5,1,25],[2,5,58],[2,4,77],[5,2,74]], 5, 3),
        ([[2, 1, 1], [2, 3, 1], [3, 4, 1]], 4, 2),
        ([[1,2,1]], 2, 1),
        ([[1,2,1]], 2, 2),

        ([[2,4,10],[5,2,38],[3,4,33],[4,2,76],[3,2,64],[1,5,54],[1,4,98],[2,3,61],[2,1,0],[3,5,77],[5,1,34],[3,1,79],[5,3,2],[1,2,59],[4,3,46],[5,4,44],[2,5,89],[4,5,21],[1,3,86],[4,1,95]], 5, 1),
    ]
    exp_outputs = [59, 2, 1, -1, 69]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.network_delay_time_743(
            inp[0], inp[1], inp[2]
        )
        assert out == exp_out


# Question 746
# https://leetcode.com/problems/min-cost-climbing-stairs/
# Min cost climbing stairs




# Question 779
# Kth symbol in grammar
# https://leetcode.com/problems/k-th-symbol-in-grammar
def test_kth_symbol_in_grammar_779():
    # inputs are (k, n) pairs
    inputs = [
        (1, 1), (2, 1), (2, 2)
    ]
    exp_outputs = [0, 0, 1]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.kth_symbol_in_grammar_779(inp[0], inp[1])
        assert out == exp_out


# Question 842
# https://leetcode.com/problems/split-array-into-fibonacci-sequence/
def test_split_into_fib_842():
    inputs = [
        "1101111",
        "112358130",
        "0123"
    ]

    for inp in inputs:
        output = questions.split_into_fib_seq_842(inp)
        assert check_fib_property(output) == True


# Question 871
# Minimum Number of Refuelling Stops
# https://leetcode.com/problems/minimum-number-of-refuelling-stops/
def test_min_number_refuelling_stops_871():
    inputs = [
        #(target, start_fuel, [(station_pos, station_fuel)])
        (1, 1, []),
        (100, 1, [[10, 100]]),
        (100, 10, [[10, 60], [20, 30], [30, 30], [60, 40]]),
    ]
    exp_outputs = [0, -1, 2]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.min_number_of_refuelling_stops_871(
            inp[0], inp[1], inp[2]
        )
        assert out == exp_out


# Question 931
# https://leetcode.com/problems/minimum-falling-path-sum/_931
#
# Given an n x n array of integers matrix, return the minimum sum of any falling
# path through matrix.
def test_min_falling_path_sum_931():
    inputs = [
        [[2,1,3],[6,5,4],[7,8,9]],
        [[-19, 57], [-40, -5]]
    ]
    exp_outputs = [13, -59]
    functions = [
        questions.min_falling_path_sum_931,
        questions.min_falling_path_sum_931_tab
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp)
            assert out == exp_out


# Question 994
# Rotting Oranges
# https://leetcode.com/problems/rotting-oranges/
def test_rotting_oranges_994():
    inputs = [
        [[2, 1, 1], [1, 1, 0], [0, 1, 1]],
        [[2, 1, 1], [0, 1, 1], [1, 0, 1]],
        [[0, 2]]
    ]
    exp_outputs = [4, -1, 0]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.rotting_oranges_994(inp)
        assert out == exp_out


# Question 1046
# Last Stone Weight
# https://leetcode.com/problems/last-stone-weight/
def test_last_stone_weight_1046():
    inputs = [
        [2, 7, 4, 1, 8, 1],
        [1],
        [3, 7, 2]
    ]
    exp_outputs = [1, 1, 2]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.last_stone_weight_1046(inp)
        assert out == exp_out


# Question 1049
# Last Stone Weight II
# https://leetcode.com/problems/last-stone-weight-ii/
def test_last_stone_weight_ii_1049() -> None:
    inputs = [
        [2, 7, 4, 1, 8, 1],
        [31, 26, 33, 21 ,40],
    ]
    exp_outputs = [1, 5]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.last_stone_weight_ii_1049(inp)
        assert out == exp_out


# Question 1091
# https://leetcode.com/problems/shortest-path-in-binary-matrix/
def test_shortest_path_in_binary_matrix_1091():
    inputs = [
        [[0, 1], [1, 0]],
        [[0, 0, 0], [1, 1, 0], [1, 1, 0]],
        [[1, 0, 0], [1, 1, 0], [1, 1, 0]]
    ]
    exp_outputs = [2, 4, -1]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.shortest_path_in_binary_matrix_1091(inp)
        assert out == exp_out


# Question 1203
# https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
# Sort Items by Group Respecting Dependencies
def test_sort_items_by_group_1203():
    inputs = [
        # (n, m, group, before_items)
        (8, 2, [-1, -1, 1, 0, 0, 1, 0, -1], [[], [6], [5], [6], [3, 6], [], [], []])
    ]
    exp_outputs = [
        [6, 3, 4, 1, 5, 2, 0, 7]
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.sort_items_by_group_1203(
            inp[0],
            inp[1],
            inp[2],
            inp[3]
        )
        assert len(out) == len(exp_out)
        assert out == exp_out


# Question 1293
# https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
def test_shortest_path_in_grid_with_obstacle_1293():
    inputs = [
        # (grid, k)
        ([[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], 1),
    ]


# Question 1335
# https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
# Minimum Difficulty of a Job Schedule
def test_minimum_difficulty_of_a_job_schedule_1335():
    inputs = [
        # (difficulty, day)
        ([6, 5, 4, 3, 2, 1], 2),
    ]
    exp_outputs = [7]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.minimum_difficulty_of_a_job_schedule_1335(inp[0], inp[1])
        assert out == exp_out



# Question 1584
# https://leetcode.com/problems/min-cost-to-connect-all-points/
def test_min_cost_to_connect_all_points_1584():
    inputs = [
        [[0,0],[2,2],[3,10],[5,2],[7,0]],
        [[3,12],[-2,5],[-4,1]],
    ]
    exp_outputs = [20, 18]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.min_cost_to_connect_all_points_1584(inp)
        assert out == exp_out


# Question 1642
# Furthest Building You Can Reach
# https://leetcode.com/problems/furthest-building-you-can-reach/
#
def test_furthest_building_you_can_reach_1642():
    # (heights, bricks, ladders)
    inputs = [
        ([4, 2, 7, 6, 9, 14, 12], 5, 1),
        ([14, 3, 19, 3], 17, 0),
        ([4, 12, 2, 7, 3, 18, 20, 3, 19], 10, 2)
    ]
    exp_outputs = [4, 3, 7]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.furthest_building_you_can_reach_1642(
            inp[0], inp[1], inp[2]
        )
        assert out == exp_out


# Question 1673
# Find the Most Competitive Subsequence
# https://leetcode.com/problems/find-the-most-competitive-subsequence/
def test_find_the_most_competitive_subsequence_1673():
    inputs = [
        # (nums, k)
        ([3, 5, 2, 6], 2),
        ([2, 4, 3, 3, 5, 4, 9, 6], 4),
        ([71,18,52,29,55,73,24,42,66,8,80,2], 3),
    ]
    exp_outputs = [
        [2, 6],
        [2, 3, 3, 4],
        [8,80,2],
    ]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.find_the_most_competitive_subsequence_1673(inp[0], inp[1])
        assert out == exp_out


# Question 1937
# Maximum Number of Points With Cost
# https://leetcode.com/problems/maximum-number-of-points-with-cost/
def test_maximum_number_of_points_with_cost_1937():
    inputs = [
        [[1, 2, 3], [1, 5, 1], [3, 1, 1]],
    ]
    exp_outputs = [9]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.maximum_number_of_points_with_cost_1937(inp)
        assert out == exp_out


# Question 1971
# https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/
def test_find_if_path_exists_in_graph_1971():
    inputs = [
        (3, [[0,1], [1, 2], [2, 0]], 0, 2),
        (6, [[0,1], [0, 2], [3, 5], [5, 4], [4, 3]], 0, 5)
    ]
    exp_outputs = [True, False]
    functions = [
        questions.find_if_path_exists_in_graph_1971,
        questions.find_if_path_exists_in_graph_1971_iter,
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp[0], inp[1], inp[2], inp[3])
            assert out == exp_out


# Question 2039
# Time When Network Becomes Idle
# https://leetcode.com/problems/time-when-the-network-becomes-idle
def test_time_when_network_becomes_idle_2039():
    inputs = [
        # (edges, patience), edges = list of (u,v) pairs, patience is max time node i waits
        ([[0,1], [1,2]], [0, 2, 1]),
        ([[0,1], [0,2], [1,2]], [0, 10, 10]),
    ]
    exp_outputs = [8, 3]

    #from pudb import set_trace; set_trace()
    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.time_when_network_becomes_idle_2039(inp[0], inp[1])
        assert out == exp_out


# Question 2050
# Parallel Courses III 
# https://leetcode.com/problems/parallel-courses-iii/
def test_parallel_courses_iii_2050():
    inputs = [
        # (n, relations, time)
        (2, [[2,1]], [1000, 1000]),
        (3, [[1, 3], [2, 3]], [3, 2, 5]),
        (5, [[1, 5], [2, 5], [3, 5], [3, 4], [4,5]], [1, 2, 3, 4, 5]),
    ]
    exp_outputs = [2000, 8, 12]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.parallel_courses_iii_2050(
            inp[0], inp[1], inp[2]
        )
        assert out == exp_out
