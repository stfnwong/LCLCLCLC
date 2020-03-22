"""
TEST_QUEUE
Unit tests for the basic queue

Stefan Wong 2019.
"""

import unittest
# unit under test
from pylc import queue


class TestQueue(unittest.TestCase):
    def setUp(self) -> None:
        self.inp1 = [1, 2, 3, 4, 5, 6, 7, 8]
        self.inp2 = [8, 7, 6, 5, 4, 3, 2, 1]

    def test_queue_enq_deq(self) -> None:
        test_queue = queue.Queue()
        self.assertEqual(0, test_queue.max_size())
        self.assertEqual(True, test_queue.empty())
        self.assertEqual(False, test_queue.full())

        for n, i in enumerate(self.inp1):
            test_queue.enqueue(i)
            self.assertEqual(n+1, len(test_queue))

        self.assertEqual(len(self.inp1), len(test_queue))
        # Dequeue and check order
        for n in self.inp1:
            self.assertEqual(n, test_queue.dequeue())

        self.assertEqual(True, test_queue.empty())
        self.assertEqual(False, test_queue.full())

        # Enqueue the other queue
        for n in self.inp2:
            test_queue.enqueue(n)
            self.assertEqual(False, test_queue.empty())

        # Dequeue and check order
        for n in self.inp2:
            self.assertEqual(n, test_queue.dequeue())

        self.assertEqual(True, test_queue.empty())
        self.assertEqual(False, test_queue.full())

    def test_queue_enq_deq_limit(self) -> None:
        test_queue_limit = queue.Queue(4)
        self.assertEqual(4, test_queue_limit.max_size())

        # Insert all the sample elements, check that the queue didn't expand
        for n in self.inp1:
            test_queue_limit.enqueue(n)

        self.assertEqual(True, test_queue_limit.full())
        self.assertEqual(False, test_queue_limit.empty())
        self.assertEqual(4, len(test_queue_limit))

        # Dequeue and check order
        # Note that there are only 4 elements in the queue
        for n, num in enumerate(self.inp1):
            q_top = test_queue_limit.dequeue()
            print('Dequeing element [%d / %d] : %s' %\
                  (n+1, test_queue_limit.max_size(), str(q_top))
            )
            self.assertEqual(num, q_top)
            self.assertEqual(False, test_queue_limit.full())
            if n < 3:
                self.assertEqual(False, test_queue_limit.empty())
            if test_queue_limit.empty():
                break

        self.assertEqual(4-1, n)         # account for zero offset
        self.assertEqual(True, test_queue_limit.empty())
        self.assertEqual(False, test_queue_limit.full())



if __name__ == '__main__':
    unittest.main()
