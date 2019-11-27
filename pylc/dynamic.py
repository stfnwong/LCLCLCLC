"""
DYNAMIC
Dynamic programming stuff

Stefan Wong 2019
"""

# debug
#from pudb import set_trace; set_trace()


# ======== Compute Fibonacci Sequence ======== #
def fibonacci(i:int) -> int:
    if i == 0 or i == 1:
        return i

    return fibonacci(i - 1) + fibonacci(i - 2)


# ---- Memoized implementation
def fibonacci_memo(i:int) -> int:
    memo    = [0 for _ in range(i+2)]
    return _fibonacci_memo_inner(i, memo)


def _fibonacci_memo_inner(i:int, memo:list) -> int:
    if i == 0 or i == 1:
        return i

    if memo[i] == 0:
        memo[i] = _fibonacci_memo_inner(i - 1, memo) + _fibonacci_memo_inner(i - 2, memo)

    return memo[i]
