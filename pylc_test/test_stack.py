"""
TEST_STACK
Quick unit test for stack

"""

from pylc import stack


stack_inputs         = [4, 5, 6, 7, 8, 9, 1]
expected_stack_state = [4, 5, 6, 7, 8, 9, 1]
expected_pop_order   = [1, 9, 8, 7, 6, 5, 4]



def test_stack_push() -> None:
    test_stack = stack.Stack()

    for i in stack_inputs:
        test_stack.push(i)

    #for n, s in enumerate(test_stack.array):
    #    print(n, s)

    assert len(expected_stack_state) == len(test_stack.array)

    for n, ss in enumerate(expected_stack_state):
        assert ss == test_stack.array[n]

    # Pop each element off and ensure that the order is correct
    for n, s in enumerate(expected_pop_order):
        assert s == test_stack.pop()
