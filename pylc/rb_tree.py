"""
RB_TREE
Implementation of an RBTree

Stefan Wong 2020
"""


class RedBlackNode:
    def __init__(self, key:int=None, value:int=None) -> None:
        self.key:int   = key
        self.value:int = value
        self.red:bool  = True            # this is either red or black, so bool is sufficient
        self.left:'RedBlackNode' = None
        self.right:'RedBlackNode' = None

    def __repr__(self) -> str:
        return 'RedBlackNode'

    def __getitem__(self, key:int) -> 'RedBlackNode':
        if key == 0:
            return self.left
        else:
            return self.right

    # NOTE: type hint for value should be 'RedBlackNode'
    def __setitem__(self, key:int, value) -> 'RedBlackNode':
        if key == 0:
            self.left = value
        else:
            self.right = value

    def is_red(self) -> bool:
        return True if self.red else False

    def is_black(self) -> bool:
        return False if self.red else True



class RedBlackTree:
    """
    RedBlackTree

    Implementation of the actual RBTree. Most of the complicated
    stuff for this tree is in the insertion and deletion mechanism
    (in order to preserve the red/black property).
    """
    def __init__(self) -> None:
        pass

    def __repr__(self) -> None:
        return 'RedBlackTree'
