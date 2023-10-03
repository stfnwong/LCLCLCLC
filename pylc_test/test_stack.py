"""
TEST_STACK
Quick unit test for stack

Stefan Wong 2019
"""

import unittest
import time
from pylc import stack


class TestStack(unittest.TestCase):
    def setUp(self) -> None:
        self.stack_inputs         = [4, 5, 6, 7, 8, 9, 1]
        self.expected_stack_state = [4, 5, 6, 7, 8, 9, 1]
        self.expected_pop_order   = [1, 9, 8, 7, 6, 5, 4]

    def test_stack_push(self) -> None:
        test_stack = stack.Stack()

        for i in self.stack_inputs:
            test_stack.push(i)

        for n, s in enumerate(test_stack.array):
            print(n, s)

        self.assertEqual(len(self.expected_stack_state), len(test_stack.array))
        for n, ss in enumerate(self.expected_stack_state):
            self.assertEqual(ss, test_stack.array[n])

        # Pop each element off and ensure that the order is correct
        for n, s in enumerate(self.expected_pop_order):
            self.assertEqual(s, test_stack.pop())



if __name__ == '__main__':
    unittest.main()
