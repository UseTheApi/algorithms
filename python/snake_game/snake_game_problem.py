
"""
Title: Growing Snake
Problem: A snake obeys two rule:
        * it always grows (move by 1 = has grown by 1)
        * it turns only to the right ( 0 in the input stream represents a turn. 0 cannot be followed by another 0 )

Given a random input of integers (where 0 represents a turn). Determine whether snakes crashes into itself
(map has no wals or borders)
"""


def optimize_input(input_stream):
    """
    Function collects only moves, gets rid of 0 and trailing integers (summing them up)
    :param input_stream: integers in format of: [3, 0, 3, 0, 1, 1, 0, 5]
    :type input_stream: list
    :return: optimized list
    """
    clear_input = list()
    index = 0

    while index < len(input_stream) - 1:
        cur = input_stream[index]
        index += 1
        if cur == 0:
            continue
        while input_stream[index] != 0:
            cur += input_stream[index]
            index += 1
        clear_input.append(cur)

    clear_input.append(input_stream[index])
    return clear_input


def detect_crash(clear_stream: list):
    """
    Function compares possible intersections.
    The trick is that each item we have to compare with 3d and 5th item in the input.
    :param clear_stream: integers without 0s indicating moves of a snake
    :type clear_stream: list
    :return: bool - True if intersection found
    """
    i = 0
    while i < len(clear_stream) - 3:
        delta = 0
        if clear_stream[i+2] < clear_stream[i]:
            if clear_stream[i+1] <= clear_stream[i+3]:
                return True
        else:
            delta = clear_stream[i+2] - clear_stream[i]

        if clear_stream[i] + delta > clear_stream[i+4]:
            if i + 5 >= len(clear_stream):
                return False
            if clear_stream[i+3] - clear_stream[i+1] <= clear_stream[i+5]:
                return True
        i += 1
    return False


if __name__ == "__main__":
    print("Snake Problem")

    # Intersecting examples

    # input_s = [3, 0, 3, 0, 1, 1, 0, 5]
    # input_s = [3, 0, 3, 0, 4, 0, 4, 0, 3, 0, 2]
    # input_s = [3, 0, 3, 0, 2, 0, 2, 0, 3]
    # input_s = [3, 0, 3, 0, 2, 0, 2, 0, 1, 0, 3]
    # input_s = [3, 0, 3, 0, 4, 0, 2, 2, 0, 5, 0, 3, 0, 2]
    # input_s = [3, 0, 3, 0, 4, 0, 4, 0, 2, 3, 0, 5, 0, 3, 0, 2]
    # input_s = [3, 0, 3, 0, 2, 0, 2, 0, 1, 0, 1, 0, 2]

    # Not intersecting examples

    input_s = [3, 0, 2, 0, 4, 0, 3, 0, 3, 2, 1, 0, 4, 0, 7, 0, 2]

    cl = optimize_input(input_s)
    print(cl)
    print(detect_crash(cl))

