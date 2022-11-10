"""
HEAP2_TEST
Heap2 unit tests. This is just a heap with less stuff attached to it

"""

from copy import copy

# unit under test
from pylc import heap      # Once this is alright, factor back into main heap


heap_inp_array_1 = [1, 2, 7, 3, 17, 36, 25, 19, 100]
heap_inp_array_2 = [1, 25, 36, 100, 7, 17, 19, 2, 3]
#heap_inp_array_3 = [16, 9, 10, 4, 1, 3, 2, 14, 8, 7]
#heap_inp_array_3 = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
heap_inp_array_3 = [20, 30, 4, 3, 19, 18, 16, 2, 1, 9]
exp_min_heap_3 = [1, 2, 4, 3, 9, 18, 16, 30, 20, 19]
exp_max_heap_3 = [30, 20, 18, 3, 19, 4, 16, 2, 1, 9]

# These are for testing the methods that heapify arrays directly
heapify_inp_array = [16, 4, 10, 14, 7, 9, 3, 2, 8 ,1]
max_heapify_exp_array = [16, 14, 10, 8, 7, 9, 3, 2, 4, 1]
min_heapify_exp_array = []



# ======== HEAP PROPERTIES ON ARRAYS ======== #
def test_max_heapify_on_array():
    inp_array = copy(heapify_inp_array)  # Need a copy since we modify in-place
    # in the book we start at i = 2, but this is in 1-indexed array so should be 1 here
    heap.max_heapify(inp_array, 1)

    for inp, exp, in zip(inp_array, max_heapify_exp_array):
        assert inp == exp

    # This will also pass
    assert heap.has_max_heap_property(inp_array)


def test_has_max_heap_property_iter():
    inp_array = copy(heapify_inp_array)  # Need a copy since we modify in-place
    # in the book we start at i = 2, but this is in 1-indexed array so should be 1 here
    heap.max_heapify(inp_array, 1)

    for inp, exp, in zip(inp_array, max_heapify_exp_array):
        assert inp == exp

    # This will also pass
    assert heap.has_heap_property_iter(inp_array, compare_func=heap.comp_lt)


def test_has_min_heap_property_iter():
    inp_array = copy(heap_inp_array_3)  # Need a copy since we modify in-place
    # in the book we start at i = 2, but this is in 1-indexed array so should be 1 here
    print(f"Original array: {inp_array}")
    heap.build_min_heap(inp_array)
    print(f"Min heaped array: {inp_array}")

    for inp, exp, in zip(inp_array, exp_min_heap_3):
        assert inp == exp

    # This will also pass
    assert heap.has_heap_property_iter(inp_array, compare_func=heap.comp_gt)


def test_has_max_heap_property_iter():
    inp_array = copy(heap_inp_array_3)  # Need a copy since we modify in-place
    # in the book we start at i = 2, but this is in 1-indexed array so should be 1 here
    print(f"Original array: {inp_array}")
    heap.build_max_heap(inp_array)
    print(f"Max heaped array: {inp_array}")

    for inp, exp, in zip(inp_array, exp_max_heap_3):
        assert inp == exp

    # This will also pass
    assert heap.has_heap_property_iter(inp_array, compare_func=heap.comp_lt)




#def test_min_heapify_on_array():
#    inp_array = copy(heapify_inp_array)
#    assert not heap.has_min_heap_property(inp_array)
#    heap.min_heapify(inp_array, 0)
#
#    assert heap.has_min_heap_property(inp_array)
#

def test_build_max_heap():
    inp_array = copy(heap_inp_array_2)  # Need a copy since we modify in-place
    print(f"Original array : {inp_array}, max heap: {heap.has_max_heap_property(inp_array)}")
    heap.build_max_heap(inp_array)
    print(f"Max heap       : {inp_array}")
    assert heap.has_max_heap_property(inp_array)


def test_build_min_heap():
    inp_array = copy(heap_inp_array_2)  # Need a copy since we modify in-place
    print(f"Original array : {inp_array}, min heap: {heap.has_min_heap_property(inp_array)}")
    heap.build_min_heap(inp_array)
    print(f"Max heap       : {inp_array}")
    assert heap.has_min_heap_property(inp_array)



# ======== MAX HEAP ======== #
def test_max_heap_init():
    test_heap = heap.MaxHeap()
    assert len(test_heap) == 0
    assert test_heap.height() == 0


def test_max_heap_init_from_list():
    inp_array = copy(heap_inp_array_1)
    test_heap = heap.MaxHeap(inp_array)
    assert heap.has_max_heap_property(test_heap.heap)


def test_create_max_heap_by_insertion():
    test_heap = heap.MaxHeap()
    arrays = [copy(heap_inp_array_1), copy(heap_inp_array_2)]

    for array in arrays:
        test_heap.clear()
        print(f"Adding {len(array)} elements to {test_heap.__class__}")
        for n, k in enumerate(array):
            test_heap.insert(k)
            print(n, test_heap)
            assert len(test_heap) == n+1
            assert heap.has_max_heap_property(test_heap.heap)

    print(f"Created test heap: {test_heap}")


def test_max_heap_height():
    inp_array = copy(heap_inp_array_1)

    test_heap = heap.MaxHeap()
    for elem in inp_array:
        test_heap.insert(elem)

    assert test_heap.height() == 4



def test_max_heap_remove_min():
    test_heap = heap.MaxHeap()
    inp_array = copy(heap_inp_array_1)

    for item in inp_array:
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
    inp_array = copy(heap_inp_array_1)
    test_heap = heap.MinHeap(inp_array)
    assert heap.has_min_heap_property(test_heap.heap)


def test_create_min_heap_by_insertion():
    test_heap = heap.MinHeap()
    arrays = [copy(heap_inp_array_1), copy(heap_inp_array_2)]

    for array in arrays:
        test_heap.clear()
        print(f"Adding {len(array)} elements to {test_heap.__class__}")
        for n, k in enumerate(array):
            test_heap.insert(k)
            print(n, test_heap)
            assert len(test_heap) == n+1
            assert heap.has_min_heap_property(test_heap.heap)

    print(f"Created test heap: {test_heap}")
