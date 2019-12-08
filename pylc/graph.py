"""
GRAPH
Basic graph representation stuff

Stefan Wong 2019
"""

from typing import List


class GraphNode(object):
    """
    GraphNode
    A single node in a graph.
    """
    def __init__(self, key:int=0, val:int=0, node_id:int=0) -> None:
        self.key:int = key
        self.val:int = val
        self.node_id:int = node_id
        self.neighbours:list = []

    def __repr__(self) -> None:
        return 'GraphNode'

    def __str__(self) -> None:
        return '%s <%s> [%s]: %s' % (repr(self), str(self.node_id), str(self.key), str(self.val))

    def __eq__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.node_id == that.node_id
        else:
            return self.node_id == that

    def __ne__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.node_id != that.node_id
        else:
            return self.node_id != that

    def __lt__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.node_id < that.node_id
        else:
            return self.node_id < that

    def __le__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.node_id <= that.node_id
        else:
            return self.node_id <= that

    def __gt__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.node_id > that.node_id
        else:
            return self.node_id > that

    def __gt__(self, that:'GraphNode') -> bool:
        if isinstance(that, GraphNode):
            return self.node_id >= that.node_id
        else:
            return self.node_id >= that

    # TODO : iteratable?

    def add_neighbour(self, n:'GraphNode') -> None:
        self.neigbours.append(n)




class Graph(object):
    """
    GRAPH
    Adjacency list graph. This object contains a set of GraphNodes that are
    connected in some fashion.
    """
    def __init__(self, node_list:List[GraphNode]=None) -> None:
        self.nodes = dict()
        if node_list is not None:
            for n in node_list:
                self.nodes[n.node_id] = n

    def __repr__(self) -> str:
        return 'Graph'

    def __str__(self) -> str:
        s = []
        s.append('%s (%d nodes)\n' % (repr(self), len(self)))
        for n, node in enumerate(self.nodes):
            s.append('  [%d] -> %s\n' % (n, str(node)))

        return ''.join(s)

    def __len__(self) -> int:
        #  The 'size' of the graph (number of nodes)
        return len(self.nodes)

    # Internal path finding methods
    def _path_dfs_inner(self, src:GraphNode, dst:GraphNode, visited:set) -> bool:
        if src.node_id in visited:
            return False

        visited.add(src.node_id)
        # if the src and dst are the same, then a path exists
        if src == dst:
            return True

        # Now iterate over the children of src
        for child in src.neighbours:
            if self._path_dfs_inner(child, dst, visited):
                return True

        # We tried all the children from here and found nothing,
        # therefore there is no path from this location to elsewhere
        return False

    # TODO : do we need to bother doing a check here? Doesn't
    # python3 do that already?
    def add_node(self, node:GraphNode) -> None:
        self.nodes[node.node_id] = node

    def get_node_by_id(self, node_id:int) -> GraphNode:
        if node_id in self.nodes:
            return self.nodes[node_id]
        else:
            return None

    # External path-finding API
    def has_path_dfs(self, src_id:int, dst_id:int) -> bool:
        if (src_id not in self.nodes) or (dst_id not in self.nodes):
            return False

        src     = self.nodes[src_id]
        dst     = self.nodes[dst_id]
        visited = set()

        return self._path_dfs_inner(src, dst, visited)

    def has_path_bfs(self, src_id:int, dst_id:int) -> bool:
        # TODO : need a queue here
        pass


class GraphAdjList(object):
    """
    GraphAdjList

    Same idea, but the adjaceny list is a literal list.
    """
    def __init__(self, adj_list:list=[], **kwargs) -> None:
        self.adj = adj_list

    def __repr__(self) -> str:
        return 'GraphAdjList'

    def __len__(self) -> int:
        return len(self.adj_list)

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


