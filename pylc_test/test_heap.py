"""
HEAP2_TEST
Heap2 unit tests. This is just a heap with less stuff attached to it

"""

import random
import copy
import unittest
# unit under test
from pylc import heap      # Once this is alright, factor back into main heap


heap_inp_array_1 = [1, 2, 7, 3, 17, 36, 25, 19, 100]
heap_inp_array_2 = [1, 25, 36, 100, 7, 17, 19, 2, 3]

# ======== MAX HEAP ======== #
def test_max_heap_init():
    test_heap = heap.MaxHeap()
    assert len(test_heap) == 0


def test_max_heap_init_from_list():
    test_heap = heap.MaxHeap(heap_inp_array_1)
    assert heap.has_max_heap_property(test_heap.heap)


def test_create_max_heap_by_insertion():
    test_heap = heap.MaxHeap()
    arrays = [heap_inp_array_1, heap_inp_array_2]

    for array in arrays:
        test_heap.clear()
        print(f"Adding {len(array)} elements to {test_heap.__class__}")
        for n, k in enumerate(array):
            test_heap.insert(k)
            print(n, test_heap)
            assert len(test_heap) == n+1
            assert heap.has_max_heap_property(test_heap.heap)

    print(f"Created test heap: {test_heap}")


def test_max_heap_remove_min():
    test_heap = heap.MaxHeap()

    for item in heap_inp_array_1:
        test_heap.insert(item)

    expected_min_seq = [100, 36, 25, 19]
    for exp in expected_min_seq:
        elem = test_heap.remove_min()
        assert elem == exp


# ======== MIN HEAP ======== #
def test_min_heap_init():
    test_heap = heap.MinHeap()
    assert len(test_heap) == 0

def test_min_heap_init_from_list():
    test_heap = heap.MinHeap(heap_inp_array_1)
    assert heap.has_min_heap_property(test_heap.heap)

def test_create_min_heap_by_insertion():
    test_heap = heap.MinHeap()
    arrays = [heap_inp_array_1, heap_inp_array_2]

    for array in arrays:
        test_heap.clear()
        print(f"Adding {len(array)} elements to {test_heap.__class__}")
        for n, k in enumerate(array):
            test_heap.insert(k)
            print(n, test_heap)
            assert len(test_heap) == n+1
            assert heap.has_min_heap_property(test_heap.heap)

    print(f"Created test heap: {test_heap}")
