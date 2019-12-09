"""
GRAPH
Basic graph representation stuff

Stefan Wong 2019
"""

from typing import List
from pylc import queue


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

        # bookkeeping for iteration
        self.idx = 0

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

    # How many neighbours?
    def __len__(self) -> int:
        return len(self.neighbours)

    # Iteration
    def __iter__(self) -> 'GraphNode':
        return self

    def __next__(self) -> 'GraphNode':
        self.idx += 1
        if (self.idx-1) < len(self.neighbours):
            return self.neighbours[idx - 1]

        raise StopIteration

    def __getitem__(self, idx:int) -> 'GraphNode':
        if idx < 0:
            raise IndexError

        if idx < len(self.neighbours):
            return self.neighbours[idx]
        else:
            raise IndexError

    def add_neighbour(self, n:'GraphNode') -> None:
        self.neigbours.append(n)

    def remove_neighbour(self, idx:int) -> None:
        if (idx >= 0) and (idx < len(self.neighbours)):
            del self.neighbours[idx]


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

    def _path_bfs_inner(self, src:GraphNode, dst:GraphNode, visited:set) -> bool:
        bfs_q = queue.Queue()
        visited.add(src)

        bfs_q.enqueue(src)
        while(not bfs_q.empty()):
            node = bfs_q.dequeue()
            # If this is the node we are looking for, then there is a path
            if node == dst:
                return True

            # If we've seen this node before, then skip
            if node.node_id in visisted:
                continue

            # Put all the children of this node into the queue
            visited.add(node)
            for child in node:
                bfs_q.enqueue(child)

        return False

    # Methods to return the actual traversal as a list
    def _dfs_inner(self, src:GraphNode, dst:GraphNode, visited:set) -> list:
        pass

    def _bfs_inner(self, src:GraphNode, dst:GraphNode, visited:set) -> list:
        pass

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
        visited = set()         # NOTE : could also do this with a list (if the graph is implemented as an array)

        return self._path_dfs_inner(src, dst, visited)

    def has_path_bfs(self, src_id:int, dst_id:int) -> bool:
        # TODO : need a queue here
        visited = set()
        return self._path_bfs_inner(src, dst, visited)


class GraphAdjDict:
    """
    GraphAdjDict
    Another Graph implementation based on an adjacency list.
    Adjacency list is implemented with a dict.
    """
    def __init__(self, adj_dict:dict=None) -> None:
        if adj_dict is None:
            self.graph = dict()
        else:
            self.graph = adj_dict

    def __repr__(self) -> str:
        return 'GraphAdjDict'

    def __str__(self) -> str:
        return '%s (%d nodes)' % (repr(self), len(self))

    def __len__(self) -> int:
        return len(self.graph)

    # Internal methods (ie: inner of paths, etc)
    def _dfs_path_inner(self, src:int, dst:int, visited:set) -> list:
        visited.add(src)
        # TODO : find path

    def _bfs_path_inner(self, src:int, dst:int, visited:set) -> list:
        visited.add(src)
        # TODO : find path

    # Built in traversals
    def _dfs_inner(self, src:int, visited:dict, traversal:list) -> list:
        traversal = []
        visited[src] = True

        for child in self.graph[src]:
            print(child)

        return traversal

    def _bfs_inner(self, src:int, visited:dict) -> list:
        bfs_q     = queue.Queue()
        traversal = []
        visited   = dict()

        bfs_q.enqueue(src)
        visited[src] = True

        while(not bfs_q.empty()):
            node = bfs_q.dequeue()
            traversal.append(self.graph[node])

            # visit children
            for n in self.graph[node]:
                if visited[n] == False:
                    bfs_q.enqueue(n)
                    visited[n] = True

        return traversal

    def add_edge(self, k:int, v:int) -> None:
        if k not in self.graph:
            self.graph[k] = []

        self.graph[k].append(v)

    def bfs(self, src:int) -> list:
        visited = dict()
        return self._bfs_inner(src, visited)

    def dfs(self, src:int) -> list:
        visited = dict()
        return self._dfs_inner(src, visited, [])

    def bfs_path(self, src:int, dst:int) -> list:
        pass
        visited = set()
        return self._bfs_path_inner(src, visited)

    def dfs_path(self, src:int, dst:int) -> list:
        visited = set()
        return self._dfs_path_inner(src, visited)


#class GraphAdjList(object):
#    """
#    GraphAdjList
#
#    Same idea, but the adjaceny list is a literal list.
#    """
#    def __init__(self, adj_list:list=[], **kwargs) -> None:
#        self.adj = adj_list
#
#    def __repr__(self) -> str:
#        return 'GraphAdjList'
#
#    def __len__(self) -> int:
#        return len(self.adj_list)
#
#    def add_node(self, node_adj_list:list) -> None:
#        self.adj.append(node_adj_list)
#
#    def remove_node(self, idx:int) -> None:
#        if idx < len(self):
#            del self.adj[idx]
#

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


