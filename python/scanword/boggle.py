# coding=utf-8
"""
Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ

Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character.
Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move
to any of 8 adjacent characters, but a word should not have multiple instances of same cell.
"""

neighbours = [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (-1, -1), (1, -1), (-1, 1)]


def dict_validate(d, word):
    d = [x for x in d if x.startswith(word)]
    return d


def is_safe(matrix, cell, visited):
    """
    Validation function
    :param matrix: 2D array
    :param cell: index in 2D array (tuple)
    :param visited: list of visited cells
    :rtype: bool
    """
    if cell not in visited \
            and (len(matrix) > cell[0] > -1) \
            and (len(matrix) > cell[1] > -1):
        return True
    return False


def boggle(matrix, dictionary):
    result = list()
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            boggle_visit(matrix, i, j, dictionary, list(), result)
    print(result)
    return result


def boggle_visit(matrix, i, j, d, track, result):
    track.append((i, j))
    word = ''.join([matrix[i][j] for i, j in track])

    d = [x for x in d if x.startswith(word)]
    if not d:
        track.pop()
        return
    if d[0] == word:
        result.append(word)
        return

    for n_i, n_j in neighbours:
        next_i, next_j = i+n_i, j+n_j
        if is_safe(matrix, (next_i, next_j), track):
            boggle_visit(matrix, next_i, next_j, d, track, result)

if __name__ == '__main__':
    dictionary = ["GEEKS", "FOR", "QUIZ", "GO"]
    boggle_m = [['G', 'I', 'Z'], ['U', 'E', 'K'], ['Q', 'S', 'E']]
    boggle(boggle_m, dictionary)

