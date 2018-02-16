# coding=utf-8
"""
The Longest Increasing Subsequence (LIS) problem is to find the length of
 the longest subsequence of a given sequence such that all elements of
  the subsequence are sorted in increasing order.
  For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6
  and LIS is {10, 22, 33, 50, 60, 80}.
"""

import unittest


def _lis(array, i, res_lis):
    """
    Recursive Longest Increasing Subsequence caluclation helper
    :param array: given array of integers
    :param i: current end of lis to be calculated
    :res_lis: list of all lis calculated
    :return: current lis of max length
    :rtype: int
    """
    if not i:
        return 1
    tmp_res, max_end_here = 1, 1
    for j in range(i):
        tmp_res = _lis(array, j, res_lis)
        if array[i] > array[j]:
            max_end_here = max(tmp_res+1, max_end_here)

    # collecting list of lis throughout calculation
    res_lis.append(max_end_here)
    return max_end_here


def lis_rec(array):
    """
    Main LIS function for recursive method.
    calls LIS helper for each index of a given array
    :param array: given array of integers
    :return: Length of LIS
    :rtype: int
    """
    result_lis = list()
    for _ in range(len(array)):
        _lis(array, _, result_lis)
    return max(*result_lis)


def lis_dp(array):
    """
    Longest Increasing Subsequence using dynamic programming approach.
    :param array: given array of integers
    :return: length of LIS
    :rtype: int
    """
    mem = [1] * len(array)

    for i in range(1, len(mem)):
        res = 1
        for j in range(i):
            if array[i] > array[j]:
                res = max(res, 1+mem[j])
        mem[i] = res
    return max(*mem)


class TestLIS(unittest.TestCase):
    """ Test Longest Increaing Subsequence solutions """
    def test_lis(self):
        """ Test both recursive and dp approaches """
        arr = [3, 4, -1, 0, 6, 2, 3]

        self.assertEqual(4, lis_rec(arr))
        self.assertEqual(4, lis_dp(arr))

        arr = [3, 10, 2, 1, 20]

        self.assertEqual(3, lis_rec(arr))
        self.assertEqual(3, lis_dp(arr))
