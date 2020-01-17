"""
PATH
Quick shortest path experiment

Stefan Wong 2020
"""


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

        #return len(self.edges)


#from pudb import set_trace; set_trace()


def graph_from_file(filename:str, bidir:bool=True) -> Graph:
    text = []
    with open(filename, 'r') as fp:
        for line in fp:
            text.append(line.strip('\n'))

    # Now each line is an element in this list of strings
    # First line is number of verticies
    num_verticies = int(text[0])
    # Second line is number of edges
    num_edges     = int(text[1])

    out_graph = Graph()
    # Each of the following lines is a vertex in the graph
    for n in range(2, len(text)):
        vertex_text = text[n].lstrip(' ').split(' ')
        # TODO : this is dumb, but it will work to handle leading spaces
        for n in range(len(vertex_text)):
            if vertex_text[n] == '':
                del vertex_text[n]
                break

        try:
            out_graph.add_edge(
                int(vertex_text[0]),
                int(vertex_text[1]),
                float(vertex_text[2]),
                bidir = bidir
            )
        except:
            pass

    #check here that we have the expected number of edges
    if num_edges != out_graph.get_num_edges():
        print('Expected to get %d edges, but final graph has %d edges' %\
              (num_edges, out_graph.get_num_edges())
        )

    return out_graph
