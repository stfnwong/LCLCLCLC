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

    def __len__(self) -> int:
        return len(self.array)

    def push(self, elem:Any) -> None:
        self.array.append(elem)

    def pop(self) -> Any:
        return self.array.pop()
