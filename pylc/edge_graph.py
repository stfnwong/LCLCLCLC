"""
EDGE_GRAPH
Edge-weighted directed graph. This is a sort of adaption of the
graph from (https://algs4.cs.princeton.edu/44sp/).

Stefan Wong 2020
"""

from typing import List
from typing import Tuple


class DirectedEdge:
    def __init__(self, v:int=0, w:int=0, weight:float=0.0) -> None:
        self.v:int        = v      # aka: from
        self.w:int        = w      # aka: to
        self.weight:float = weight

    def __repr__(self) -> str:
        return 'DirectedEdge'

    def __str__(self) -> str:
        return '%s (%d -> %d [%3.2f])' % (repr(self), self.w, self.v, self.weight)

    def get_from(self) -> int:
        return self.v

    def get_to(self) -> int:
        return self.w



class EdgeWeightedDigraph:
    """
    EdgeWeightedDigraph

    Implementes an edge-weighted directed graph
    """
    def __init__(self, **kwargs) -> None:
        self.adj:dict      = {}
        self.indegree:dict = {}
        self.E     = 0

        # Deal with keyword args
        self.verbose:bool = kwargs.pop('verbose', False)

    def __repr__(self) -> str:
        return 'EdgeWeightedDigraph'

    def __str__(self) -> str:
        s = []
        s.append('[%s] (%d verticies, %d edges)\n' %\
                 (repr(self), self.num_verticies(), self.num_edges())
        )

        for k, edges in self.adj.items():
            s.append('    ')
            for e in edges:
                s.append('%s ' % str(e))
            s.append('\n')

        return ''.join(s)

    #def _validate_vertex(self, v:int) -> bool:
    #    if (v < 0) or (v >= len(self.adj)):
    #        if self.verbose:
    #            print('Vertex %d is not between 0 and %d' %\
    #                  (v, len(self.adj))
    #            )
    #        return False

    #    return True

    def num_verticies(self) -> int:
        return len(self.adj)

    def num_edges(self) -> int:
        return self.E

    def add_edge(self, edge:DirectedEdge) -> None:
        if edge.get_from() not in self.adj:
            self.adj[edge.get_from()] = []
            self.indegree[edge.get_from()] = 0

        self.adj[edge.get_from()].append(edge)
        self.indegree[edge.get_from()] += 1
        self.E += 1

    def get_edge(self, k:int) -> DirectedEdge:
        if k not in self.adj:
            return None
        return self.adj[k]

    def get_edges(self) -> dict:
        return self.adj


# NOTE: its actually debatable if an object oriented approach is really
# useful here, but lets so it anyway for now
#class EWDPathFinder:
#    def __init__(self, graph:EdgeWeightedDigraph, start:int=0, **kwargs) -> None:
#        self.graph:EdgeWeightedDigraph = graph
#        self.start:int = start
#
#    def __repr__(self) -> str:
#        return 'EWDPathFinder'
#
#    def dist_to(self, dest:int) -> float:
#        pass
#
#    def path_to(self, dest:int) -> List[DirectedEdge]:
#        pass

#from pudb import set_trace; set_trace()


def ewd_dijsktra(graph:EdgeWeightedDigraph, start:int) -> Tuple[dict, dict]:

    # Visited maps graph to known distances
    visited = {start: 0}
    path    = {}

    nodes = set(graph.get_edges())

    while nodes:
        min_node = None
        # start visiing neighbours
        for node in gra[:
            print(node)

    return (None, None)


def graph_from_file(filename:str, **kwargs) -> EdgeWeightedDigraph:
    """
    GRAPH_FROM_FILE
    Read file and generate corresponding Edge-weighted Digraph
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

    out_graph = EdgeWeightedDigraph(**kwargs)
    # Each of the following lines is a vertex in the graph
    for n in range(2, len(text)):
        vertex_text = text[n].lstrip(' ').split(' ')
        # TODO : this is dumb, but it will work
        for n in range(len(vertex_text)):
            if vertex_text[n] == '':
                del vertex_text[n]
                break

        try:
            edge = DirectedEdge(
                int(vertex_text[0]),
                int(vertex_text[1]),
                float(vertex_text[2])
            )
        except:
            pass
        #except Exception as e:
        #    print('Got exception %s' % str(e))

        out_graph.add_edge(edge)

    #check here that we have the expected number of edges
    if num_edges != out_graph.num_edges():
        print('Expected to get %d edges, but final graph has %d edges' %\
              (num_edges, out_graph.num_edges())
        )

    return out_graph
