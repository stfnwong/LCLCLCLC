"""
GRAPH
Basic graph representation stuff

"""
from typing import Optional, Sequence, Set
from dataclasses import dataclass
from collections import defaultdict


# TODO: re-writes of this to implement things like Union Find, Prims/Kruskal, etc

@dataclass
class Node:
    verts = []


class Graph:
    def __init__(self):
        self.nodes = defaultdict(set)

    def __len__(self) -> int:
        return len(self.nodes)

    def __eq__(self, other) -> bool:
        if not isinstance(other, Graph):
            return False

        if self.nodes.keys() != other.nodes.keys():
            return False

        for node, edges in self.nodes.items():
            if edges != other.nodes[node]:
                return False

        return True

    def add_one(self, node:Sequence[int], directed:bool=True) -> None:
        self.nodes[node[0]].add(node[1])
        if directed:
            self.nodes[node[1]].add(node[0])

    def add(self, nodes:Sequence[Sequence[int]]) -> None:
        for n in nodes:
            self.add_one(n)

    def remove(self, node:int) -> None:
        for edges in self.nodes.values():
            try:
                edges.remove(node)
            except KeyError:
                pass

        try:
            del self.nodes[node]
        except KeyError:
            pass

    def get_children(self, node:int) -> Set[int]:
        # Prevent creating a new entry
        if node in self.nodes:
            return self.nodes[node]

        return set()



#class Graph:
#    def __init__(self, a:Optional[List[int]]=None) -> None:
#        self.adj = a if a else []
#
#    def __repr__(self) -> str:
#        return 'Graph'
#
#    def __str__(self) -> str:
#        s = []
#        s.append('%s (%d nodes)\n' % (repr(self), len(self)))
#        for n, node in enumerate(self.adj):
#            s.append('  [%d] -> %s\n' % (n, str(node)))
#
#        return ''.join(s)
#
#    def __len__(self) -> int:
#        return len(self.adj)
#
#    def add_node(self, node_adj_list:list) -> None:
#        self.adj.append(node_adj_list)
#
#    def remove_node(self, idx:int) -> None:
#        if idx < len(self):
#            del self.adj[idx]
