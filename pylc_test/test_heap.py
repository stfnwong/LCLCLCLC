"""
HEAP_TEST
Unit tests for heap data structure

Stefan Wong 2019
"""

import random
import copy
import unittest
# unit under test
import pylc.heap as pylc_heap

#from pudb import set_trace; set_trace()

def print_heap_array(heap_array:list) -> None:
    print('[', end=' ')
    for node in heap_array:
        print('%d,' % (node.key), end=' ')
    print(']')


# Test the functions which determine if an array meets the
# heap property
class TestHeapProperty(unittest.TestCase):
    def setUp(self) -> None:
        self.input_keys        = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        self.min_expected_keys = [0, 1, 2, 4, 3, 7, 8, 5, 9, 6]
        self.max_expected_keys = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]

    def test_min_heap_property(self) -> None:
        # The input keys should have the min heap property
        is_heap = pylc_heap.has_min_heap_property(self.input_keys)
        print('Input keys are a min heap? : %s' % str(is_heap))
        self.assertEqual(True, is_heap)

        # Now put the keys in an actual heap and ensure that
        # the result heap also has the expected heap properties
        test_heap = pylc_heap.MinHeap()

        for n, k in enumerate(self.input_keys):
            node = pylc_heap.HeapNode(k, n)
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print_heap_array(heap_array)

        self.assertEqual(True, pylc_heap.has_max_heap_property(heap_array))
        self.assertEqual(False, pylc_heap.has_min_heap_property(heap_array))

    def test_max_heap_property(self) -> None:
        # This of course means that the input keys should not have the max heap
        # property
        is_heap = pylc_heap.has_max_heap_property(self.input_keys)
        print('Input keys are a max heap? : %s' % str(is_heap))
        self.assertEqual(False, is_heap)

        # Now put the keys in an actual heap and ensure that
        # the result heap also has the expected heap properties
        test_heap = pylc_heap.MaxHeap()

        for n, k in enumerate(self.input_keys):
            node = pylc_heap.HeapNode(k, n)
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print_heap_array(heap_array)

        self.assertEqual(True, pylc_heap.has_min_heap_property(heap_array))
        self.assertEqual(False, pylc_heap.has_max_heap_property(heap_array))


# Test the base Heap class
class TestHeap(unittest.TestCase):

    def setUp(self) -> None:
        self.input_keys            = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        self.expected_keys         = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        self.expected_keys_reverse = [9, 8, 7, 5, 6, 2, 1, 4, 0, 3]

    def test_init(self) -> None:
        test_heap = pylc_heap.Heap()
        # If we don't specify a size, then the default size is 32
        self.assertEqual(32, test_heap.max_size)
        self.assertEqual(0, test_heap.cur_idx)
        self.assertEqual(32, len(test_heap.nodes))

        for n in test_heap.nodes:
            self.assertEqual(pylc_heap.HeapNode(0, 0), n)


# All node keys are less than their children
class TestMinHeap(unittest.TestCase):

    def setUp(self) -> None:
        self.input_keys            = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        self.expected_keys         = [0, 1, 2, 4, 3, 7, 8, 5, 9, 6]
        self.expected_keys_reverse = [9, 8, 7, 5, 6, 2, 1, 4, 0, 3]

    def test_insert_keys_inorder(self) -> None:
        test_heap = pylc_heap.MinHeap()
        # Insert the keys in the order they appear in setUp()
        print('Inserting %d keys' % len(self.expected_keys))
        for n, k in enumerate(self.expected_keys):
            node = pylc_heap.HeapNode(k, n)
            print('Inserting node [%d / %d] into %s (%s)' % (n+1, len(self.expected_keys), repr(test_heap), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print_heap_array(heap_array)

        self.assertEqual(len(self.expected_keys), test_heap.cur_idx)
        # Check that this satisfies the heap property
        self.assertEqual(False, pylc_heap.has_max_heap_property(test_heap.nodes))
        self.assertEqual(True, pylc_heap.has_min_heap_property(test_heap.nodes))

        # Now do the check
        for n, node in enumerate(test_heap.nodes):
            if n < len(self.expected_keys):
                self.assertEqual(self.expected_keys[n], node.key)
            else:
                self.assertEqual(0, node.key)

    def test_insert_keys_inorder(self) -> None:
        test_heap = pylc_heap.MinHeap()
        # Insert the keys in the order they appear in setUp()
        print('Inserting %d keys' % len(self.expected_keys))
        for n, k in enumerate(self.expected_keys):
            node = pylc_heap.HeapNode(k, n)
            print('Inserting node [%d / %d] into %s (%s)' % (n+1, len(self.expected_keys), repr(test_heap), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print_heap_array(heap_array)

        self.assertEqual(len(self.expected_keys), test_heap.cur_idx)
        self.assertEqual(True, pylc_heap.has_min_heap_property(test_heap.nodes))

        # Test the actual key values
        for n, node in enumerate(test_heap.nodes):
            if n < len(self.expected_keys):
                self.assertEqual(self.expected_keys[n], node.key)
            else:
                self.assertEqual(0, node.key)

    def test_insert_keys_random_order(self) -> None:
        random_keys = copy.copy(self.expected_keys)
        random.shuffle(random_keys)

        print('Original keys')
        print('    {', end=' ')
        for k in self.expected_keys:
            print('%d,' % k, end=' ')
        print('}')

        print('Random keys')
        print('    {', end=' ')
        for k in random_keys:
            print('%d,' % k, end=' ')
        print('}')

        test_heap = pylc_heap.MinHeap()

        print('Inserting %d keys' % len(random_keys))
        for n, k in enumerate(random_keys):
            node = pylc_heap.HeapNode(k, n)
            print('Inserting node [%d / %d] into %s (%s)' % (n+1, len(self.expected_keys), repr(test_heap), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print_heap_array(heap_array)

        self.assertEqual(True, pylc_heap.has_min_heap_property(test_heap.nodes))
        # Test the actual key values
        for n, node in enumerate(test_heap.nodes):
            if n < len(self.expected_keys):
                self.assertEqual(self.expected_keys[n], node.key)
            else:
                self.assertEqual(0, node.key)


# All node keys are greater than their children
class TestMaxHeap(unittest.TestCase):

    def setUp(self) -> None:
        self.input_keys            = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        self.expected_keys         = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        self.expected_keys_reverse = [9, 8, 7, 5, 6, 2, 1, 4, 0, 3]

    def test_insert_keys_inorder(self) -> None:
        test_heap = pylc_heap.MaxHeap()
        # Insert the keys in the order they appear in setUp()
        print('Inserting %d keys' % len(self.input_keys))
        for n, k in enumerate(self.input_keys):
            node = pylc_heap.HeapNode(k, n)
            print('Inserting node [%d / %d] into %s (%s)' % (n+1, len(self.input_keys), repr(test_heap), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print_heap_array(heap_array)

        self.assertEqual(len(self.expected_keys), test_heap.cur_idx)
        self.assertEqual(False, pylc_heap.has_min_heap_property(test_heap.get_array()))
        self.assertEqual(True,  pylc_heap.has_max_heap_property(test_heap.get_array()))
        # Now do the check
        for n, node in enumerate(test_heap.nodes):
            if n < len(self.expected_keys):
                self.assertEqual(self.expected_keys[n], node.key)
            else:
                self.assertEqual(0, node.key)

    def test_insert_keys_reverse(self) -> None:
        reversed_keys = copy.copy(self.expected_keys)
        reversed_keys.reverse()

        print('Original keys')
        print('    {', end=' ')
        for k in self.expected_keys:
            print('%d,' % k, end=' ')
        print('}')

        print('Reversed keys')
        print('    {', end=' ')
        for k in reversed_keys:
            print('%d,' % k, end=' ')
        print('}')

        test_heap = pylc_heap.MaxHeap()

        print('Inserting %d keys' % len(reversed_keys))
        for n, k in enumerate(reversed_keys):
            node = pylc_heap.HeapNode(k, n)
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print_heap_array(heap_array)

        # Now do the check
        for n, node in enumerate(test_heap.nodes):
            if n < len(self.expected_keys_reverse):
                self.assertEqual(self.expected_keys_reverse[n], node.key)
            else:
                self.assertEqual(0, node.key)

    def test_insert_keys_random_order(self) -> None:
        random_keys = copy.copy(self.expected_keys)
        random.shuffle(random_keys)

        print('Original keys')
        print('    {', end=' ')
        for k in self.expected_keys:
            print('%d,' % k, end=' ')
        print('}')

        print('Random keys')
        print('    {', end=' ')
        for k in random_keys:
            print('%d,' % k, end=' ')
        print('}')

        test_heap = pylc_heap.MaxHeap()

        print('Inserting %d keys' % len(random_keys))
        for n, k in enumerate(random_keys):
            node = pylc_heap.HeapNode(k, n)
            print('Inserting node [%d / %d] into %s (%s)' % (n+1, len(self.expected_keys), repr(test_heap), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print_heap_array(heap_array)

        self.assertEqual(False, pylc_heap.has_min_heap_property(test_heap.get_array()))
        self.assertEqual(True,  pylc_heap.has_max_heap_property(test_heap.get_array()))


if __name__ == '__main__':
    unittest.main()
