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
        # 250 vertex graph
        self.graph_250_filename = 'data/ewd_250.txt'
        self.graph_250_num_vertex = 250
        self.graph_250_num_edge   = 2546


    def test_tiny_graph_init_file(self) -> None:
        # Note that the princeton graphs are not bidirectional...
        test_graph = path.graph_from_file(self.tiny_filename, bidir=False)
        print('test_graph contains %d verticies (expected %d verticies)' %\
              (test_graph.get_num_nodes(), self.tiny_exp_num_vertex)
        )
        print('test_graph contains %d edges (expected %d edges)' %\
              (test_graph.get_num_edges(), self.tiny_exp_num_edge)
        )

        self.assertEqual(self.tiny_exp_num_vertex, test_graph.get_num_nodes())
        self.assertEqual(self.tiny_exp_num_edge, test_graph.get_num_edges())

    def test_path_tiny_graph(self) -> None:
        test_graph = path.graph_from_file(self.tiny_filename, bidir=True)
        self.assertEqual(self.tiny_exp_num_vertex, test_graph.get_num_nodes())
        self.assertEqual(2 * self.tiny_exp_num_edge, test_graph.get_num_edges())


    def test_250_node_graph_init_file(self) -> None:
        test_graph = path.graph_from_file(self.graph_250_filename, bidir=False)
        print('test_graph contains %d verticies (expected %d verticies)' %\
              (test_graph.get_num_nodes(), self.graph_250_num_vertex)
        )
        print('test_graph contains %d edges (expected %d edges)' %\
              (test_graph.get_num_edges(), self.graph_250_num_edge)
        )

        self.assertEqual(self.graph_250_num_vertex, test_graph.get_num_nodes())
        self.assertEqual(self.graph_250_num_edge, test_graph.get_num_edges())


    #def test_graph_init(self) -> None:

    #    test_graph = path.Graph()


if __name__ == '__main__':
    unittest.main()
