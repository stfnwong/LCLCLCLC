"""
PYLC_HEAP
Heap implementation for LC in Python

Stefan Wong 2019
"""

from copy import copy
# debug
from pudb import set_trace; set_trace()


# Check min heap property
def has_min_heap_property(array:list, idx:int=0) -> bool:
    if idx >= len(array):
        return True

    lval = heap_left_child(idx)
    rval = heap_right_child(idx)
    # bounds check on children
    if (lval >= len(array)) or (rval >= len(array)):
        return True

    if(array[lval] <= array[idx]) and (array[rval] <= array[idx]):
        return has_min_heap_property(array, idx+1)
    else:
        return False


# Check max heap property
def has_max_heap_property(array:list, idx:int=0) -> bool:
    if idx >= len(array):
        return True

    lval = heap_left_child(idx)
    rval = heap_right_child(idx)

    # bounds check on children
    if (lval >= len(array)) or (rval >= len(array)):
        return True

    if(array[lval] >= array[idx]) and (array[rval] >= array[idx]):
        return has_max_heap_property(array, idx+1)
    else:
        return False


# Zero index left and right functions
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
        if isinstance(that, HeapNode):
            return (self.key == that.key) and (self.val == that.val)
        else:
            return self.key == that

    def __lt__(self, that:'HeapNode') -> bool:
        if isinstance(that, HeapNode):
            return (self.key < that.key)
        else:
            return self.key < that

    def __le__(self, that:'HeapNode') -> bool:
        if isinstance(that, HeapNode):
            return (self.key <= that.key)
        else:
            return self.key <= that

    def __gt__(self, that:'HeapNode') -> bool:
        if isinstance(that, HeapNode):
            return (self.key > that.key)
        else:
            return self.key > that

    def __ge__(self, that:'HeapNode') -> bool:
        if isinstance(that, HeapNode):
            return (self.key >= that.key)
        else:
            return self.key >= that



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

    # NOTE : we need to account for the zero index, hence -1
    def _left_child(self, idx:int) -> int:
        return 2 * (idx + 1) - 1

    # NOTE: similarly here, we account for the zero-indexing
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
