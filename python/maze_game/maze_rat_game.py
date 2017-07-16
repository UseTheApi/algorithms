"""
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e.,
maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1].
A rat starts from source and has to reach destination. The rat can move only in two directions: forward and down.
In the maze matrix, 0 means the block is dead end and
1 means the block can be used in the path from source to destination.
Note that this is a simple version of the typical Maze problem.
For example, a more complex version can be that the rat can move in 4 directions
and a more complex version can be with limited number of moves.
"""


def find_exit(matrix):
    """
    This function represents a backtracking solution for this maze game.
    This function looks for a valid path and returns a track
    :param matrix: given map
    :return: track of moves
    """
    raw = 0
    col = 0
    track = [(raw, col)]
    max_n = len(matrix)-1

    while not (max_n, max_n) in track and track:
        if raw < max_n and matrix[raw+1][col] == 1:
            raw += 1
            track.append((raw, col))
        elif col < max_n and matrix[raw][col+1] == 1:
            col += 1
            track.append((raw, col))
        else:
            matrix[raw][col] = 0
            track.pop()
            raw, col = track[-1]
    return track


def count_paths(matrix, raw, col):
    """
    This function counts all possible valid paths from starting point to an exit
    recursively
    :param col:
    :param raw:
    :param matrix: given map
    :return: number of valid paths
    """
    if raw >= len(matrix) or col >= len(matrix) or not matrix[raw][col]:
        return 0
    if raw == len(matrix)-1 and col == len(matrix)-1:
        return 1
    return count_paths(matrix, raw+1, col) + count_paths(matrix, raw, col+1)


def count_paths_dp(matrix):
    """
    This function counts all possible valid paths from starting point to an exit
    dynamic programming
    :param matrix: given map
    :return: number of valid paths
    """
    for raw in range(len(matrix)-1, -1, -1):
        for col in range(len(matrix)-1, -1, -1):
            if raw == len(matrix)-1 and col == len(matrix)-1:
                continue
            if raw == len(matrix)-1:
                mat[raw][col] = mat[raw][col+1] if mat[raw][col] else 0
            elif col == len(matrix)-1:
                mat[raw][col] = mat[raw+1][col] if mat[raw][col] else 0
            else:
                mat[raw][col] = mat[raw+1][col] + mat[raw][col+1] if mat[raw][col] else 0
    return mat[0][0]


if __name__ == "__main__":
    mat = [
        [
            1, 1, 1, 1, 1, 1
        ],
        [
            1, 1, 0, 1, 1, 1
        ],
        [
            0, 1, 1, 1, 0, 1
        ],
        [
            1, 1, 0, 1, 1, 1
        ],
        [
            1, 0, 1, 1, 1, 1
        ],
        [
            1, 1, 1, 1, 0, 1
        ]
    ]

    print(find_exit(matrix=mat.copy()))
    print(count_paths(mat.copy(), 0, 0))
    print(count_paths_dp(mat.copy()))
