"""
TREE
Implementations of various tree things

Stefan Wong 2019
"""

# debug
#from pudb import set_trace; set_trace()


class BinaryTreeNode(object):
    def __init__(self,
            val=None,
            left:'BinaryTreeNode'=None,
            right:'BinaryTreeNode'=None) -> None:
        self.left  :'BinaryTreeNode' = left
        self.right :'BinaryTreeNode' = right
        self.val                     = val

    def __repr__(self) -> str:
        return 'BinaryTreeNode'

    def __str__(self) -> str:
        return '%s [%s]' % (repr(self), str(self.val))


# ==== Create new Binary Tree objects ==== #
def repr_to_tree(rstring:str) -> BinaryTreeNode:
    rtokens = rstring.split(',')

    node_q = list()
    root = None
    check_left = True
    for n, token in enumerate(rtokens):
        # Strip any leading or trailing square brackets
        if n == 0:
            if token[0] == '[':
                token = token[1:]

            # If this is the first node, assign here and
            # then skip to the next iteration
            # NOTE : for now the values in the tree are ints
            root = BinaryTreeNode(val = int(token))
            continue

        if n == len(rtokens)-1:
            if token[-1] == ']':
                token = token[0 : len(token)-1]

        # Assign values to the correct node pointers
        node = None
        null_node = (token == 'None') or (token == 'null')

        if not null_node:
            node = BinaryTreeNode(val = int(token))
            node_q.append(node)

        # Assign the left node
        if check_left:
            cur_node = node_q.pop(0)
            cur_node.left = node
            check_left = False

        # Assign the right node
        if not check_left:
            cur_node.right = node
            check_left = True


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


#def tree_to_str(root:BinaryTreeNode) -> str:
#    s = []
#
#    if root is None:
#        return "[]"



# ==== traversal methods ==== #
def inorder(root:BinaryTreeNode, traversal:list) -> list:
    if root is not None:
        inorder(root.left, traversal)
        traversal.append(root.val)
        inorder(root.right, traversal)

        return res


# ==== iterative traversal methods ==== #
def inorder_iter(root:BinaryTreeNode) -> list:
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



# More complex traversals
def spiral_order(root:BinaryTreeNode) -> list:
    pass
