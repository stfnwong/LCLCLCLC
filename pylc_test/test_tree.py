"""
TEST_TREE
Unit tests for tree structure

Stefan Wong 2019
"""

from pylc.tree import (
    repr_to_tree,
    tree_size,
    preorder,
    postorder,
    inorder,
    tree_level_traversal
)

rstring = "[1, 2, None, 3, 4, None, 5, 6, 7]"
expected_size = 7

def test_repr_to_tree():

    repr_inputs = [
        "[1, 2, 3]",
        "[1, None, 3]",
        "[1, 2, 3, None, 4, 5, 6]",
        "[1, None, 2, None, None, 4]"
    ]
    exp_traversals = [
        [[1], [2, 3]],
        [[1], [3]],
        [[1], [2, 3], [4, 5, 6]],
        [[1], [2], [4]]
    ]
    exp_sizes = [3, 2, 6, 3]

    for inp, exp_t, exp_size in zip(repr_inputs, exp_traversals, exp_sizes):
        tree = repr_to_tree(inp)
        traversal = tree_level_traversal(tree)
        assert exp_t == traversal
        assert len(tree) == exp_size


def test_tree_size():
    tree_repr = "[1, 2, null, 3]"
    expected_size = 3

    tree = repr_to_tree(tree_repr)
    print(tree_level_traversal(tree))
    out = tree_size(tree)

    assert out == expected_size



# ======== TRAVERSALS ======== #
def test_preorder_traversal():
    repr_strings = [
        "[1, 2, 3]",
        "[1, 2, None, 3, 4]",
        "[1, 2, 3, None, 4, 5]",
    ]
    expected_traversals = [
        [1, 2, 3],
        [1, 2, 3, 4],
        [1, 2, 4, 3, 5],
    ]

    for rstring, exp_traversal in zip(repr_strings, expected_traversals):
        tree = repr_to_tree(rstring)
        out_traversal = preorder(tree, [])
        assert len(out_traversal) == len(exp_traversal)
        assert out_traversal == exp_traversal


def test_postorder_traversal():
    repr_strings = [
        "[1, 2, 3]",
        "[1, 2, None, 3, 4]",
        "[1, 2, 3, None, 4, 5]",
    ]
    expected_traversals = [
        [2, 3, 1],
        [3, 4, 2, 1],
        [4, 2, 5, 3, 1],
    ]

    for rstring, exp_traversal in zip(repr_strings, expected_traversals):
        tree = repr_to_tree(rstring)
        out_traversal = postorder(tree, [])
        assert len(out_traversal) == len(exp_traversal)
        assert out_traversal == exp_traversal



def test_inorder_traversal():
    repr_strings = [
        "[1, 2, 3]",
        "[1, 2, None, 3, 4]",
        "[1, 2, 3, None, 4, 5]",
    ]
    expected_traversals = [
        [2, 1, 3],
        [3, 2, 4, 1],
        [2, 4, 1 , 5, 3],
    ]

    for rstring, exp_traversal in zip(repr_strings, expected_traversals):
        tree = repr_to_tree(rstring)
        out_traversal = inorder(tree, [])
        assert len(out_traversal) == len(exp_traversal)
        assert out_traversal == exp_traversal


