"""
HEAP2_TEST
Heap2 unit tests. This is just a heap with less stuff attached to it

Stefan Wong 2020
"""

import random
import copy
import unittest
# unit under test
from pylc import heap      # Once this is alright, factor back into main heap

# Debug
#from pudb import set_trace; set_trace()


class TestMaxHeap2(unittest.TestCase):
    def setUp(self) -> None:
        self.input_keys_1 = [1, 2, 3, 7, 17, 19, 25, 36, 100]
        self.input_keys_2 = [1, 2, 7, 3, 17, 36, 25, 19, 100]

    def test_max_heap_init(self) -> None:
        # grab a heap
        test_heap = heap.MaxHeap()
        self.assertEqual([], test_heap.heap)
        self.assertEqual(0, len(test_heap))

        # what happens as we add elements from self.input_keys?
        print('Adding keys %s to heap...' % str(self.input_keys_1))
        for n, k in enumerate(self.input_keys_1):
            test_heap.insert(k)
            print(n, test_heap)
            self.assertEqual(len(test_heap), n+1)
            self.assertEqual(True, heap.has_max_heap_property(test_heap.heap))

        print(test_heap)
        # Ensure that this is a max heap
        self.assertEqual(False, heap.has_min_heap_property(test_heap.heap))
        self.assertEqual(True, heap.has_max_heap_property(test_heap.heap))
        self.assertEqual(len(self.input_keys_1), len(test_heap))

    def test_max_heap_remove_min(self) -> None:
        # NOTE: remember that this is a MaxHeap at the moment
        test_heap = heap.MaxHeap()
        self.assertEqual([], test_heap.heap)
        self.assertEqual(0, len(test_heap))

        # what happens as we add elements from self.input_keys?
        print('Adding keys %s to heap...' % str(self.input_keys_1))
        for n, k in enumerate(self.input_keys_1):
            test_heap.insert(k)
            print(n, test_heap)
            self.assertEqual(len(test_heap), n+1)

        self.assertEqual(True, heap.has_max_heap_property(test_heap.heap))
        self.assertEqual(False, heap.has_min_heap_property(test_heap.heap))

        heap_min = test_heap.remove_min()
        self.assertEqual(100, heap_min)
        print('After removal : ' , test_heap)
        self.assertEqual(True, heap.has_max_heap_property(test_heap.heap))

        heap_min = test_heap.remove_min()
        self.assertEqual(36, heap_min)
        self.assertEqual(True, heap.has_max_heap_property(test_heap.heap))

        heap_min = test_heap.remove_min()
        self.assertEqual(25, heap_min)
        self.assertEqual(True, heap.has_max_heap_property(test_heap.heap))

        heap_min = test_heap.remove_min()
        self.assertEqual(19, heap_min)
        self.assertEqual(True, heap.has_max_heap_property(test_heap.heap))


class TestMinHeap2(unittest.TestCase):
    def setUp(self) -> None:
        self.input_keys_1 = [1, 25, 36, 100, 7, 17, 19, 2, 3]
        self.input_keys_2 = [1, 2, 7, 3, 17, 36, 25, 19, 100]

    def test_min_heap_init(self) -> None:
        # grab a heap
        test_heap = heap.MinHeap()
        self.assertEqual([], test_heap.heap)
        self.assertEqual(0, len(test_heap))

        # what happens as we add elements from self.input_keys?
        print('Adding keys %s to heap...' % str(self.input_keys_1))
        for n, k in enumerate(self.input_keys_1):
            test_heap.insert(k)
            print(n, test_heap)
            self.assertEqual(len(test_heap), n+1)
            self.assertEqual(True, heap.has_min_heap_property(test_heap.heap))

        print(test_heap)
        # Ensure that this is a min heap
        self.assertEqual(True, heap.has_min_heap_property(test_heap.heap))
        self.assertEqual(False, heap.has_max_heap_property(test_heap.heap))
        self.assertEqual(len(self.input_keys_1), len(test_heap))

        #heap_min = test_heap.remove_min()
        #self.assertEqual(1, heap_min)
        #self.assertEqual(True, heap.has_min_heap_property(test_heap.heap))

        #print(test_heap)
        #heap_min = test_heap.remove_min()
        #self.assertEqual(2, heap_min)
        #self.assertEqual(True, heap.has_min_heap_property(test_heap.heap))

        #print(test_heap)
        #heap_min = test_heap.remove_min()
        #self.assertEqual(3, heap_min)
        #self.assertEqual(True, heap.has_min_heap_property(test_heap.heap))

        #print(test_heap)
        #heap_min = test_heap.remove_min()
        #self.assertEqual(7, heap_min)
        #self.assertEqual(True, heap.has_min_heap_property(test_heap.heap))


if __name__ == '__main__':
    unittest.main()
