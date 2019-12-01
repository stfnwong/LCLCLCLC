"""
TEST_QUESTIONS
Unit tests for LC questions

Stefan Wong 2019
"""

import unittest
from pylc import questions



class TestQuestion3(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = "abcabcbb"
        self.exp1 = 3
        self.inp2 = "bbbbb"
        self.exp2 = 1
        self.inp3 = "pwwkew"
        self.exp3 = 3

    def test_longest_unique_substring(self) -> None:
        l1 = questions.longest_unique_substring_3(self.inp1)
        print('Input [%s] Expected length %d, got length %d' % (self.inp1, self.exp1, l1))
        self.assertEqual(self.exp1, l1)

        l2 = questions.longest_unique_substring_3(self.inp2)
        print('Input [%s] Expected length %d, got length %d' % (self.inp2, self.exp2, l2))
        self.assertEqual(self.exp2, l2)

        l3 = questions.longest_unique_substring_3(self.inp3)
        print('Input [%s] Expected length %d, got length %d' % (self.inp3, self.exp3, l3))
        self.assertEqual(self.exp3, l3)



class TestQuestion53(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        self.exp1 = 6
        self.inp2 = [-2]
        self.exp2 = -2

    def test_max_subarray(self) -> None:
        s1 = questions.maximum_subarray_53(self.inp1)
        self.assertEqual(self.exp1, s1)
        s2 = questions.maximum_subarray_53(self.inp2)
        self.assertEqual(self.exp2, s2)



# For this question, we only need to know if we can or cannot make
# it to the last index. We don't need to know the path.
class TestQuestion55(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = [2, 3, 1, 1, 4]
        self.exp1 = True
        self.inp2 = [3, 2, 1, 0, 4]
        self.exp2 = False
        self.inp3 = [1, 5, 2, 1, 0, 2, 0]
        self.exp3 = True
        self.inp4 = [2, 0]
        self.exp4 = True

    def test_jump_game(self) -> None:
        jump1 = questions.jump_game_55(self.inp1)
        self.assertEqual(self.exp1, jump1)
        jump2 = questions.jump_game_55(self.inp2)
        self.assertEqual(self.exp2, jump2)
        jump3 = questions.jump_game_55(self.inp3)
        self.assertEqual(self.exp3, jump3)

        jump4 = questions.jump_game_55(self.inp4)
        self.assertEqual(self.exp4, jump4)


if __name__ == '__main__':
    unittest.main()
