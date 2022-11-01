"""
TREE
Implementations of various tree things

"""

from typing import List, Optional
from collections import deque


# The python3 tree class that seems to be used on leetcode now
class TreeNode:
    def __init__(self, val:int=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right



#class NTree:
#    def __init__(self, val:int=0, c:Optional[List[NTree]]=None):
#        self.val = val
#        self.children = c
#


# Some class I probably made up similar to the leetcode one
class BinaryTreeNode:
    def __init__(
        self,
        val=None,
        left=None,
        right=None
    ) -> None:
        self.left = left
        self.right = right
        self.val:int = val

    def __repr__(self) -> str:
        s = []
        q = deque([self])

        while q:
            cur_node = q.pop()
            if cur_node.val:
                s.append(str(cur_node.val))
            else:
                s.append("null")

            if cur_node.left:
                q.append(cur_node.left)
            if cur_node.right:
                q.append(cur_node.right)

        return ",".join(s)

    def __str__(self) -> str:
        return self.__repr__()

    def __len__(self) -> int:
        """
        The len() for this object is the total number of nodes
        """

        n = 0
        stack = []
        cur_node = self

        while len(stack) > 0 or cur_node is not None:
            if cur_node is not None:
                n += 1
                stack.append(cur_node)
                cur_node = cur_node.left
            else:
                prev_node = stack.pop(-1)
                cur_node = prev_node.right

        return n



def tree_size(tree:Optional[BinaryTreeNode]) -> int:
    """
    Return the number of nodes in a binary tree
    """

    n = 0
    stack = []
    cur_node = tree

    while len(stack) > 0 or cur_node is not None:
        if cur_node is not None:
            n = n + 1
            stack.append(cur_node)
            cur_node = cur_node.left
        else:
            prev_node = stack.pop(-1)
            cur_node = prev_node.right

    return n



def tree_level_traversal(root:Optional[BinaryTreeNode]) -> List[List[int]]:
    """
    Return a level-order traversal of a binary tree. The traversal is represented
    as a List where each Element is a list of the nodes on a given level.
    """

    traversal = []
    q = []
    q.append(root)

    while len(q) > 0:
        level = []

        for _ in range(len(q)):
            cur_node = q.pop(0)
            level.append(cur_node.val)

            if cur_node.left is not None:
                q.append(cur_node.left)
            if cur_node.right is not None:
                q.append(cur_node.right)

        traversal.append(level)

    return traversal


# ==== Create new Binary Tree objects ==== #
def repr_to_tree(repr_string:str) -> BinaryTreeNode:
    """
    Convert a leetcode style tree repr string into a BinaryTreeNode. The repr string
    is given as the level-order traversal of the tree.
    """

    # Strip outside square brackets
    if repr_string[0] == "[" and repr_string[-1] == "]":
        repr_string = repr_string[1:-1]

    rtokens = repr_string.split(',')

    if not rtokens:
        return BinaryTreeNode()

    # Create the root of the tree. The root node can't be null.
    root = BinaryTreeNode(int(rtokens[0]))
    node_q = []
    next_is_left = False
    is_root = True

    for token in rtokens:
        if len(node_q) > 0:
            cur_node = node_q.pop(0)
            next_is_left = ~next_is_left
            is_root = False

        token = "".join(token.split())      # This actually seems quite cumbersome for what I want to do
        null_node = (token == "None") or (token == "null")

        if not null_node:
            new_node = BinaryTreeNode(int(token))
            node_q.append(new_node)
            node_q.append(new_node)
            if is_root:
                root = new_node
            else:
                if next_is_left:
                    cur_node.left = new_node
                else:
                    cur_node.right = new_node

    return root



# ==== recursive traversal methods ==== #
def inorder(root:BinaryTreeNode, traversal:List[int]) -> List[int]:
    if root is not None:
        inorder(root.left, traversal)
        traversal.append(root.val)
        inorder(root.right, traversal)

    return traversal


def levelorder(root:BinaryTreeNode, traversal:List[int]) -> List[int]:
    q = deque([root])

    while q:
        cur_node = q.pop()
        traversal.append(cur_node.val)
        if cur_node.left:
            q.append(cur_node.left)
        if cur_node.right:
            q.append(cur_node.right)

    return traversal




# ==== iterative traversal methods ==== #
def inorder_iter(root:BinaryTreeNode, traversal:List[int]) -> List[int]:
    traversal = []
    stack = []

    while True:
        while root:
            stack.append(root)
            root = root.left
        if not stack:
            return stack
        node = stack.pop()
        traversal.append(node.val)
        root = node.right

    return traversal


def tree_bfs(root: BinaryTreeNode, traversal:List[int]) -> List[int]:
    q = deque([root])

    while q:
        for elem in q:
            cur_node = q.pop()
            traversal.append(cur_node.val)
            if cur_node.left:
                q.append(cur_node.left)
            if cur_node.right:
                q.append(cur_node.right)


