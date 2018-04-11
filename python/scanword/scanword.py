"""
Given a puzzle of letters/ characters e.g.

   0 1 2 3 4 5

0  a e r o p s
1  b h a r l s
2  w r i s l o
3  a s n k t q

Write a function to which this puzzle and a word will be passed to test whether that word exists in the puzzle or not.
e.g. rain and slow will return true. rain is present in the second column and slow in the third row wrapped around.
"""

neighbours = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def is_safe(len_i, len_j, cell, track):
    if cell not in track and len_i > cell[0] > -1 and len_j > cell[1] > -1:
        return True
    return False


def scanword(mat, word):
    word = list(word)
    result = list()
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            if mat[i][j] == word[0]:
                scanword_visit(mat, i, j, result, word, list())
                if result:
                    return True
    return False


def scanword_visit(mat, i, j, result, word, track):
    track.append((i, j))
    cur = [mat[i][j] for i, j in track]
    if cur[-1] != word[len(cur)-1]:
        track.pop()
        return
    if word == cur:
        result.append(''.join(cur))
        return
    for n_i, n_j in neighbours:
        next_i, next_j = i+n_i, j+n_j
        if next_i == len(mat):
            next_i = 0
        elif next_j == len(mat[0]):
            next_j = 0
        if is_safe(len(mat), len(mat[0]), (next_i, next_j), track):
            if result:
                break
            scanword_visit(mat, next_i, next_j, result, word, track)

