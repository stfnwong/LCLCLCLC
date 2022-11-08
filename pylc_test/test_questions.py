"""
TEST_QUESTIONS
Unit tests for LC questions

Stefan Wong 2019
"""

from typing import List

import unittest
from pylc import questions
from pylc.tree import TreeNode, repr_to_tree
from pylc.utils import check_fib_property



class TestQuestion3(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = "abcabcbb"
        self.exp1 = 3
        self.inp2 = "bbbbb"
        self.exp2 = 1
        self.inp3 = "pwwkew"
        self.exp3 = 3

    def test_longest_unique_substring(self) -> None:
        l1 = questions.longest_unique_substring_3(self.inp1)
        print('Input [%s] Expected length %d, got length %d' % (self.inp1, self.exp1, l1))
        self.assertEqual(self.exp1, l1)

        l2 = questions.longest_unique_substring_3(self.inp2)
        print('Input [%s] Expected length %d, got length %d' % (self.inp2, self.exp2, l2))
        self.assertEqual(self.exp2, l2)

        l3 = questions.longest_unique_substring_3(self.inp3)
        print('Input [%s] Expected length %d, got length %d' % (self.inp3, self.exp3, l3))
        self.assertEqual(self.exp3, l3)


class TestQuestion14(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = ["flower", "flow", "flight"]
        self.exp1 = "fl"
        self.inp2 = ["dog", "racecar", "car"]
        self.exp2 = ""

    def test_longest_common_prefix(self) -> None:
        p1 = questions.longest_common_prefix_14(self.inp1)
        print('Input [%s] : expected %s, got %s' % (self.inp1, self.exp1, p1))
        self.assertEqual(self.exp1, p1)

        p2 = questions.longest_common_prefix_14(self.inp2)
        print('Input [%s] : expected %s, got %s' % (self.inp2, self.exp2, p2))
        self.assertEqual(self.exp2, p2)



class TestQuestion53(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        self.exp1 = 6
        self.inp2 = [-2]
        self.exp2 = -2

    def test_max_subarray(self) -> None:
        s1 = questions.maximum_subarray_53(self.inp1)
        self.assertEqual(self.exp1, s1)
        s2 = questions.maximum_subarray_53(self.inp2)
        self.assertEqual(self.exp2, s2)



# For this question, we only need to know if we can or cannot make
# it to the last index. We don't need to know the path.
class TestQuestion55(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = [2, 3, 1, 1, 4]
        self.exp1 = True
        self.inp2 = [3, 2, 1, 0, 4]
        self.exp2 = False
        self.inp3 = [1, 5, 2, 1, 0, 2, 0]
        self.exp3 = True
        self.inp4 = [2, 0]
        self.exp4 = True

    def test_jump_game(self) -> None:
        jump1 = questions.jump_game_55(self.inp1)
        self.assertEqual(self.exp1, jump1)
        jump2 = questions.jump_game_55(self.inp2)
        self.assertEqual(self.exp2, jump2)
        jump3 = questions.jump_game_55(self.inp3)
        self.assertEqual(self.exp3, jump3)

        jump4 = questions.jump_game_55(self.inp4)
        self.assertEqual(self.exp4, jump4)


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
        questions.min_path_sum_64_top_down
    ]

    for func in functions:
        for inp, exp_out in zip(inputs, exp_outputs):
            out = func(inp)
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

        assert max_profit == exp_profit



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


if __name__ == '__main__':
    unittest.main()
