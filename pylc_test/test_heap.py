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
        self.expected_keys = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]

    def test_init(self) -> None:
        test_heap = pylc_heap.Heap()
        # If we don't specify a size, then the default size is 32
        self.assertEqual(32, test_heap.max_size)
        self.assertEqual(0, test_heap.cur_idx)
        self.assertEqual(32, len(test_heap.nodes))

        for n in test_heap.nodes:
            self.assertEqual(pylc_heap.HeapNode(0, 0), n)

    def test_insert_keys_inorder(self) -> None:
        test_heap = pylc_heap.Heap()
        # Insert the keys in the order they appear in setUp()
        print('Inserting %d keys' % len(self.expected_keys))
        for n, k in enumerate(self.expected_keys):
            node = pylc_heap.HeapNode(k, n)
            print('Inserting node [%d / %d] (%s)' % (n+1, len(self.expected_keys), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array (keys only): ')
        print('{', end=' ')
        for n in test_heap.nodes:
            print('%d,' % n.key, end=' ')
        print('}')

        self.assertEqual(len(self.expected_keys), test_heap.cur_idx)

        # Now do the check
        for n, node in enumerate(test_heap.nodes):
            self.assertEqual(self.expected_keys[n], node.key)
            if n == len(self.expected_keys)-1:
                break


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

        test_heap = pylc_heap.Heap()

        print('Inserting %d keys' % len(random_keys))
        for n, k in enumerate(random_keys):
            node = pylc_heap.HeapNode(k, n)
            print('Inserting node [%d / %d] (%s)' % (n+1, len(self.expected_keys), str(node)))
            test_heap.insertNode(node)

        print('Heap internal array (keys only): ')
        print('{', end=' ')
        for n in test_heap.nodes:
            print('%d,' % n.key, end=' ')
        print('}')


if __name__ == '__main__':
    unittest.main()
