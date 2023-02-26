"""
TEST_GRAPH
Unit tests for Graph object

"""

# unit under test
from pylc import graph

# Tests for new graph





# Tests for old graph
def test_create_graph_empty():
    g = graph.Graph()

    assert len(g) == 0
    assert g.get_children(0) == set()


def test_add_nodes_to_graph():
    # The nodes need to be a list of pairs, where each pair is one edge
    pairs = [
        [0, 1], [0, 2], [1, 3], [1, 2], [2, 3]
    ]

    g1 = graph.Graph()

    # Add the nodes one at time
    for p in pairs:
        g1.add_one(p)

    assert len(g1) == 4    # nodes should be [0, 1, 2, 3], with 3 only connected back to 1 and 2
    assert g1.get_children(0) == set([1, 2])
    assert g1.get_children(1) == set([0, 2, 3])
    assert g1.get_children(2) == set([0, 1, 3])
    assert g1.get_children(3) == set([1, 2])

    # add them all at once
    g2 = graph.Graph()
    g2.add(pairs)

    assert g1 == g2


