# coding=utf-8
"""
Find positions of a battleship of a given size on a given battlefeild.
Battlefeild is represented as a 2D matrix where ships are marked with 1.
"""

POTENTIALS_NEIGHBOURS = [(0, 1), (0, -1), (1, 0), (-1, 0)]


def is_safe(mat, visited, new_position):
    """ Check if move is safe for a given position and a matrix """
    if (0 <= new_position[0] < len(mat) and 0 <= new_position[1] < len(mat)) and \
            mat[new_position[0]][new_position[1]] and not visited[new_position[0]][new_position[1]]:
        return True
    return False


def visit(mat, visited, cur_pos, ship_size, positions=None):
    """ Visit recursively (DFS) each cell of a given matrix """
    if not positions:
        positions = list()
    visited[cur_pos[0]][cur_pos[1]] = True
    positions.append(cur_pos)

    for neighbour in POTENTIALS_NEIGHBOURS:
        new_position = (cur_pos[0] + neighbour[0], cur_pos[1] + neighbour[1])
        if is_safe(mat, visited, new_position):
            visit(mat, visited, new_position, ship_size, positions)
    if ship_size == len(positions):
        return positions
    return None


def find_ship(mat, ship_size=3):
    """ Find positions of the ship of a given size """
    visited = [[0 for _ in mat] for _ in mat]
    positions = None
    for row in range(len(mat)):
        for col in range(len(mat)):
            if mat[row][col] and not visited[row][col]:
                positions = visit(mat, visited, (row, col), ship_size)
                if positions:
                    return positions
    return positions


if __name__ == "__main__":
    BATTLEFIELD = [
        [0, 0, 0, 1, 0, 0],
        [1, 0, 0, 0, 0, 1],
        [0, 0, 0, 1, 0, 1],
        [0, 0, 0, 1, 0, 0],
        [1, 0, 0, 1, 0, 0],
        [1, 0, 0, 0, 0, 0]
    ]

    print(find_ship(BATTLEFIELD))
