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



from pylc import stack

# ==== TOWERS OF HANOI ======== #
#def towers_of_hanoi() -> None:
#    tower1 = stack.Stack()
#    tower2 = stack.Stack()
#    tower3 = stack.Stack()
#
#
#    # for now, lets do the 5 disk case
#    for i in (5,4,3,2,1):
#        tower1.push(i)
#
#    for n, s in enumerate(tower1.array):
#        print(n, s)



def hanoi_simple(num_towers:int=3, num_disks:int=4) -> list:

    towers = [stack.Stack() for _ in range(num_towers)]
    # Init the first tower with disks
    for n in reversed(range(num_disks)):
        towers[0].push(n)

    # TODO : debug only, remove
    print('Tower[0] :')
    print(towers[0])

    print('Moving disks....')
    hanoi_calc(towers, num_disks, 0, 2, 1)

    return towers


def hanoi_calc(towers:list, n:int, src:int, dst:int, buf:int) -> None:

    if n == 1:
        #print('Moving %d from %d -> %d' % (n, src, dst))
        hanoi_move(towers, src, dst)
        # Debug only
        #for n, tow in enumerate(towers):
        #    print(n, tow)
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
    for n, tow in enumerate(towers):
        print(n, tow)


