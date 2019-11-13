"""
TEST_DISTANCE
Unit test harness for distances.

Stefan Wong 2019
"""

import unittest
# unit under test
import pylc.distance as distance


class TestPairDistance(unittest.TestCase):

    def setUp(self):
        self.test_array = [3, 5, 4, 2]
        self.expected_diff = 2
        self.expected_pair = (3, 4)
        self.verbose = True

    def test_int_min_pair_brute(self):
        diff, idx, pair = distance.int_min_pair_brute(self.test_array, verbose=self.verbose)
        # show results before assertion
        print('Found distance as ', diff)
        print('Found idx as ', idx)
        print('Found pair as ', pair)

        self.assertEqual(self.expected_diff, diff)
        self.assertEqual(self.expected_pair, pair)

    #def test_int_min_pair_recursion(self):
    #    diff, idx, pair = distance.int_min_pair_recursion(self.test_array, verbose=self.verbose)
    #    # show results before assertion
    #    print('Found distance as ', diff)
    #    print('Found idx as ', idx)
    #    print('Found pair as ', pair)

    #    self.assertEqual(self.expected_diff, diff)
    #    self.assertEqual(self.expected_pair, pair)




class TestOccurenceDistance(unittest.TestCase):

    def setUp(self):
        self.test_array = [3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2]
        self.expected_dist_1 = 2
        self.expected_dist_2 = 10
        self.expected_dist_4 = 5
        self.verbose = True

    def test_int_occurence_dist_brute(self):
        print('Testing double-array implementation')
        dist_1, idx_1 = distance.int_occurence_dist_brute(self.test_array, 1, verbose=self.verbose)
        dist_2, idx_2 = distance.int_occurence_dist_brute(self.test_array, 2, verbose=self.verbose)
        dist_4, idx_4 = distance.int_occurence_dist_brute(self.test_array, 4, verbose=self.verbose)

        print('Found max_dist for value 1 as :', dist_1, ' at indicies ', idx_1)
        print('Found max_dist for value 2 as :', dist_2, ' at indicies ', idx_2)
        print('Found max_dist for value 4 as :', dist_4, ' at indicies ', idx_4)

        self.assertEqual(self.expected_dist_1, dist_1)
        self.assertEqual(self.expected_dist_2, dist_2)
        self.assertEqual(self.expected_dist_4, dist_4)

        print('OK')

    def test_int_occurence_dist_hash(self):
        print('Testing hash implementation')
        dist_1, idx_1 = distance.int_occurence_dist_hash(self.test_array, 1, verbose=self.verbose)
        dist_2, idx_2 = distance.int_occurence_dist_hash(self.test_array, 2, verbose=self.verbose)
        dist_4, idx_4 = distance.int_occurence_dist_hash(self.test_array, 4, verbose=self.verbose)

        print('Found max_dist for value 1 as :', dist_1, ' at indicies ', idx_1)
        print('Found max_dist for value 2 as :', dist_2, ' at indicies ', idx_2)
        print('Found max_dist for value 4 as :', dist_4, ' at indicies ', idx_4)

        self.assertEqual(self.expected_dist_1, dist_1)
        self.assertEqual(self.expected_dist_2, dist_2)
        self.assertEqual(self.expected_dist_4, dist_4)

        print('OK')

if __name__ == '__main__':
    unittest.main()
