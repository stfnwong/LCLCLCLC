"""
TEST_TREE
Unit tests for tree structure

Stefan Wong 2019
"""

from pylc.tree import (
    repr_to_tree,
    tree_to_repr,
    compare_tree_rec,
    copy_tree_rec,
    tree_size,
    tree_height,
    preorder_rec,
    postorder_rec,
    inorder_rec,
    tree_level_traversal
)

rstring = "[1, 2, None, 3, 4, None, 5, 6, 7]"
expected_size = 7


def test_repr_to_tree():

    repr_inputs = [
        "[]",
        "[1, 2, 3]",
        "[1, None, 3]",
        "[1, 2, 3, None, 4, 5, 6]",
        "[1, None, 2, None, None, 4]",
    ]
    exp_traversals = [
        [],
        [[1], [2, 3]],
        [[1], [3]],
        [[1], [2, 3], [4, 5, 6]],
        [[1], [2], [4]],
    ]
    exp_sizes = [0, 3, 2, 6, 3]

    for inp, exp_t, exp_size in zip(repr_inputs, exp_traversals, exp_sizes):
        tree = repr_to_tree(inp)
        traversal = tree_level_traversal(tree)
        assert exp_t == traversal
        if tree:
            assert len(tree) == exp_size


#def test_tree_to_repr():
#    repr_inputs = [
#        #"[1, None, 3]",
#        #"[1, 2, 3]",
#        #"[1, 2, 3, None, 4, 5, 6]",
#        "[1, None, 2, None, None, 4]",
#    ]
#
#    for inp in repr_inputs:
#        print(f"Input repr: {inp}")
#        tree = repr_to_tree(inp)
#        out_repr = tree_to_repr(tree)
#        print(f"Output repr: {out_repr}")
#        assert out_repr == inp


def test_compare_tree_rec():
    repr_inputs = [
        "[1, 2, 3]",
        "[1, None, 3]",
        "[1, 2, 3, None, 4, 5, 6]",
        "[1, None, 2, None, None, 4]",
    ]

    for inp in repr_inputs:
        print(f"Comparing trees with repr {inp}", end=" ")
        tree_a = repr_to_tree(inp)
        tree_b = repr_to_tree(inp)
        assert id(tree_a) != id(tree_b)   # just to make sure these are distinct objects
        assert compare_tree_rec(tree_a, tree_b)
        print("....OK")

    # Also test that the empty case
    assert compare_tree_rec(repr_to_tree("[]"), repr_to_tree("[]"))


def test_copy_tree_rec():
    repr_inputs = [
        "[]",
        "[1, 2, 3]",
        "[1, None, 3]",
        "[1, 2, 3, None, 4, 5, 6]",
        "[1, None, 2, None, None, 4]",
    ]

    for inp in repr_inputs:
        src_tree = repr_to_tree(inp)
        dst_tree = copy_tree_rec(src_tree)
        assert compare_tree_rec(src_tree, dst_tree)



def test_tree_size():
    tree_repr = "[1, 2, null, 3]"
    expected_size = 3

    tree = repr_to_tree(tree_repr)
    print(tree_level_traversal(tree))
    out = tree_size(tree)

    assert out == expected_size



def test_tree_height():
    repr_strings = [
        "[]",
        "[1, 2, 3]",
        "[1, 2, None, 3, 4]",
        "[1, 2, 3, None, 4, 5]",
    ]
    expected_heights = [0,2, 3, 3]

    for rstring, exp_height in zip(repr_strings, expected_heights):
        tree = repr_to_tree(rstring)
        height = tree_height(tree)
        assert height == exp_height


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
        out_traversal = preorder_rec(tree, [])
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
        out_traversal = postorder_rec(tree, [])
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
        out_traversal = inorder_rec(tree, [])
        assert len(out_traversal) == len(exp_traversal)
        assert out_traversal == exp_traversal


