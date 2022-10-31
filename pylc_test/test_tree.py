"""
TEST_TREE
Unit tests for tree structure

Stefan Wong 2019
"""

import unittest
from pylc.tree import (
    repr_to_tree,
    tree_size,
    inorder,
    inorder_iter
)

rstring = "[1, 2, None, 3, 4, None, 5, 6, 7]"
expected_size = 7

def test_repr_to_tree():
    tree          = repr_to_tree(rstring)
    size          = tree_size(tree)
    assert size == expected_size


def test_inorder_traverse():
    tree = repr_to_tree(rstring)
    size = tree_size(tree)
    assert size == expected_size

    t_input = []
    traversal = inorder(tree, t_input)
    assert len(traversal) == expected_size

        # TODO : how to check the traversal?


def test_tree_size():
    tree_repr = "[1, 2, null, 3]"
    expected_size = 3

    tree = repr_to_tree(tree_repr)
    out = tree_size(tree)

    assert out == expected_size


#def test_inorder_iter_traverse():
#    tree = repr_to_tree(rstring)
#    assert size == expected_size
#
#    traversal = inorder_iter(tree)
#    assert len(traversal) == expected_size
