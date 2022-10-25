# Those functions that fit nowhere else

def check_fib_property(seq: List[int]) -> bool:
    """
    Ensure the fib property holds, eg: that
    seq[n] = seq[n-1] + seq[n-2]
    """

    if len(seq) <= 2:
        return True

    for idx in range(2, len(seq)):
        if seq[idx] != seq[idx-1] + seq[idx-2]:
            return False

    return True

