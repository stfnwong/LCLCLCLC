"""
TEST_GRAPH
Unit tests for Graph object

Stefan Wong 2019
"""

import unittest
# unit under test
import pylc.graph as graph


class TestGraph(unittest.TestCase):

    def setUp(self) -> None:
        self.empty_repr = "{}"
        self.repr3      = "{0,1,4,5#1,4,3#2,1#3,2,4#4#5}"
        self.expected_graph3_bfs = [0, 1, 4, 5, 3, 2]
        self.expected_graph3_dfs = [0, 1, 3, 2, 4, 5]

    def test_init_graph_empty(self) -> None:
        g = graph.Graph()
        # This should be an empty graph
        print(g)
        self.assertEqual(0, len(g))

    def test_init_graph_adj_list(self) -> None:
        # Make an adjacency list
        adj_list = [[1,2], [0,2], [2,0]]
        g = graph.Graph(adj_list)
        self.assertEqual(3, len(g))
        # TODO: walk along the graph

    def test_init_graph_from_repr(self) -> None:
        pass


if __name__ == '__main__':
    unittest.main()
