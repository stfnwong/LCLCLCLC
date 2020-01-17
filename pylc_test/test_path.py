"""
TEST_PATH
Tests for path experiment

Stefan Wong 2020
"""


import unittest
# unit(s) under test
from pylc import path


class TestGraph(unittest.TestCase):
    def setUp(self) -> None:
        # Tiny graph
        self.tiny_filename = 'data/tiny_ewd.txt'
        self.tiny_exp_num_vertex = 8
        self.tiny_exp_num_edge   = 15

    def test_graph_init_file(self) -> None:
        # Note that the princeton graphs are not bidirectional...
        test_graph = path.graph_from_file(self.tiny_filename, bidir=False)

        self.assertEqual(self.tiny_exp_num_vertex, test_graph.get_num_nodes())
        self.assertEqual(self.tiny_exp_num_edge, test_graph.get_num_edges())

    #def test_graph_init(self) -> None:

    #    test_graph = path.Graph()


if __name__ == '__main__':
    unittest.main()
