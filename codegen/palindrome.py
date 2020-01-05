"""
PALINDROME
"""


def is_palindrome_short(word:str) -> bool:
    return word.casefold() == word[::-1].casefold()
