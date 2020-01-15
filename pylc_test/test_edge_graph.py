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


# TODO: another for the graph


class TestEdgeWeightedDigraph(unittest.TestCase):
    def setUp(self) -> None:
        self.tiny_filename = 'data/tiny_ewd.txt'
        self.tiny_exp_num_vertex = 8
        self.tiny_exp_num_edge   = 15

    def test_graph_from_file(self) -> None:

        test_graph = edge_graph.graph_from_file(self.tiny_filename, verbose=True)

        # Debug print
        print(test_graph)

        self.assertEqual(self.tiny_exp_num_vertex, test_graph.num_verticies())
        self.assertEqual(self.tiny_exp_num_edge, test_graph.num_edges())



if __name__ == '__main__':
    unittest.main()
