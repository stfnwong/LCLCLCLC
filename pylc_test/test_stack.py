"""
TEST_STACK
Quick unit test for stack

Stefan Wong 2019
"""

import unittest
from pylc import stack


def test_stack_push():
    stack_inputs         = [4, 5, 6, 7, 8, 9, 1]
    expected_stack_state = [4, 5, 6, 7, 8, 9, 1]
    expected_pop_order   = [1, 9, 8, 7, 6, 5, 4]

    test_stack = stack.Stack()

    for i in stack_inputs:
        test_stack.push(i)

    for n, s in enumerate(test_stack.array):
        print(n, s)

    assert len(test_stack.array) == len(expected_stack_state)
    for ts, ss in zip(test_stack.array, expected_stack_state):
        assert ts == ss

    for s in expected_pop_order:
        assert s == test_stack.pop()
