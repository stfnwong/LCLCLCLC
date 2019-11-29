"""
DYNAMIC
Dynamic programming stuff

Stefan Wong 2019
"""

from pylc import stack
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


# --- Iterative implementation
def fibonacci_iter(i:int) -> int:
    if i == 0 or i == 1:
        return i

    fib    = [0 for _ in range(i+1)]
    fib[1] = 1

    for n in range(2, i+1):
        fib[n] = fib[n-1] + fib[n-2]

    return fib[i]


def fibonacci_iter_const_space(i:int) -> int:
    # We can do this in constant space since we don't need
    # to store all the previous sums
    if i == 0 or i == 1:
        return i

    f_oldest = 0
    f_old = 1
    f_cur = 0

    for f in range(2, i+1):
        f_cur = f_old + f_oldest
        f_oldest = f_old
        f_old = f_cur
        # ye olde print style debug

    return f_cur


# Fastest would be a direct form - not going to bother for now


# ==== TOWERS OF HANOI ======== #

def hanoi_simple(num_towers:int=3, num_disks:int=4, verbose:bool=False) -> list:
    towers = [stack.Stack() for _ in range(num_towers)]
    # Init the first tower with disks
    for n in reversed(range(num_disks)):
        towers[0].push(n)

    if verbose:
        print('Tower[0] :')
        print(towers[0])
        print('Moving disks....')

    hanoi_calc(towers, num_disks, 0, 2, 1)

    return towers


def hanoi_calc(towers:list, n:int, src:int, dst:int, buf:int) -> None:
    if n == 1:
        hanoi_move(towers, src, dst)
    else:
        # here we implement the logic to reduce the movement problem down
        # to a single disk
        hanoi_calc(towers, n-1, src, buf, dst)      # buffer the disk below
        hanoi_calc(towers, 1, src, dst, buf)        # move the disk below from src->dst
        hanoi_calc(towers, n-1, buf, dst, src)      # move disks off the buffer and towards the dst


def hanoi_move(towers:list, src:int, dst:int) -> None:
    disk = towers[src].pop()
    towers[dst].push(disk)

    print('Moving disk from %d -> %d' % (src, dst))
