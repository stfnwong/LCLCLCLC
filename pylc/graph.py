"""
GRAPH
Basic graph representation stuff

Stefan Wong 2019
"""

class GraphNode(object):
    def __init__(self, key:int=0, val:int=0) -> None:
        self.key:int = key
        self.val:int = val
        self.neighbours:list = []

    def __repr__(self) -> None:
        return 'GraphNode'

    def __repr__(self) -> None:
        return '%s [%s]: %s' % (repr(self), str(self.key), str(self.val))

    def __eq__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.key == that.key
        else:
            return self.key == that

    def __lt__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.key < that.key
        else:
            return self.key < that

    def __lte__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.key <= that.key
        else:
            return self.key <= that

    def __gt__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.key > that.key
        else:
            return self.key > that

    def __gte__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.key >= that.key
        else:
            return self.key >= that

    def add_neighbour(self, n:'GraphNode') -> None:
        self.neigbours.append(n)



class Graph(object):
    """
    GRAPH
    Adjacency list graph
    """
    def __init__(self, adj_list:list=[], **kwargs) -> None:
        self.adj = adj_list

    def __repr__(self) -> str:
        return 'Graph'

    def __str__(self) -> str:
        s = []
        s.append('%s (%d nodes)\n' % (repr(self), len(self)))
        for n, node in enumerate(self.adj):
            s.append('  [%d] -> %s\n' % (n, str(node)))

        return ''.join(s)

    def __len__(self) -> int:
        return len(self.adj)

    def add_node(self, node_adj_list:list) -> None:
        self.adj.append(node_adj_list)

    def remove_node(self, idx:int) -> None:
        if idx < len(self):
            del self.adj[idx]


# repr to graph?
def repr_to_graph(graph_repr:str) -> Graph:

    if graph_repr == "{}":  # check for valid empty graph
        return None

    # Check braces and strip
    # TODO : could just return NULL so we can move on....?
    if graph_repr[0] != '{' or graph_repr[-1] != '}':
        raise ValueError('Invalid repr %s' % str(graph_repr))

    # Crop the braces out
    graph_repr = graph_repr[1 : -1]
    # tokenize the string along node boundaries
    token_list = graph_repr.split('#')

    # TODO : need two passes through the data to do this
    # first pass finds all the nodes,
    # second pass finds all the neighbours
    for n, tok in enumerate(token_list):
        nsplit = tok.split(',')     # split neighour string
        cur_node = GraphNode(nsplit[0], 0)
        for s in nsplit[1:]:
            cur_node.add_neighbour(int(s))




# Various traversals


