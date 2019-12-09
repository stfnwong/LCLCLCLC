"""
QUEUE
A really basic queue

Stefan Wong 2019
"""

from typing import Any


class Queue:
    def __init__(self, size:int=0) -> None:
        self.size = size
        self.q = []

    def __repr__(self) -> str:
        return 'Queue'

    def __str__(self) -> str:
        return "%s [%d]" % (repr(self), self.size)

    def __len__(self) -> str:
        return len(self.q)

    def full(self) -> bool:
        if (self.size > 0) and (len(self.q) == self.size):
            return True

        return False

    def empty(self) -> bool:
        if len(self.q) == 0:
            return True

        return False

    def max_size(self) -> int:
        return self.size

    def enqueue(self, item:Any) -> None:
        if self.size == 0:
            self.q.append(item)
        elif len(self.q) < self.size:
            self.q.append(item)

    def dequeue(self) -> Any:
        return self.q.pop(0)
