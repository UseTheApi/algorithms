"""
Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands

Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}
Output : 5

This is an variation of the standard problem: “Counting number of connected components in a undirected graph”.
"""

neighbours_positions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
num_of_neighbours = 8


def is_save(matrix, cur_pos, visited):
    return (0 <= cur_pos[0] < len(matrix) and 0 <= cur_pos[1] < len(matrix)) \
           and \
           (matrix[cur_pos[0]][cur_pos[1]] and not visited[cur_pos[0]][cur_pos[1]])


def check_neighbours(matrix, cur_pos, visited):
    """
    Do DFS-visit through neighbours until find 0 or not valid index
    :param matrix: given map
    :param cur_pos: tuple of current position
    :param visited: map of visited cells
    :return: None
    """
    visited[cur_pos[0]][cur_pos[1]] = True

    for i in range(num_of_neighbours):
        cur_neighbour = (cur_pos[0]+neighbours_positions[i][0], cur_pos[1]+neighbours_positions[i][1])
        if is_save(matrix, cur_neighbour, visited):
            check_neighbours(matrix, cur_neighbour, visited)


def init_visited(matrix):
    visited = [0] * len(matrix)
    for i in range(len(matrix)):
        visited[i] = [0] * len(matrix)
    return visited


def count_islands(matrix):
    """
    DFS for searching islands. Counts how many times DFS-visit is called
    :param matrix: given map
    :return: number of islands
    """
    visited = init_visited(matrix)
    num_islands = 0
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if matrix[i][j] and not visited[i][j]:
                check_neighbours(matrix, (i, j), visited)
                num_islands += 1
    # print(visited)
    return num_islands


if __name__ == "__main__":
    # mat = [[
    #     1, 1, 0, 0, 0
    # ], [
    #     1, 0, 0, 1, 1
    # ], [
    #     0, 0, 1, 0, 1
    # ], [
    #     0, 0, 0, 0, 0
    # ],
    #    [
    #     1, 0, 1, 0, 0
    # ]
    # ]
    mat = [[
            1, 1, 0, 0, 0
        ], [
            0, 1, 0, 0, 1
        ], [
            1, 0, 0, 1, 1
        ], [
            0, 0, 0, 0, 0
        ], [
            1, 0, 1, 0, 1
        ]
    ]
    print(mat)
    print(count_islands(mat))
