"""
PYLC_HEAP
Heap implementation for LC in Python

Stefan Wong 2019
"""

from copy import copy

# TODO : a function that checks if an array has the heap property
def has_heap_property(array:list) -> bool:
    pass

def heap_left_child(idx:int) -> int:
    return 2 * (idx + 1) - 1

def heap_right_child(idx:int) -> int:
    return 2 * (idx + 1)



class HeapNode(object):
    """
    HeapNode
    A node in a heap
    """
    def __init__(self, key:int=0, val:int=0) -> None:
        self.key = key
        self.val = val

    def __repr__(self) -> str:
        return 'HeapNode'

    def __str__(self) -> str:
        return 'HeapNode [%d]: %d' % (self.key, self.val)

    def __eq__(self, that:'HeapNode') -> bool:
        return (self.key == that.key) and (self.val == that.val)

    def __lt__(self, that:'HeapNode') -> bool:
        return (self.key < that.key)

    def __lte__(self, that:'HeapNode') -> bool:
        return (self.key <= that.key)

    def __gt__(self, that:'HeapNode') -> bool:
        return (self.key > that.key)

    def __gte__(self, that:'HeapNode') -> bool:
        return (self.key >= that.key)



class Heap(object):
    def __init__(self, max_size:int=32) -> None:
        self.max_size:int = max_size
        self.cur_idx:int  = 0
        # Trying a version with a 'pre-allocated' array
        self.nodes:list   = [HeapNode(0, 0) for _ in range(self.max_size)]

    def __repr__(self) -> str:
        return 'Heap'

    def __str__(self) -> str:
        return "%s-%d" % (repr(self), self.max_size)

    def _left_child(self, idx:int) -> int:
        return 2 * (idx + 1) - 1

    def _right_child(self, idx:int) -> int:
        return 2 * (idx + 1)

    def _parent(self, idx:int) -> int:
        if idx <= 1:
            return 0

        return int(idx // 2)

    def _swap(self, a:HeapNode, b:HeapNode) -> tuple:
        a, b = b, a
        return a, b

    def _swap_copy(self, a:HeapNode, b:HeapNode) -> tuple:
        return (copy(b), copy(a))

    # Internal balancing functions
    # NOTE: for now this is a max heap
    def _bubble_up(self, idx:int) -> None:
        parent_idx = self._parent(idx)
        #if parent_idx == 0:
        #    return

        if self.nodes[parent_idx] < self.nodes[idx]:
            self.nodes[idx], self.nodes[parent_idx] = self.nodes[parent_idx], self.nodes[idx]
            self._bubble_up(parent_idx)


    def _bubble_down(self, idx:int) -> None:
        pass

    # TODO : all the balancing stuff
    def insertNode(self, node:HeapNode) -> None:
        if self.cur_idx < self.max_size:
            self.nodes[self.cur_idx] = node
            self._bubble_up(self.cur_idx)
            self.cur_idx += 1

    def get_array(self) -> list:
        return self.nodes[0 : self.cur_idx]



class MaxHeap(Heap):
    def __init__(self, max_size:int=32) -> None:
        super(MaxHeap, self).__init__(max_size=max_size)

    def __repr__(self) -> str:
        return 'MaxHeap'

    # Parents must be greater than children
    def _bubble_up(self, idx:int) -> None:
        parent_idx = self._parent(idx)
        # MaxHeap - parent should be greater
        if self.nodes[parent_idx] < self.nodes[idx]:
            self.nodes[idx], self.nodes[parent_idx] = self.nodes[parent_idx], self.nodes[idx]
            self._bubble_up(parent_idx)


class MinHeap(Heap):
    def __init__(self, max_size:int=32) -> None:
        super(MinHeap, self).__init__(max_size=max_size)

    def __repr__(self) -> str:
        return 'MinHeap'

    def _bubble_up(self, idx:int) -> None:
        parent_idx = self._parent(idx)
        # Min heap - parent should be lesser
        if self.nodes[parent_idx] > self.nodes[idx]:
            self.nodes[idx], self.nodes[parent_idx] = self.nodes[parent_idx], self.nodes[idx]
            self._bubble_up(parent_idx)
