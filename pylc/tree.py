"""
TREE
Implementations of various tree things

"""

from typing import List, Optional, Union
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
        return str(self.val)

        #s = []
        #q = deque([self])

        #while q:
        #    cur_node = q.pop()
        #    if cur_node.val:
        #        s.append(str(cur_node.val))
        #    else:
        #        s.append("null")

        #    if cur_node.left:
        #        q.append(cur_node.left)
        #    if cur_node.right:
        #        q.append(cur_node.right)

        #return ",".join(s)

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


# This is the Node for question 116
# https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
class RPTreeNode:
    def __init__(
        self,
        val:int=0,
        left:Optional["RPTreeNode"]=None,
        right:Optional["RPTreeNode"]=None,
        next_node:Optional["RPTreeNode"]=None,
        other_tree:Optional[BinaryTreeNode]=None,
    ):
        if other_tree:
            self._fill_from_tree(other_tree)
        else:
            self.val = val
            self.left = left
            self.right = right
            self.next_node = next_node

    def _fill_from_tree(self, root:BinaryTreeNode) -> None:
        # traverse in level order and create a new tree that follows the
        # structure of the existing tree
        if not root:
            return

        src_q = [root]

        while src_q:
            num_nodes = len(src_q)
            for _ in range(num_nodes):
                src_cur_node = src_q.pop(0)

                if src_cur_node.left:
                    src_q.append(src_cur_node.left)
                if src_cur_node.right:
                    src_q.append(src_cur_node.right)



# Type for any tree
TreeType = Union[BinaryTreeNode, RPTreeNode, TreeNode]

def compare_tree_rec(a:Optional[BinaryTreeNode], b:Optional[BinaryTreeNode]) -> bool:
    """
    Recursively compare two trees for equality.
    """

    if a is None and b is None:
        return True
    if (a is None and b is not None) or (a is not None and b is None):
        return False
    if a.val != b.val:
        return False

    return compare_tree_rec(a.left, b.left) and compare_tree_rec(a.right, b.right)


def copy_tree_rec(src_root:BinaryTreeNode) -> BinaryTreeNode:
    """
    Recursively copy a tree.
    """

    if not src_root:
        return None
    else:
        new_node = BinaryTreeNode(src_root.val)
        new_node.left = copy_tree_rec(src_root.left)
        new_node.right = copy_tree_rec(src_root.right)
        return new_node


def copy_tree_iter(src_root:BinaryTreeNode) -> Optional[BinaryTreeNode]:
    """
    Copy a tree iteratively.
    """

    if not src_root:
        return src_root

    src_node_q = [src_root]
    dst_node_q = []

    while src_node_q:
        num_src_nodes = len(src_node_q)
        for _ in range(num_src_nodes):
            cur_src_node = src_node_q.pop(0)
            if cur_src_node:
                cur_dst_node = BinaryTreeNode(cur_src_node.val)

                if cur_src_node.left:
                    src_node_q.append(cur_src_node.left)
                if cur_src_node.right:
                    src_node_q.append(cur_src_node.right)





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


def tree_height(tree:Optional[BinaryTreeNode]) -> int:
    """
    Iteratively finds the height of some Binary Tree
    """

    if not tree:
        return 0

    height = 0
    q = [tree]

    while q:
        level = len(q)          # number of nodes at this level - bounded by O(2^l)
        for _ in range(level):
            cur_node = q.pop(0)     # queue reduces by one here

            if cur_node:
                if cur_node.left:
                    q.append(cur_node.left)
                if cur_node.right:
                    q.append(cur_node.right)

        height += 1

    return height



def tree_level_traversal(root:Optional[BinaryTreeNode]) -> List[List[int]]:
    """
    Return a level-order traversal of a binary tree. The traversal is represented
    as a List where each Element is a list of the nodes on a given level.
    """

    if not root:
        return []

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
def repr_to_tree(repr_string:str) -> Optional[BinaryTreeNode]:
    """
    Convert a leetcode style tree repr string into a BinaryTreeNode. The repr string
    is given as the level-order traversal of the tree.
    """

    is_null_token = lambda token: token in ("None", "null", "")
    strip_whitespace = lambda token: "".join(token.split())

    # Strip outside square brackets
    if repr_string[0] == "[" and repr_string[-1] == "]":
        repr_string = repr_string[1:-1]

    rtokens = repr_string.split(',')
    if len(rtokens) == 1 and rtokens[0] == "":
        return None

    # Create the root of the tree. The root node can't be null.
    root = None
    node_q = []
    next_is_left = False
    is_root = True

    for token in rtokens:
        if len(node_q) > 0:
            cur_node = node_q.pop(0)
            next_is_left = ~next_is_left
            is_root = False

        null_node = is_null_token(strip_whitespace(token))

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


def tree_to_repr(root:Optional[TreeType], null_str:str="None") -> str:
    """
    Convert a tree to its corresponding leet-code style repr
    """

    # TODO: traverse the tree in level order, appending "null" to the string
    # when there are empty leaf nodes
    if not root:
        return "[]"

    node_strings = []
    q = [root]

    while q:
        num_nodes = len(q)
        for _  in range(num_nodes):
            cur_node = q.pop(0)
            if cur_node:
                node_strings.append(str(cur_node.val))
                q.append(cur_node.left)
                q.append(cur_node.right)
                #if cur_node.left:
                #    q.append(cur_node.left)
                #if cur_node.right:
                #    q.append(cur_node.right)
            else:
                node_strings.append(null_str)

    # Shit implementation - strip trailing None's
    idx = len(node_strings)-1
    while node_strings[idx] == null_str:
        node_strings.pop(idx)
        idx = idx - 1

    return "[" + ", ".join(node_strings) + "]"



# ==== recursive traversal methods ==== #
def preorder_rec(root:Optional[BinaryTreeNode], traversal:List[int]) -> List[int]:
    """
    Recursively perform preorder traversal
    """

    if root is not None:
        traversal.append(root.val)
        preorder_rec(root.left, traversal)
        preorder_rec(root.right, traversal)

    return traversal


def postorder_rec(root:Optional[BinaryTreeNode], traversal:List[int]) -> List[int]:
    """
    Recursively perform postorder traversal
    """

    if root is not None:
        postorder_rec(root.left, traversal)
        postorder_rec(root.right, traversal)
        traversal.append(root.val)

    return traversal


def inorder_rec(root:Optional[BinaryTreeNode], traversal:List[int]) -> List[int]:
    """
    Recursively perform inorder traversal
    """

    if root is not None:
        inorder_rec(root.left, traversal)
        traversal.append(root.val)
        inorder_rec(root.right, traversal)

    return traversal


def preorder_iter(root:Optional[BinaryTreeNode], traversal:List[int]) -> List[int]:
    if not root:
        return []

    stack = [root]
    while stack:
        cur_node = stack.pop()
        traversal.append(cur_node.val)
        if cur_node.right:
            stack.append(cur_node.right)
        if cur_node.left:
            stack.append(cur_node.left)

    return traversal


def levelorder_iter(root:Optional[BinaryTreeNode], traversal:List[int]) -> List[int]:
    q = deque([root])

    while q:
        cur_node = q.pop()
        if cur_node:
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


