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


class TestQuestion14(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = ["flower", "flow", "flight"]
        self.exp1 = "fl"
        self.inp2 = ["dog", "racecar", "car"]
        self.exp2 = ""

    def test_longest_common_prefix(self) -> None:
        p1 = questions.longest_common_prefix_14(self.inp1)
        print('Input [%s] : expected %s, got %s' % (self.inp1, self.exp1, p1))
        self.assertEqual(self.exp1, p1)

        p2 = questions.longest_common_prefix_14(self.inp2)
        print('Input [%s] : expected %s, got %s' % (self.inp2, self.exp2, p2))
        self.assertEqual(self.exp2, p2)


class TestQuestion39(unittest.TestCase):
    def setUp(self) -> None:
        # input format is (candiates, target)
        self.inp1 = ([2, 3, 6, 7], 7)
        self.exp1 = [[7], [2, 2, 3]]
        self.inp2 = ([2,3,5], 8)
        self.exp2 = [[2, 2, 2, 2], [2, 3, 3], [3, 5]]

    def test_combination_sum(self) -> None:
        result1 = questions.combination_sum_39(self.inp1[0], self.inp1[1])

        print('Got %s' % str(result1))
        print('Expected %s' % str(self.exp1))

        result2 = questions.combination_sum_39(self.inp2[0], self.inp2[1])

        print('Got %s' % str(result2))
        print('Expected %s' % str(self.exp2))


class TestQuestion40(unittest.TestCase):
    def setUp(self) -> None:
        # input format is (candiates, target)
        self.inp1 = ([10, 1, 2, 7, 6, 1, 5], 8)
        self.exp1 = [[1, 7], [1, 2, 5], [2, 6], [1, 1, 6]]
        self.inp2 = ([2, 5, 2, 1, 2], 5)
        self.exp2 = [[1, 2, 2], [5]]

    def test_combination_sum(self) -> None:
        result1 = questions.combination_sum_40(self.inp1[0], self.inp1[1])

        print('Got %s' % str(sorted(result1)))
        print('Expected %s' % str(sorted((self.exp1))))

        # Not sure that we can rely on order for assertions here...
        # The output here is a list of lists, so the first thing we can
        # do is check that each of the expected lists is in fact in the
        # output
        for n, (out, exp) in enumerate(zip(sorted(result1), sorted(self.exp1))):
            for o, e in zip(out, exp):
                self.assertEqual(e, o)

        result2 = questions.combination_sum_40(self.inp2[0], self.inp2[1])

        print('Got %s' % str(sorted(result2)))
        print('Expected %s' % str(sorted((self.exp2))))

        for n, (out, exp) in enumerate(zip(sorted(result2), sorted(self.exp2))):
            for o, e in zip(out, exp):
                self.assertEqual(e, o)



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
