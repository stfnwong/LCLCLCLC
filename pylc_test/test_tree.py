"""
TEST_TREE
Unit tests for tree structure

Stefan Wong 2019
"""

from pylc.tree import (
    repr_to_tree,
    tree_size,
    inorder,
    inorder_iter,
    tree_level_traversal
)

rstring = "[1, 2, None, 3, 4, None, 5, 6, 7]"
expected_size = 7

def test_repr_to_tree():

    repr_inputs = [
        "[1, 2, 3]",
        "[1, None, 3]",
        "[1, 2, None, 3, 4, None, 5, 6, 7]",
        "[1, None, 2, None, 3, 4]"
    ]
    exp_sizes = [3, 2, 7, 4]
    exp_traversals = [
        [[1], [2, 3]],
        [[1], [3]],
        [[1], [2], [3, 4, 5], [6, 7]],
        [[1], [2], [3], [4]]
    ]
    from pudb import set_trace; set_trace()

    for inp, exp_size, exp_t in zip(repr_inputs, exp_sizes, exp_traversals):
        tree = repr_to_tree(inp)
        traversal = tree_level_traversal(tree)
        assert exp_t == traversal
        assert len(tree) == exp_size

    #tree          = repr_to_tree(rstring)
    #assert len(tree) == expected_size
    #size          = tree_size(tree)
    #assert size == expected_size


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
    print(tree_level_traversal(tree))
    out = tree_size(tree)

    assert out == expected_size



def test_level_order_traversal():

    tree = repr_to_tree(rstring)
    expected_traversal = [[1], [2], [3, 4, 5], [6, 7]]

    traversal = tree_level_traversal(tree)
    assert len(traversal) == len(expected_traversal)



#def test_inorder_iter_traverse():
#    tree = repr_to_tree(rstring)
#    assert size == expected_size
#
#    traversal = inorder_iter(tree)
#    assert len(traversal) == expected_size
