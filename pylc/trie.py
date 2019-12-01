"""
TRIE
An implementation of a Trie
Taken mostly from here https://leetcode.com/articles/implement-trie-prefix-tree/#

Stefan Wong 2019
"""

def char_to_idx(c:str) -> int:
    if len(c) > 1:
        return 0
    return ord(c) - 'a'


class TrieNode(object):
    def __init__(self, max_links:int=24, is_end:bool=False) -> None:
        self.max_links:int = max_links
        self.is_end:bool   = is_end
        #self.links         = TrieNode(0, False)
        self.links = dict()         # TODO : not strictly correct...

    def __repr__(self) -> str:
        return 'TrieNode'

    def __str__(self) -> str:
        return '%s-%d' % (repr(self), self.max_links)

    #def contains_key(self, key:str) -> bool:
    #    if key in self.links:
    #        return links[key]
    #    return None

    def put(self, w:str, node:'TrieNode') -> None:
        self.links[char_to_idx(w)] = node

    def is_end(self) -> bool:
        return self.is_end

    def set_end(self, e:bool) -> None:
        self.is_end = e



# For now, this is a prefix tree for strings
class Trie(object):
    def __init__(self) -> None:
        self.root = TrieNode()

    def __repr__(self) -> str:
        return 'Trie'

    def __str__(self) -> str:
        return '%s' % (repr(self))

    def insert(self, word:str) -> None:
        TrieNode node = self.root

        for c in range(len(word)):
            if not node.contains(c):
                node.put(c, TrieNode())

