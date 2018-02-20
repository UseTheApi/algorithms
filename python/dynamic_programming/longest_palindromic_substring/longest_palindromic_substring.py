# coding=utf-8
"""
Given a string, find the longest substring which is palindrome.
For example,
    if the given string is “forgeeksskeegfor”, the output should be “geeksskeeg”.
"""

import unittest


def lpstr(array):
    """
    Longest Palindromic Substring. Dynamic Programming approach
    :param array: given string
    :return: Length of LPS
    """
    if not array:
        return 0

    mat = [[0 for _ in range(len(array))] for _ in range(len(array))]

    max_length = 1
    for i in range(len(array)):
        mat[i][i] = 1
        if i+1 < len(array) and array[i] == array[i+1]:
            mat[i][i+1] = 1
            max_length = 2

    for cur_length in range(2, len(array)):
        j = cur_length-1
        for i in range(0, len(array)-cur_length):

            if array[i] == array[j+1] and mat[i+1][j] == 1:

                mat[i][j+1] = 1
                max_length = max(cur_length+1, max_length)
            j += 1

    return max_length


class TestLPStr(unittest.TestCase):
    """ Test Case for Longest Palindromic Substring """

    def test_lpstr(self):
        """ Test Cases for LPS """
        test_arr = list('geekeekg')
        self.assertEqual(lpstr(test_arr), 5)
        test_arr = list('forgeeksskeegfor')
        self.assertEqual(lpstr(test_arr), 10)
        self.assertEqual(lpstr([]), 0)
