"""
The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.
For example, following is a solution for 4 Queen problem:

The expected output is a binary matrix which has 1s for the blocks where queens are placed.
For example following is the output matrix for above 4 queen solution.

              { 0,  1,  0,  0}
              { 0,  0,  0,  1}
              { 1,  0,  0,  0}
              { 0,  0,  1,  0}
"""


def is_safe(positions, row, col):
    for queen in range(row):
        if positions[queen][1] == col \
                or (positions[queen][0] + positions[queen][1] == row + col) \
                or (positions[queen][0] - positions[queen][1] == row - col):
            return False
    return True


def place_n_queens(positions, row, num_of_queens):
    if row == num_of_queens:
        return True
    for col in range(num_of_queens):
        if is_safe(positions, row, col):
            positions[row] = (row, col)
            if place_n_queens(positions, row+1, num_of_queens):
                return True
    return False


def find_one_n_queens(num_of_queens):
    positions = [(0, 0)]*num_of_queens
    if place_n_queens(positions, 0, num_of_queens):
        return positions
    else:
        return positions[0]


def place_queens_collect_positions(result, positions, row, num_of_queens):
    if row == num_of_queens:
        result.append(positions)
        return
    for col in range(num_of_queens):
        if is_safe(positions, row, col):
            positions[row] = (row, col)
            place_queens_collect_positions(result, positions, row+1, num_of_queens)


def find_all_n_queens(num_of_queens):
    positions = [(0, 0)] * num_of_queens
    result = list()
    place_queens_collect_positions(result, positions, 0, num_of_queens)
    return result


if __name__ == "__main__":
    print(find_all_n_queens(4))
