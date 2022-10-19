from pylc import pointer



def test_two_sum():

    targets = [9, 6, 6]
    inputs = [
        [2, 7, 11, 15],
        [3, 2, 4],
        [3, 3]
    ]

    exp_outputs = [
        [0, 1],
        [1, 2],
        [0, 1]
    ]

    functions = [
        pointer.two_sum_hashmap_1,
        pointer.two_sum_sort_1
    ]

    for func, target, inp, exp_out in zip(
        functions,
        targets,
        inputs,
        exp_outputs
    ):
        output = func(inp, target)
        assert output == exp_out
