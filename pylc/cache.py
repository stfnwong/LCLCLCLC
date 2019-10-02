"""
CACHE
Cache algorithms in python. Actually I stole quite a lot
of this from another LeetCode example.

Stefan Wong 2019
"""


# A node in a cache object
class CacheNode(object):
    def __init__(self, key:int, val:int) -> None:
        self.key:int = key
        self.val:int = val
        self.prev = None
        self.next = None

    def __repr__(self) -> str:
        return "[%s] : %s" % (str(self.key), str(self.val))

    def __str__(self) -> str:
        return self.__repr__()


# Least Recently Used cache
class LRUCache(object):
    def __init__(self, capacity:int) -> None:
        self.capacity:int = capacity
        if self.capacity <= 0:
            raise ValueError('Capacity must be > 0')

        self.head = None
        self.end  = None
        self.cur_size = 0
        self.hashmap = dict()

    def __repr__(self) -> str:
        return 'LRUCache [%s] cur size : %d' % (str(self.capacity), self.cur_size)

    def __str__(self) -> str:
        s = []
        s.append('[head: %s, end: %s\n' % (str(self.head), str(self.end)))
        n = self.head
        while n:
            s.append('%s -> ' % str(n))
            n = n.prev

        s.append('\n')
        return ''.join(s)

    def get(self, key:int) -> int:
        
        if key not in self.hashmap:
            return -1

        node = self.hashmap[key]
        # if we are looking at head then just return value
        if self.head == node:
            return node.val
        self.remove(node)
        self.set_head(node)
        
        return node.val

    def set(self, key:int, value:int) -> None:
        if key in self.hashmap:
            # update the existing value
            node = self.hashmap[key]
            node.val = value

            if self.head != node:
                self.remove(node)
                self.set_head(node)
        else:
            new_node = CacheNode(key, value)
            if self.cur_size == self.capacity:
                del self.hashmap[self.end.key]
                self.remove(self.end)
            self.set_head(new_node)
            self.hashmap[key] = new_node

    def set_head(self, node:CacheNode) -> None:
        if not self.head:
            self.head = node
            self.end = node
        else:
            node.prev = self.head
            self.head.next = node
            self.head = node

        self.cur_size += 1

    def remove(self, node:CacheNode) -> CacheNode:
        if not self.head:
            return 

        # Remove a node from somewhere in the middle. Update pointers
        if node.prev:
            node.prev.next = node.next
        if node.next:
            node.next.prev = node.prev

        # head == end == node
        if (not node.next) and (not node.prev):
            self.head = None
            self.end = None

        # If the node being removed is at the end, update the new end. Also for 
        # the sake of completeness set the end previous to be NULL.
        if self.end == node:
            self.end = node.next
            self.end.prev = None

        self.cur_size -= 1
        
        return node
