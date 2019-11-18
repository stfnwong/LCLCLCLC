"""
GRAPH
Basic graph representation stuff

Stefan Wong 2019
"""


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

# Various traversals


