"""
TEST_DYNAMIC
Unit tests for dynamic programming

Stefan Wong 2019
"""

import unittest
import time
from timeit import default_timer
from pylc import dynamic


# Debug
#from pudb import set_trace; set_trace()


class TestFibonacci(unittest.TestCase):
    def setUp(self) -> None:
        self.expected_fib_numbers = [
            0,           1,    1,     2,     3,     5,     8,    13, 21,
            34,         55,   89,   144,   233,   377,   610,   987, 1597,
            2584,     4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393,
            196418, 317811
        ]

    def test_fibonacci_basic(self) -> None:
        fib_output = []

        print('Computing %d fibonacci numbers with dynamic.fibonacci()' % len(self.expected_fib_numbers))
        start_time = default_timer()
        for n in range(len(self.expected_fib_numbers)):
            fib_output.append(dynamic.fibonacci(n))
        end_time = default_timer()
        total_time = end_time - start_time
        print('fibonacci() took %ss' % str(total_time))

        for n, num in enumerate(self.expected_fib_numbers):
            self.assertEqual(num, fib_output[n])

    def test_fibonacci_memo(self) -> None:
        fib_output = []

        print('Computing %d fibonacci numbers with dynamic.fibonacci_memo()' % len(self.expected_fib_numbers))
        start_time = default_timer()
        for n in range(len(self.expected_fib_numbers)):
            fib_output.append(dynamic.fibonacci_memo(n))
        end_time = default_timer()
        total_time = end_time - start_time
        print('fibonacci_memo() took %ss' % str(total_time))

        for n, num in enumerate(self.expected_fib_numbers):
            self.assertEqual(num, fib_output[n])


class TestHanoi(unittest.TestCase):
    def setUp(self) -> None:
        self.num_towers = 3
        self.num_disks = 4

    def test_towers(self) -> None:
        print('Computing hanoi with %d towers and %d disks' % (self.num_towers, self.num_disks))
        towers_out = dynamic.hanoi_simple(self.num_towers, self.num_disks)

        print('Final towers :')
        for t in towers_out:
            print(t)



if __name__ == '__main__':
    unittest.main()
