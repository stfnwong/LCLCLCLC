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
        s.append('%s :\n    ' % repr(self))
        for elem in self.array:
            s.append(' %s,' % str(elem))

        return ''.join(s)

    def __len__(self) -> int:
        return len(self.array)

    def push(self, elem:Any) -> None:
        self.array.append(elem)

    def pop(self) -> Any:
        return self.array.pop()
