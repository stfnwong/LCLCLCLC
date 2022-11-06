"""
HEAP
A binary heap

"""

from typing import List, Optional, Union

Numeric = Union[int, float]


# Get the children or parents of a zero-indexed heap array
def heap_left_child(idx:int) -> int:
    return 2 * idx + 1

def heap_right_child(idx:int) -> int:
    return 2 * idx + 2

def heap_parent(idx:int) -> int:
    return max(0, (idx-1) // 2)


# ---- Functions to test heap property ----
def has_min_heap_property(array:List[Numeric], idx:int=0) -> bool:
    if idx >= len(array):
        return True

    lval = heap_left_child(idx)
    rval = heap_right_child(idx)
    # bounds check on children
    if (lval >= len(array)) or (rval >= len(array)):
        return True

    if(array[lval] >= array[idx]) and (array[rval] >= array[idx]):
        return has_min_heap_property(array, idx+1)

    return False


def has_max_heap_property(array:List[Numeric], idx:int=0) -> bool:
    if idx >= len(array):
        return True

    lval = heap_left_child(idx)
    rval = heap_right_child(idx)
    # bounds check on children
    if (lval >= len(array)) or (rval >= len(array)):
        return True

    if(array[lval] <= array[idx]) and (array[rval] <= array[idx]):
        return has_max_heap_property(array, idx+1)

    return False


# New (simpler) heap class
class Heap:
    def __init__(self, heap:Optional[List[Numeric]]=None) -> None:
        self.heap = []
        if heap is not None:
            for elem in heap:
                self.insert(elem)

    def __repr__(self) -> str:
        return 'Heap(%s)' % str(self.heap)

    def __str__(self) -> str:
        return self.__repr__()

    def __len__(self) -> int:
        return len(self.heap)

    def _compare(self, parent_idx:Numeric, child_idx:Numeric) -> bool:
        raise NotImplementedError('_compare() should be implementd in derived class')

    def _swap(self, a_idx:int, b_idx:int) -> None:
        self.heap[a_idx], self.heap[b_idx] = self.heap[b_idx], self.heap[a_idx]

    def heapify_up(self, idx:int) -> None:
        # heapify from the leaf up
        parent_idx = heap_parent(idx)
        # TODO: debug only, remove
        #print(f"{__name__}:{self.__class__}, heap: {self.heap}")
        print(f"{__name__}:{self.__class__}, idx: {idx}, parent_idx: {parent_idx}")

        if self._compare(self.heap[parent_idx], self.heap[idx]):
            self._swap(parent_idx, idx)
            self.heapify_up(parent_idx)

    def heapify_down(self, idx:int) -> None:
        # heapify from the root down
        raise NotImplemented('_heapify_down() should be implemented in derived class')

    def get_root(self) -> Union[None, Numeric]:
        if not self.heap:
            return None
        return self.heap[0]

    def insert(self, element:Numeric) -> None:
        self.heap.append(element)
        self.heapify_up(len(self.heap) - 1)


class MinHeap(Heap):
    """
    MinHeap specialization - OOP style
    """
    def __init__(self, heap:list=None) -> None:
        super(MinHeap, self).__init__(heap)

    def __repr__(self) -> str:
        return 'MinHeap(%s)' % str(self.heap)

    def _compare(self, parent:int, child:int) -> bool:
        return parent > child

    def heapify_down(self, idx:int) -> None:
        # Heapify from the root down
        lchild = heap_left_child(idx)
        rchild = heap_right_child(idx)

        # bounds check children
        if(lchild >= len(self.heap)) or (rchild >= len(self.heap)):
            return

        if self.heap[lchild] < self.heap[idx]:
            smallest_idx = lchild
        else:
            smallest_idx = idx
        if self.heap[rchild] < self.heap[smallest_idx]:
            smallest_idx = rchild

        if smallest_idx != idx:
            self._swap(idx, smallest_idx)
            self.heapify_down(smallest_idx)

    def remove_max(self) -> int:
        last_elem = self.heap.pop()
        if not self.heap:
            return last_elem

        elem = self.heap[0]
        self.heap[0] = last_elem
        self.heapify_down(0)

        return elem


class MaxHeap(Heap):
    """
    MaxHeap specialization - OOP style
    """
    def __init__(self, heap:Optional[List[Numeric]]=None) -> None:
        super(MaxHeap, self).__init__(heap)

    def __repr__(self) -> str:
        return 'MaxHeap(%s)' % str(self.heap)

    def _compare(self, parent:int, child:int) -> bool:
        return parent < child

    def heapify_down(self, idx:int) -> None:
        # Heapify from the root down
        lchild = heap_left_child(idx)
        rchild = heap_right_child(idx)

        # bounds check children
        if(lchild >= len(self.heap)) or (rchild >= len(self.heap)):
            return

        if self.heap[lchild] > self.heap[idx]:
            largest_idx = lchild
        else:
            largest_idx = idx
        if self.heap[rchild] > self.heap[largest_idx]:
            largest_idx = rchild

        if largest_idx != idx:
            self._swap(idx, largest_idx)
            self.heapify_down(largest_idx)

    def remove_min(self) -> int:
        last_elem = self.heap.pop()
        if not self.heap:
            return last_elem

        elem = self.heap[0]
        self.heap[0] = last_elem
        self.heapify_down(0)

        return elem
