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
            print('Inserting node [%d / %d] (%s)' % (n+1, len(self.expected_keys), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print('[', end=' ')
        for node in heap_array:
            print('%d,' % (node.key), end=' ')
        print(']')

        self.assertEqual(len(self.expected_keys), test_heap.cur_idx)

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
            print('Inserting node [%d / %d] (%s)' % (n+1, len(self.expected_keys), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print('[', end=' ')
        for node in heap_array:
            print('%d,' % (node.key), end=' ')
        print(']')

        self.assertEqual(len(self.expected_keys), test_heap.cur_idx)

        # Now do the check
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
            print('Inserting node [%d / %d] (%s)' % (n+1, len(self.expected_keys), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print('[', end=' ')
        for node in heap_array:
            print('%d,' % (node.key), end=' ')
        print(']')


# All node keys are greater than their children
class TestMaxHeap(unittest.TestCase):
    def setUp(self) -> None:
        self.input_keys            = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        self.expected_keys         = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        self.expected_keys_reverse = [9, 8, 7, 5, 6, 2, 1, 4, 0, 3]

    def test_insert_keys_inorder(self) -> None:
        test_heap = pylc_heap.MaxHeap()
        # Insert the keys in the order they appear in setUp()
        print('Inserting %d keys' % len(self.expected_keys))
        for n, k in enumerate(self.expected_keys):
            node = pylc_heap.HeapNode(k, n)
            print('Inserting node [%d / %d] (%s)' % (n+1, len(self.expected_keys), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print('[', end=' ')
        for node in heap_array:
            print('%d,' % (node.key), end=' ')
        print(']')

        self.assertEqual(len(self.expected_keys), test_heap.cur_idx)

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
        print('[', end=' ')
        for node in heap_array:
            print('%d,' % (node.key), end=' ')
        print(']')

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
            print('Inserting node [%d / %d] (%s)' % (n+1, len(self.expected_keys), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array : ')
        heap_array = test_heap.get_array()
        print('[', end=' ')
        for node in heap_array:
            print('%d,' % (node.key), end=' ')
        print(']')



if __name__ == '__main__':
    unittest.main()
