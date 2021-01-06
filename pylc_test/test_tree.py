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
        test_tree          = tree.repr_to_tree(self.rstring)
        expected_size = 7
        size          = tree.tree_size(test_tree)

        self.assertEqual(expected_size, size)



class TestTreeTraverse(unittest.TestCase):
    def setUp(self):
        self.rstring = "[1, 2, None, 3, 4, None, 5, 6, 7]"
        self.expected_size = 7

    def test_inorder_recur(self):
        # get a new tree
        test_tree = tree.repr_to_tree(self.rstring)
        print(test_tree.inorder())
        self.assertEqual(self.expected_size, tree.tree_size(test_tree))

        traversal = inorder(test_tree)

        # TODO : how to check the traversal?

    def test_inorder_iter(self):
        test_tree = tree.repr_to_tree(self.rstring)
        self.assertEqual(self.expected_size, tree.tree_size(test_tree))

        traversal = inorder_iter(test_tree)


if __name__ == '__main__':
    unittest.main()
