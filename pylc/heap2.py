"""
HEAP2
Another simpler heap (without a Node) to test heap properties

Stefan Wong 2020
"""

from copy import copy
from typing import Union

def heap_left_child(idx:int) -> int:
    return 2 * idx + 1

def heap_right_child(idx:int) -> int:
    return 2 * idx + 2

def heap_parent(idx:int) -> int:
    return max(0, (idx-1) // 2)




# New (simpler) heap class
class Heap:
    def __init__(self, heap:list=None) -> None:
        if heap is None:
            self.heap = []
        else:
            self.heap = heap
        # Can add custom compare later, but for now compare
        # is fixed as lt (so MinHeap)

    def __repr__(self) -> str:
        return 'Heap(%s)' % str(self.heap)

    def __str__(self) -> str:
        return self.__repr__()

    def __len__(self) -> int:
        return len(self.heap)

    # heapify from the bottom to the root
    def _heapify_up(self, idx:int) -> None:
        child_idx = idx
        while child_idx > 0:
            parent_idx = heap_parent(child_idx)
            if self.heap[parent_idx] >= self.heap[child_idx]:
                return
            # swap
            self.heap[parent_idx], self.heap[child_idx] = self.heap[child_idx], self.heap[parent_idx]
            child_idx = parent_idx

    # heapify from the root to the bottom
    def _heapify_down(self, idx:int) -> None:
        if len(self.heap) == 1:
            return
        parent_idx = heap_parent(idx)

        while parent_idx >= len(self.heap):
            child_idx = heap_left_child(parent_idx)
            if ((child_idx + 1) < len(self.heap)) and (self.heap[child_idx + 1] >= self.heap[child_idx]):
                child_idx += 1
            if self.heap[parent_idx] >= self.heap[child_idx]:
                return
            # swap
            self.heap[parent_idx], self.heap[child_idx] = self.heap[child_idx], self.heap[parent_idx]
            parent_idx = child_idx

    def get_min(self) -> Union[None, int]:
        if not self.heap:
            return None
        return self.heap[0]

    def insert(self, element:int) -> None:
        self.heap.append(element)
        self._heapify_up(len(self.heap) - 1)

    # NOTE: for now we only deal with ints, but if this
    # became a generic heap then we need an Any here or something
    def remove_min(self) -> int:
        last_elem = self.heap.pop()
        if not self.heap:
            return last_elem

        elem = self.heap[0]
        self.heap[0] = last_elem
        self._heapify_down(0)

        return elem
