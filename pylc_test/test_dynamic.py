"""
TEST_DYNAMIC
Unit tests for dynamic programming

Stefan Wong 2019
"""

import unittest
from pylc import dynamic


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

        for n in range(len(self.expected_fib_numbers)):
            fib_output.append(dynamic.fibonacci(n))

        for n, num in enumerate(self.expected_fib_numbers):
            self.assertEqual(num, fib_output[n])

    def test_fibonacci_memo(self) -> None:
        fib_output = []

        for n in range(len(self.expected_fib_numbers)):
            fib_output.append(dynamic.fibonacci_memo(n))

        for n, num in enumerate(self.expected_fib_numbers):
            self.assertEqual(num, fib_output[n])


if __name__ == '__main__':
    unittest.main()
