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

    for func in functions:
        print(f"Testing function [{func.__name__}]")
        for target, inp, exp_out in zip(
            targets,
            inputs,
            exp_outputs
        ):
            output = func(inp, target)
            assert output == exp_out



def test_lc_167():

    targets = [9, 6, -1]
    inputs = [
        [2, 7, 11, 15],
        [2, 3, 4],
        [-1, 0]
    ]

    exp_outputs = [
        [1, 2],
        [1, 3],
        [1, 2]
    ]

    functions = [
        pointer.two_sum_ii_2p_lc_167
    ]

    for func in functions:
        print(f"Testing function [{func.__name__}]")
        for target, inp, exp_out in zip(
            targets,
            inputs,
            exp_outputs
        ):
            print(f"inp:  {inp}")
            output = func(inp, target)
            assert output == exp_out

