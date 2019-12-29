"""
TEST_CONCURRENCY
Unit tests for Concurrency questions.

Stefan Wong 2019
"""

import unittest
# Unit(s) under test
from pylc import concurrency


class TestQuestion1114(unittest.TestCase):
    def setUp(self) -> None:
        # There are 3 threads being fired asynchronously. The input
        # [1, 2, 3] means thread A calls first(), thread B calls
        # second() and thread C calls third().
        self.inp1 = [1, 2, 3]
        self.exp1 = "firstsecondthird"

        # In this case, thead A calls first(), thread B calls third(),
        # and thread C calls second(). We synchronise the order so that
        # the output is still "firstsecondthird".
        self.inp2 = [1, 3, 2]
        self.exp2 = "firstsecondthird"

    def test_question_1114(self) -> None:
        q = concurrency.Question1114()


if __name__ == '__main__':
    unittest.main()
