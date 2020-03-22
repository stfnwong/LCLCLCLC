"""
TEST_GRAPH
Unit tests for Graph object

Stefan Wong 2019
"""

import unittest
# unit under test
import pylc.graph as graph

# debug
#from pudb import set_trace; set_trace()


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

        # Also if we go backwards these rules are now invalid
        # as the list is now monotonically decreasing
        for n in range(len(nodes)-1, 1, -1):
            self.assertTrue(nodes[n] >= nodes[n-1])


class TestGraph(unittest.TestCase):
    def setUp(self) -> None:
        self.empty_repr = "{}"
        self.repr1      = "{0,1,2#1,2#2,2}";
        self.repr2      = "{0,1,2#1,2#2,2,4#3,1,0#4,2,3}";
        self.repr3      = "{0,1,4,5#1,4,3#2,1#3,2,4#4#5}"

        self.expected_graph3_bfs = [0, 1, 4, 5, 3, 2]
        self.expected_graph3_dfs = [0, 1, 3, 2, 4, 5]

    def test_init_graph(self) -> None:
        test_graph = graph.Graph()
        print(test_graph)
        self.assertEqual(0, len(test_graph))

        # enusre that the empty repr produces an empty graph
        test_graph = graph.repr_to_graph(self.empty_repr)
        self.assertEqual(0, len(test_graph))

        # construct a graph from a non-empty repr
        test_graph = graph.repr_to_graph(self.repr1)
        print('created graph from repr %s' % self.repr1)
        print(test_graph)
        self.assertEqual(3, len(test_graph))

        # construct a bigger graph
        test_graph = graph.repr_to_graph(self.repr2)
        print('created graph from repr %s' % self.repr2)
        print(test_graph)
        self.assertEqual(5, len(test_graph))



    #def test_init_graph_adj_list(self) -> None:
    #    # Make an adjacency list
    #    adj_list = [[1,2], [0,2], [2,0]]
    #    g = graph.Graph(adj_list)
    #    self.assertEqual(3, len(g))
    #    # TODO: walk along the graph

    #def test_init_graph_from_repr(self) -> None:
    #    pass


class TestGraphAdjDict(unittest.TestCase):
    def setUp(self) -> None:
        self.test_graph = graph.GraphAdjDict()
        self.test_graph.add_edge(0, 1)
        self.test_graph.add_edge(0, 2)
        self.test_graph.add_edge(1, 2)
        self.test_graph.add_edge(2, 0)
        self.test_graph.add_edge(2, 3)
        self.test_graph.add_edge(3, 3)

        # Graph without cycles
        self.tree_graph1 = graph.GraphAdjDict()
        self.tree_graph1.add_edge(0,1)
        self.tree_graph1.add_edge(0,2)
        self.tree_graph1.add_edge(1,3)
        self.tree_graph1.add_edge(1,4)
        self.tree_graph1.add_edge(2,5)

        # Graph with cycles
        self.cycle_graph1 = graph.GraphAdjDict()
        self.cycle_graph1.add_edge(0, 1)
        self.cycle_graph1.add_edge(1, 0)

        # Diamond graph
        self.cycle_graph2 = graph.GraphAdjDict()
        self.cycle_graph2.add_edge(0, 1)
        self.cycle_graph2.add_edge(0, 2)
        self.cycle_graph2.add_edge(1, 3)
        self.cycle_graph2.add_edge(2, 3)

    def test_graph_dfs(self) -> None:
        self.assertEqual(4, len(self.test_graph))
        exp_dfs = [2, 0, 1, 3]

        print('Generatng DFS traversal for graph %s' % str(self.test_graph))
        out_dfs = self.test_graph.dfs(2)

        for t in out_dfs:
            print(t, end=',')
        print('\n')

        self.assertEqual(len(exp_dfs), len(out_dfs))
        for exp, out in zip(exp_dfs, out_dfs):
            self.assertEqual(exp, out)

    def test_graph_bfs(self) -> None:
        self.assertEqual(4, len(self.test_graph))
        exp_bfs = [2, 0, 3, 1]

        print('Generatng BFS traversal for graph %s' % str(self.test_graph))
        out_bfs = self.test_graph.bfs(2)

        for t in out_bfs:
            print(t, end=',')
        print('\n')

        self.assertEqual(len(exp_bfs), len(out_bfs))
        for exp, out in zip(exp_bfs, out_bfs):
            self.assertEqual(exp, out)

    def test_graph_cycle(self) -> None:
        print('Checking cycle for graph [%s]' % str(self.tree_graph1))
        self.assertEqual(False, self.tree_graph1.has_cycle())
        print('Checking cycle for graph [%s]' % str(self.cycle_graph1))
        self.assertEqual(True, self.cycle_graph1.has_cycle())
        print('Checking cycle for graph [%s]' % str(self.cycle_graph2))
        self.assertEqual(True, self.cycle_graph2.has_cycle())



if __name__ == '__main__':
    unittest.main()
