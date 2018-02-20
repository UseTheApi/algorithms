# coding=utf-8
"""
Given a sequence, find the length of the longest palindromic subsequence in it.

if the given sequence is “BBABCBCAB”, then the output should be 7 as
“BABCBAB” is the longest palindromic subseuqnce in it.
“BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence,
but not the longest ones.
"""


def lps_rec(array, i, j):
    """
    Longest Palindromic Subsequence using Recursive approach
    :param array: given array
    :param i: beginning of a palindromic subsequence currently processed
    :param j: ending of a palindromic subsequence currently processed
    :return: Length of LPS
    :rtype: int
    """
    if i+1 == j and array[i] == arr[j]:
        return 2
    if i == j:
        return 1
    if array[i] == array[j]:
        return 2 + lps_rec(array, i+1, j-1)
    return max(lps_rec(array, i+1, j), lps_rec(array, i, j-1))


def lps_dp(array):
    """
    Longest Palindromic Subsequence using Dynamic Programming approach
    :param array: given array
    :return: Length of LPS
    :rtype: int
    """
    pass


if __name__ == "__main__":
    arr = ['g', 'e', 'e', 'k', 's', 'e', 'e', 'k', 'g']
    print(lps_rec(arr, 0, len(arr)-1))
