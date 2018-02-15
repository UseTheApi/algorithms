# coding=utf-8
"""
Given two strings str1 and str2 and below operations that can performed on str1.
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’

* Insert
* Remove
* Replace

All of the above operations are of equal cost.

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations.
Replace 'n' with 'r', insert t, insert a
"""

import unittest


def min_of_three(first, second, third):
    """ Calculates a min of three. parameters should be comparable """
    return min(min(first, second), third)


def edit_distance_rec(str1, str2, len1, len2):
    """
    Edit Distance Implementation naive approach using recursion
    :param str1: first string
    :param str2: second string
    :param len1: length of str1
    :param len2: length of str2
    :return: number of operations to be perform in order to transform str1 into str2
    :rtype: int
    """

    if not len1:
        return len2

    if not len2:
        return len1

    if str1[len1-1] == str2[len2-1]:
        return edit_distance_rec(str1, str2, len1-1, len2-1)

    return 1 + min_of_three(
        edit_distance_rec(str1, str2, len1-1, len2),  # delete from first
        edit_distance_rec(str1, str2, len1, len2-1),  # insert into first
        edit_distance_rec(str1, str2, len1-1, len2-1)  # replace char in first
    )


def edit_distance_dp(str1, str2):
    """
    Edit Distance Implementation dynamic programming approach
    :param str1: first string
    :param str2: second string
    :return: number of operations to be perform in order to transform str1 into str2
    :rtype: int
    """
    matrix = [[0 for _ in range(len(str1) + 1)] for _ in range(len(str2) + 1)]
    for i in range(len(str1)+1):
        matrix[0][i] = i
    for i in range(len(str2)+1):
        matrix[i][0] = i

    for column in range(1, len(str1)+1):
        for row in range(1, len(str2)+1):
            if str1[column-1] == str2[row-1]:
                curry = 0
            else:
                curry = 1
            matrix[row][column] = curry + min_of_three(
                matrix[row - 1][column],
                matrix[row][column - 1],
                matrix[row - 1][column - 1]
            )
    return matrix[len(str2)][len(str1)]


class TestEditDistance(unittest.TestCase):
    """ Test cases for Edit Distance """

    def test_edit_distance_rec(self):
        """ Test Edit Distance Recursive """
        print('==== Test Edit Distance Recursive ====')
        str1 = 'sunday'
        str2 = 'saturday'
        print('Given strs: {} and {}'.format(str1, str2))
        result = edit_distance_rec(str1, str2, len(str1), len(str2))
        print('Need to perform {} operations', result)
        self.assertEqual(result, 3)

        str1 = ''
        str2 = 'test'
        print('Given strs: {} and {}'.format(str1, str2))
        result = edit_distance_rec(str1, str2, len(str1), len(str2))
        print('Need to perform {} operations', result)
        self.assertEqual(result, 4)

        str1 = 'geek'
        str2 = 'gesek'
        print('Given strs: {} and {}'.format(str1, str2))
        result = edit_distance_rec(str1, str2, len(str1), len(str2))
        print('Need to perform {} operations', result)
        self.assertEqual(result, 1)

        str1 = 'cat'
        str2 = 'cut'
        print('Given strs: {} and {}'.format(str1, str2))
        result = edit_distance_rec(str1, str2, len(str1), len(str2))
        print('Need to perform {} operations', result)
        self.assertEqual(result, 1)

    def test_edit_distance_dp(self):
        """ Test Edit Distance DP """
        print('==== Test Edit Distance DP ====')
        str1 = 'sunday'
        str2 = 'saturday'
        print('Given strs: {} and {}'.format(str1, str2))
        result = edit_distance_rec(str1, str2, len(str1), len(str2))
        print('Need to perform {} operations', result)
        self.assertEqual(result, 3)

        str1 = ''
        str2 = 'test'
        print('Given strs: {} and {}'.format(str1, str2))
        result = edit_distance_rec(str1, str2, len(str1), len(str2))
        print('Need to perform {} operations', result)
        self.assertEqual(result, 4)

        str1 = 'geek'
        str2 = 'gesek'
        print('Given strs: {} and {}'.format(str1, str2))
        result = edit_distance_rec(str1, str2, len(str1), len(str2))
        print('Need to perform {} operations', result)
        self.assertEqual(result, 1)

        str1 = 'cat'
        str2 = 'cut'
        print('Given strs: {} and {}'.format(str1, str2))
        result = edit_distance_rec(str1, str2, len(str1), len(str2))
        print('Need to perform {} operations', result)
        self.assertEqual(result, 1)
