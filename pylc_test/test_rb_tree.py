"""
TEST_RB_TREE

Stefan Wong 2020
"""

import unittest
# Modules(s) under test
from pylc import rb_tree


class TestRedBlackNode(unittest.TestCase):
    # default node init
    def test_init_node(self) -> None:
        rb_node = rb_tree.RedBlackNode()

        self.assertEqual(True, rb_node.is_red())
        self.assertEqual(False, rb_node.is_black())
        # We expect the left and right pointers to be None
        self.assertEqual(None, rb_node.left)
        self.assertEqual(None, rb_node.right)
        # value defaults to None. For this test we expect ints
        self.assertEqual(None, rb_node.value)

        # if we get left or right keys, we expect null
        self.assertEqual(None, rb_node[0])
        self.assertEqual(None, rb_node[1])


class TestRedBlackTree(unittest.TestCase):
    def test_init_tree(self) -> None:
        pass



if __name__ == '__main__':
    unittest.main()
