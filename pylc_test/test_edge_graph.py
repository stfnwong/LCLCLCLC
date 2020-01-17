"""
TEST_EDGE_GRAPH
Unit tests for Edge Weighted Graph object

Stefan Wong 2020
"""

import unittest
# unit under test
from pylc import edge_graph

# debug
#from pudb import set_trace; set_trace()


class TestDirectedEdge(unittest.TestCase):
    def test_edge_init(self) -> None:
        test_edge = edge_graph.DirectedEdge()

        print('Created edge : %s' % str(test_edge))

        self.assertEqual(0, test_edge.v)
        self.assertEqual(0, test_edge.w)
        self.assertAlmostEqual(0.0, test_edge.weight)



class TestEdgeWeightedDigraph(unittest.TestCase):
    def setUp(self) -> None:
        # Tiny graph
        self.tiny_filename = 'data/tiny_ewd.txt'
        self.tiny_exp_num_vertex = 8
        self.tiny_exp_num_edge   = 15

        # 250 vertex graph
        self.g250_filename = 'data/ewd_250.txt'
        self.g250_exp_num_vertex = 250
        self.g250_exp_num_edge   = 2546


    def test_tiny_graph_from_file(self) -> None:
        test_graph = edge_graph.graph_from_file(self.tiny_filename, verbose=True)
        # Debug print
        print(test_graph)

        self.assertEqual(self.tiny_exp_num_vertex, test_graph.num_verticies())
        self.assertEqual(self.tiny_exp_num_edge, test_graph.num_edges())

    def test_250_graph_from_file(self) -> None:
        test_graph = edge_graph.graph_from_file(self.g250_filename, verbose=True)
        self.assertEqual(self.g250_exp_num_vertex, test_graph.num_verticies())
        self.assertEqual(self.g250_exp_num_edge, test_graph.num_edges())

    def test_ewd_dijsktra(self) -> None:
        # Get the small graph and check its the correct size
        test_graph = edge_graph.graph_from_file(self.tiny_filename, verbose=True)
        self.assertEqual(self.tiny_exp_num_vertex, test_graph.num_verticies())
        self.assertEqual(self.tiny_exp_num_edge, test_graph.num_edges())

        start_node = 4

        visited, path = edge_graph.ewd_dijsktra(test_graph, start_node)


if __name__ == '__main__':
    unittest.main()
