"""
HEAP2_TEST
Heap2 unit tests. This is just a heap with less stuff attached to it

Stefan Wong 2020
"""

import random
import copy
import unittest
# unit under test
from pylc import heap2      # Once this is alright, factor back into main heap
#import pylc.heap2 as heap2

# Debug
#from pudb import set_trace; set_trace()

#def print_heap_array(heap_array:list) -> None:
#    print('[', end=' ')
#    for node in heap_array:
#        print('%d,' % (node.key), end=' ')
#    print(']')


class TestHeap2(unittest.TestCase):
    def setUp(self) -> None:
        #self.input_keys            = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        #self.input_keys            = [5, 8, 3, 2, 4, 9, 7, 0, 6, 1]
        #self.input_keys            = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        #self.expected_keys         = [9, 8, 6, 7, 4, 5, 2, 0, 3, 1]
        #self.expected_keys_reverse = [9, 8, 7, 5, 6, 2, 1, 4, 0, 3]
        self.input_keys_1 = [1, 2, 3, 7, 17, 19, 25, 36, 100]
        self.input_keys_2 = [1, 2, 7, 3, 17, 36, 25, 19, 100]

    def test_heap_12_init(self) -> None:
        # grab a heap
        test_heap_1 = heap2.Heap()
        self.assertEqual([], test_heap_1.heap)

        # what happens as we add elements from self.input_keys?
        print('Adding keys %s to heap...' % str(self.input_keys_1))
        for n, k in enumerate(self.input_keys_1):
            test_heap_1.insert(k)
            self.assertEqual(len(test_heap_1), n+1)

        print(test_heap_1)


if __name__ == '__main__':
    unittest.main()
