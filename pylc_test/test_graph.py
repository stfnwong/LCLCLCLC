"""
TEST_GRAPH
Unit tests for Graph object

Stefan Wong 2019
"""

import unittest
import pylc.graph as graph


class TestGraph(unittest.TestCase):

    def test_graph_init(self) -> None:
        g = graph.Graph()
        # This should be an empty graph
        print(g)
        self.assertEqual(0, len(g))

        # Make an adjacency list
        adj_list = [[1,2], [0,2], [2,0]]


if __name__ == '__main__':
    unittest.main()
