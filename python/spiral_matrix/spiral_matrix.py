# coding=utf-8
"""
Given n represents a size of matrix. Fill matrix in spiral manner
"""

def spiral(num):
    """
    Returns matrix of size n filled with numbers from 1 to n in spiral manner
    :param n: size of matrix
    :return: array [][]
    """
    if not num:
        return
    if num == 1:
        return [[1]]

    mat = [[0 for _ in range(num)] for _ in range(num)]

    dir_row = [0, 1, 0, -1]
    dir_col = [1, 0, -1, 0]

    val = 1
    for i in range(num):
        mat[0][i] = val
        val += 1
    num -= 1
    row = 0
    col = num
    direc = 1
    count = 0
    while num:
        for i in range(num):
            row += dir_row[direc]
            col += dir_col[direc]
            mat[row][col] = val
            val += 1
        count += 1
        direc += 1
        direc %= 4
        if count >= 2:
            num -= 1
            count = 0

    return mat


if __name__ == "__main__":
    for _ in spiral(3):
        print(_)
