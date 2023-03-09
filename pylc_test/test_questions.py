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


def test_maximum_subarray_53():
    inputs = [
        [-2, 1, -3, 4, -1, 2, 1, -5, 4]
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
        (3, 7),
        (3, 2)
    ]
    exp_outputs = [28, 3]
    functions = [
        questions.unique_paths_62_brute_force
    ]

    for func in functions:
        print(f"Testing {func.__name__}")
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp[0], inp[1])
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


# Question 206
# https://leetcode.com/problems/course-schedule/
def test_course_schedule_206():
    graph_inputs = [
        [[1, 0]],
        [[1,0], [0,1]]
    ]
    nc_inputs = [2, 2]
    exp_outputs = [True, False]

    for nc, graph, exp_out in zip(nc_inputs, graph_inputs, exp_outputs):
        out = questions.course_schedule_206(nc, graph)
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
        questions.max_sliding_window_239_deque
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


# Question 714
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#
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


# Question 1293
# https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
def test_shortest_path_in_grid_with_obstacle_1293():
    inputs = [
        # (grid, k)
        ([[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], 1),
    ]

# Question 1584
# https://leetcode.com/problems/min-cost-to-connect-all-points/
def test_min_cost_to_connect_all_points_1584():
    inputs = [
        [[0,0],[2,2],[3,10],[5,2],[7,0]],
        [[3,12],[-2,5],[-4,1]],
        #[[-8988,-8416],[-5299,7210],[-5132,-6801],[-501,4378],[-6429,-2747],[-6707,7699],[4136,-6086],[6311,-5534],[-4114,-9305],[-8189,-9624],[9644,-4646],[-8520,3180],[9018,-2556],[-5445,4930],[1549,7421],[-455,-7400],[3578,1030],[-9676,-7740],[6823,-2933],[8599,1252],[-9122,6121],[-4331,-5318],[8399,4967],[1454,-7459],[-8826,-6339],[-1601,-6797],[-9473,247],[1092,-4900],[5946,-2760],[-4227,9007],[-2034,-1698],[1647,7561],[1353,-9845],[8132,9102],[8012,6644],[8496,-4241],[-4084,1708],[2145,-5993],[4171,7629],[3700,8578],[-4532,9034],[1504,-8983],[-2943,-2501],[9505,-8352],[2729,3954],[-1834,-1837],[-1083,-7265],[5475,-1753],[2684,589],[1269,-4238],[-2160,9037],[-5638,6135],[5638,2211],[5235,8446],[-3559,-3221],[372,9599],[1091,3439],[-1939,2607],[7559,7687],[2411,-9285],[774,6395],[8933,-4090],[1729,-7803],[7707,221],[192,6442],[2666,-8556],[-9394,-7278],[-3436,6198],[-6875,-5577],[-2867,-8426],[-8793,-3110],[-7341,-169],[5555,-1718],[-9725,-4156],[-2756,7213],[1413,-6421],[3261,2341],[-4749,9258],[-8220,1700],[-8242,6550],[6618,-1170],[6851,8241],[5619,3580],[-8944,1442],[-990,9490],[9526,2764],[2867,9679],[-1257,-8846],[-2790,7544],[-8419,-4198],[-3594,4537],[7874,-1396],[3646,-7597],[7350,2628],[9478,-2709],[-4623,-5005],[9044,-3746],[-6955,-5785],[-2175,5650],[4367,-3521],[8504,-1616],[-4546,-2365],[8841,5989],[-5191,1178],[9692,125],[-593,1298],[8350,-2744],[-603,9710],[8983,-3423],[-6393,-1619],[5439,-2874],[4686,-9336],[8776,4842],[-1654,-2478],[-1325,107],[-2511,-7791],[-8477,-5472],[-7026,-427],[-2426,-5032],[2,7761],[3937,-4022],[5355,9532],[337,-2619],[-2166,-4865],[-314,-2231],[-6403,-356],[8370,3473],[-4575,1726],[-3380,-7740],[-8538,3338],[-9502,-1065],[-6139,8975],[-5613,-3139],[-739,-4537],[-5365,329],[7868,3052],[-6290,7374],[-8647,5963],[9889,-2064],[9974,-4514],[5313,-7159],[-7519,1076],[7748,-3701],[-8180,3306],[9686,2669],[9247,-5331],[7282,-7061],[-3077,9371],[-3418,3846],[5637,4391],[-4230,-121],[5453,9099],[1959,6109],[5093,-8844],[5054,8312],[3659,-940],[8363,9969],[-101,-264],[-11,5271],[9460,5886],[494,-4020],[-8877,8164],[-2303,-5103],[-7535,-6647],[-5321,8877],[-5981,6099],[5451,2469],[-1469,-7877],[-5688,-9714],[8648,-7318],[-4535,6785],[2974,5314],[-6017,-5672],[6821,1176],[5458,3798],[-2684,6453],[813,8999],[-6524,8952],[-4414,6571],[3109,-9498],[-3787,5517],[1510,-7545],[5376,8396],[4069,7141],[-562,397],[7604,-6051],[7237,-9629],[-1970,5925],[-9338,-8166],[-6285,7404],[7655,8779],[-5772,-101],[6310,6307],[-4812,2604],[7992,7534],[1100,-1035],[1318,-8732],[8995,-9691],[-8415,-7895],[-5136,-6000],[-3625,-330],[1030,-4247],[2787,1385],[-624,-7305],[-1976,-2812],[-741,-9974],[-6193,-4721],[1199,157],[8295,9380],[-5658,-5301],[-6675,-4990],[-2181,-701],[5192,408],[-1692,6007],[-3271,-8525],[6862,-9175],[-2055,1786],[5905,-486],[3032,1347],[1581,4776],[-4249,-949],[2943,3646],[-8158,1645],[-7362,2848],[3488,-3259],[3483,-7734],[-1535,-8670],[-5878,-7635],[-5536,3947],[-2244,658],[5875,4050],[7989,-1189],[8642,7381],[-6640,-8838],[4971,-2124],[-6951,-8377],[-452,-8449],[1789,-3908],[-8879,-3281],[8668,-1666],[2412,3345],[-4813,5466],[6476,361],[6271,4086],[-1623,-3600],[-5234,-7773],[3992,7081],[5964,7402],[-5158,-307],[-9346,5117],[-2788,1219],[-9691,-7467],[3983,-3384],[9258,-5179],[7457,-3511],[8945,-603],[-3818,-9181],[7617,-6696],[2759,3932],[1528,-8928],[7434,-3165],[-1069,-4960],[3207,-5549],[-6276,-1351],[3744,-9299],[-6972,3162],[-6886,-2824],[-9271,7476],[-1595,1728],[-29,-1217],[7249,8212],[1146,-6591],[1784,6986],[-1585,1461],[-6850,1592],[2703,-8838],[-7391,2755],[-5065,-5565],[-4756,7472],[-3846,4104],[-5041,-1126],[-4896,-9019],[-3624,6080],[4077,-1332],[8627,-5382],[-5786,9566],[-4567,4490],[2253,-6215],[-579,-9047],[-647,-1579],[-2278,-7088],[6855,-3423],[6192,6193],[-3962,-3285],[-785,6981],[6796,2665],[6749,-2647],[7149,840],[7234,2152],[559,-2138],[6132,-4945],[-8386,1981],[-4861,413],[2423,-1170],[7790,-831],[-7736,3443],[-2634,4789],[860,365],[3460,-6434],[-1297,-2600],[-6190,-8501],[-7956,9131],[-3060,-4059],[-9644,7930],[-2873,6790],[5874,-6554],[-9417,-1207],[-456,4639],[-4566,9926],[-9438,2825],[-6042,-3183],[-6495,-3877],[7744,-6847],[-7017,7854],[1848,6927],[-4389,1563],[-4795,6535],[-5241,4654],[6237,-3216],[7194,-2613],[-4326,-5007],[-9698,-778],[6241,5525],[6461,6649],[-8533,5329],[1165,6283],[-4292,-7563],[7594,3596],[-3525,-750],[2025,-4290],[2056,3713],[-1580,-2],[-3026,-4448],[913,1398],[1784,9855],[6823,5176],[-4101,-7117],[9378,-820],[5188,-7520],[6441,-5630],[9220,-2304],[-700,-5775],[-1778,-8855],[-5798,-4711],[1363,-5175],[9020,4459],[326,7169],[6069,2083],[-1523,1319],[-5172,-1917],[9427,8576],[-8713,-5436],[6950,2613],[7137,-7896],[5799,-4602],[6194,1863],[1324,3743],[-9168,-6443],[1465,-1789],[-65,-5349],[-6439,-1075],[-7931,7102],[3888,-4675],[1411,-9841],[-6485,-9322],[9441,-8060],[4728,6773],[-9411,1317],[6466,3161],[1892,-5184],[-8238,-4791],[2143,5460],[4833,1765],[-98,-8624],[-6431,1285],[7949,-6954],[-2162,1485],[-6691,-4410],[6405,6575],[7663,-6223],[-9712,3091],[977,4378],[-4846,6846],[1136,-2407],[-9413,8690],[8173,-8524],[-2463,-8684],[5856,-527],[-9484,5483],[5568,2532],[-3325,640],[-6906,8347],[8943,1320],[1972,9204],[9670,6174],[-2539,8811],[8071,-2298],[4322,9261],[-824,-640],[667,-7559],[2935,3765],[961,1933],[-4225,554],[-2672,-3510],[5510,-4440],[4814,-6211],[5334,115],[4862,3075],[-1938,-7453],[5563,8333],[4903,4369],[-1962,-6210],[-4275,-2512],[-6366,-3346],[9252,5797],[7291,1919],[-8155,-9318],[9531,-3092],[-8120,7513],[-8421,306],[3297,-3803],[9593,-9650],[8578,4628],[5431,3966],[-9600,675],[4979,-5283],[1616,215],[-252,-733],[1846,102],[-4586,3178],[-7218,-2268],[-252,4357],[6752,9575],[4045,7027],[2872,145],[-2515,8818],[7343,7036],[-9071,-8979],[1567,-8532],[5710,4639],[-7649,-4757],[-2316,-3250],[-740,-8523],[-8934,-6745],[9941,2407],[1952,-7321],[4152,-448],[-9594,1085],[-2192,-7473],[9257,4488],[8369,-1238],[-3452,-8993],[-6954,5505],[-312,4659],[-7728,6193],[8092,-6396],[-909,5334],[4077,9062],[-2916,-2665],[-9831,7040],[-9131,2894],[-1036,-8186],[-4364,-5071],[-5484,1140],[-9514,6979],[-6770,5050],[-9931,6683],[-2080,5690],[-4430,-5829],[8014,-7985],[5821,-8714],[5457,9374],[-7217,5224]]
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
        ([4, 12, 2, 7, 3, 18, 20, 3, 19], 10, 2)
    ]
    exp_outputs = [4, 7]

    for inp, exp_out in zip(inputs, exp_outputs):
        out = questions.furthest_building_you_can_reach_1642(
            inp[0], inp[1], inp[2]
        )
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
