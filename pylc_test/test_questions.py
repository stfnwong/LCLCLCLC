"""
TEST_QUESTIONS
Unit tests for LC questions

Stefan Wong 2019
"""

import unittest
from pylc import questions



class TestQuestion53(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        self.exp1 = [4, -1, 2, 1]



if __name__ == '__main__':
    unittest.main()
