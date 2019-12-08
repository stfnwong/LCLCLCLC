"""
TEST_GRAPH
Unit tests for Graph object

Stefan Wong 2019
"""

import unittest
# unit under test
import pylc.graph as graph


class TestGraphNode(unittest.TestCase):

    def test_graph_node_operators(self) -> None:
        num_nodes = 8
        nodes = [graph.GraphNode(0, 0, n) for n in range(num_nodes)]

        # This test is so obvious it hurts, but lets do it anyway
        self.assertEqual(num_nodes, len(nodes))
        for n, node in enumerate(nodes):
            self.assertEqual(n, node.node_id)

        # None of these should be equal
        for n in range(1, len(nodes)):
            self.assertNotEqual(nodes[n-1].node_id, nodes[n].node_id)

        # So therefore, the __eq__ overload will fail
        for n in range(1, len(nodes)):
            self.assertFalse(nodes[n-1] == nodes[n])

        # But the __ne___ overload wont
        for n in range(1, len(nodes)):
            self.assertTrue(nodes[n-1] != nodes[n])

        # The nodes ids are monotonically increasing so any montonically
        # increasing equality check will pass
        for n in range(1, len(nodes)):
            self.assertTrue(nodes[n-1] <= nodes[n])
            self.assertTrue(nodes[n-1] < nodes[n])

        # And any monotonically decreasing equality check will fail
        for n in range(1, len(nodes)):
            self.assertFalse(nodes[n-1] >= nodes[n])
            self.assertFalse(nodes[n-1] > nodes[n])



class TestGraph(unittest.TestCase):

    def setUp(self) -> None:
        self.empty_repr = "{}"
        self.repr3      = "{0,1,4,5#1,4,3#2,1#3,2,4#4#5}"
        self.expected_graph3_bfs = [0, 1, 4, 5, 3, 2]
        self.expected_graph3_dfs = [0, 1, 3, 2, 4, 5]

    #def test_init_graph_empty(self) -> None:
    #    g = graph.Graph()
    #    # This should be an empty graph
    #    print(g)
    #    self.assertEqual(0, len(g))

    #def test_init_graph_adj_list(self) -> None:
    #    # Make an adjacency list
    #    adj_list = [[1,2], [0,2], [2,0]]
    #    g = graph.Graph(adj_list)
    #    self.assertEqual(3, len(g))
    #    # TODO: walk along the graph

    #def test_init_graph_from_repr(self) -> None:
    #    pass


if __name__ == '__main__':
    unittest.main()
