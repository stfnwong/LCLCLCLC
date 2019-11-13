"""
TEST_DISTANCE
Unit test harness for distances.

Stefan Wong 2019
"""

import unittest
# unit under test
import pylc.distance as distance


class TestDistance(unittest.TestCase):

    def test_int_min_pair_brute(self):
        test_array = [3, 5, 4, 2]
        expected_diff = 2
        expected_pair = (3, 4)

        diff, idx, pair = distance.int_min_pair_brute(test_array, verbose=True)
        # show results before assertion
        print('Found distance as ', diff)
        print('Found idx as ', idx)
        print('Found pair as ', pair)

        self.assertEqual(expected_diff, diff)
        self.assertEqual(expected_pair, pair)


if __name__ == '__main__':
    unittest.main()
