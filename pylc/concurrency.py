"""
CONCURRENCY
Leetcode concurrency questions.
It seems odd to try and do concurrecy stuff in Python, but I'll try to breeze through
this and move onto C++ in short order

Stefan Wong 2019
"""

import threading
from typing import Callable

# Note that in the original questions each question is encapsulated in
# a class specific to that question (as opposed to the generic Solution
# class that most questions are wrapped in).


"""
Question 1114: Print in Order
"""
# Helper functions for question
def printFirst() -> None:
    print('first')

def printSecond() -> None:
    print('second')

def printThird() -> None:
    print('third')

# TODO : for each possible solution create a new object/derived object
# so that they can be profiled against each other

# Main body of question
class Question1114:
    def __init__(self) -> None:
        pass

    def first(self, printFirst: Callable[[], None]) -> None:
        printFirst()

    def second(self, printSecond: Callable[[], None]) -> None:
        printSecond()

    def third(self, printThird: Callable[[], None]) -> None:
        printThird()
