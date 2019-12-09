"""
STACK
Generic stack

Stefan Wong 2019
"""

from typing import Any


class Stack(object):
    def __init__(self) -> None:
        self.array = []

    def __repr__(self) -> str:
        return 'Stack'

    def __str__(self) -> str:
        s = []
        s.append('%s :\n' % repr(self))
        for n, elem in enumerate(reversed(self.array)):
            s.append('[%d]  %s\n' % (len(self.array) - n, str(elem)))

        return ''.join(s)

    def __len__(self) -> int:
        return len(self.array)

    def empty(self) -> bool:
        if len(self) > 0:
            return False

        return True

    def push(self, elem:Any) -> None:
        self.array.append(elem)

    def pop(self) -> Any:
        return self.array.pop()