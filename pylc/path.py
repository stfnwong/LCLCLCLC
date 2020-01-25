"""
PATH
Quick shortest path experiment

Stefan Wong 2020
"""

import re
from typing import Tuple


class Graph:
    def __init__(self) -> None:
        self.nodes = set()
        self.edges = dict()
        self.distances = dict()

    def __repr__(self) -> str:
        return 'Graph (%d nodes, %d edges)' % (len(self.nodes), len(self.edges))

    def add_node(self, value:int) -> None:
        self.nodes.add(value)

    def add_edge(self, node_from:int, node_to:int, weight:float=1.0, bidir:bool=True) -> None:
        if node_from not in self.edges:
            self.edges[node_from] = []

        if node_from not in self.nodes:
            self.nodes.add(node_from)

        if node_to not in self.nodes:
            self.nodes.add(node_to)

        self.edges[node_from].append(node_to)
        self.distances[node_from] = weight
        if bidir:
            if node_to not in self.edges:
                self.edges[node_to] = []

            self.edges[node_to].append(node_from)
            self.distances[node_to] = weight

    def get_num_nodes(self) -> int:
        return len(self.nodes)

    def get_num_edges(self) -> int:
        num_edges = 0
        for k in self.edges:
            num_edges += len(self.edges[k])

        return num_edges

    def get_nodes(self) -> dict:
        return self.nodes

    def get_edges(self) -> dict:
        return self.edges


def dijsktra(graph:Graph, start:int) -> Tuple[dict, dict]:
    visited = {start: 0}
    path    = dict()

    nodes = set(graph.get_nodes())

    while nodes:
        min_node = None
        # Walk over the neighbours
        for node in nodes:
            if node in visited:
                if (min_node is None):
                    min_node = node
            elif (visited[node] < visited[min_node]):
                min_node = node

        if min_node is None:
            break

        nodes.remove(min_node)
        cur_weight = visited[min_node]


#from pudb import set_trace; set_trace()


def graph_from_file(filename:str, bidir:bool=True) -> Graph:
    """
    graph_from_file

    Read a graph description from a text file and transform into a
    graph object
    """

    text = []
    with open(filename, 'r') as fp:
        for line in fp:
            text.append(line.strip('\n'))

    # Now each line is an element in this list of strings
    # First line is number of verticies
    num_verticies = int(text[0])
    # Second line is number of edges
    num_edges     = int(text[1])
    num_fails     = 0
    which_fails   = []

    out_graph = Graph()
    # Each of the following lines is a vertex in the graph
    for n in range(2, len(text)):
        # Make a regex to extract numbers
        text_nums = re.findall('\d+\.?\d*', repr(text[n].split(' ')))

        try:
            out_graph.add_edge(
                int(text_nums[0]),
                int(text_nums[1]),
                float(text_nums[2]),
                bidir = bidir
            )
        except:
            num_fails += 1
            which_fails.append(n)
            print('Failed vertex text was %d:%s' % (n, repr(text_nums)))
            pass

    # TODO : Maybe I want proper logging here at some point
    print('Caught %d failing edges' % num_fails)
    if num_fails > 0:
        print(which_fails)

    #check here that we have the expected number of edges
    if bidir:
        if (2 * num_edges) != out_graph.get_num_edges():
            print('Expected to get %d edges, but final graph has %d edges' %\
                (2 * num_edges, out_graph.get_num_edges())
            )
    else:
        if num_edges != out_graph.get_num_edges():
            print('Expected to get %d edges, but final graph has %d edges' %\
                (num_edges, out_graph.get_num_edges())
            )

    return out_graph
