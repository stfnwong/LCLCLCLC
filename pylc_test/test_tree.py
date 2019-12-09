"""
TEST_TREE
Unit tests for tree structure

Stefan Wong 2019
"""

import unittest
from pylc import tree


class TestTree(unittest.TestCase):
    def setUp(self):
        self.rstring = "[1, 2, None, 3, 4, None, 5, 6, 7]"

    #def test_tree_init(self):
    #    pass

    def test_repr_to_tree(self):
        tree          = tree.repr_to_tree(self.rstring)
        expected_size = 7
        size          = tree.tree_size(tree)

        self.assertEqual(expected_size, size)



class TestTreeTraverse(unittest.TestCase):
    def setUp(self):
        self.rstring = "[1, 2, None, 3, 4, None, 5, 6, 7]"
        self.expected_size = 7
        self.expected_inorder = []

    def test_inorder_recur(self):
        # get a new tree
        tree = tree.repr_to_tree(self.rstring)
        self.assertEqual(self.expected_size, tree.tree_size(tree))

        traversal = inorder(tree)

        # TODO : how to check the traversal?

    def test_inorder_iter(self):
        tree = tree.repr_to_tree(self.rstring)
        self.assertEqual(self.expected_size, tree.tree_size(tree))

        traversal = inorder_iter(tree)

