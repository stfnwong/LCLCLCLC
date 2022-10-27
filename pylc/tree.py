"""
TREE
Implementations of various tree things

"""

from typing import List
from collections import deque


# The python3 tree class that seems to be used on leetcode now
class TreeNode:
    def __init__(self, val:int=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


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


# ==== Create new Binary Tree objects ==== #
def repr_to_tree(repr_string:str) -> BinaryTreeNode:
    """
    Convert a leetcode-style string repr into a tree
    """

    # Strip outside square brackets
    if repr_string[0] == "[" and repr_string[-1] == "]":
        repr_string = repr_string[1:-1]

    rtokens = repr_string.split(',')
    #node_q = list()

    if not rtokens:
        return BinaryTreeNode()

    # Create the root of the tree. The root node can't be null.
    root = BinaryTreeNode(int(rtokens[0]))
    node_q = deque([root])
    #node_q.append(root)
    check_left = True

    for token in rtokens[1:]:
        #cur_node = node_q[-1]

        # check the next token in the sequence
        null_node = (token == "None") or (token == "null")
        #null_node = token in ('none', 'None', 'Null', 'null')

        if null_node:
            check_left = ~check_left
        else:
            cur_node = node_q.pop()
            print(f"cur_token: {token}")

            new_node = BinaryTreeNode(int(token))
            # Attach this node to the current node 
            if check_left:
                cur_node.left = new_node
                node_q.append(cur_node.left)
            else:
                cur_node.right = new_node
                node_q.append(cur_node.right)
            check_left = ~check_left


    return root



def tree_size(root:BinaryTreeNode) -> int:
    """
    tree_size()
    Counts the number of non-empty nodes in a tree
    """

    size:int = 1

    if root is None:
        return 0
    if root.left is not None:
        size = size + tree_size(root.left)
    if root.right is not None:
        size = size + tree_size(root.right)

    return size


def tree_to_str(root:BinaryTreeNode) -> str:
    s = []

    if root is None:
        return "[]"




# ==== recursive traversal methods ==== #
def inorder(root:BinaryTreeNode, traversal:List[int]) -> List[int]:
    if root is not None:
        inorder(root.left, traversal)
        traversal.append(root.val)
        inorder(root.right, traversal)

        return
        #return res


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


