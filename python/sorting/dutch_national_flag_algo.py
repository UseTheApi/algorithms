"""
Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[].
The functions should put all 0s first, then all 1s and all 2s in last.

Example
Input = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
Output = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}
"""

import unittest


def sort012(array: list):
    low = 0
    high = len(array)-1
    middle = 0

    while middle <= high:
        if array[middle] == 0:
            array[low], array[middle] = array[middle], array[low]
            low += 1
            middle += 1
        elif array[middle] == 1:
            middle += 1
        elif array[middle] == 2:
            array[middle], array[high] = array[high], array[middle]
            high -= 1
    return array


class Sort012Test(unittest.TestCase):
    def test_sort_ascending_ordered(self):
        arr = [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2]
        self.assertEqual(arr, sort012(arr))

    def test_sort_descending_ordered(self):
        arr = [2, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0]
        self.assertEqual(sorted(arr), sort012(arr))

    def test_sort_random(self):
        arr = [1, 2, 0, 2, 1, 0, 0, 2, 1, 2, 0, 0]
        self.assertEqual(sorted(arr), sort012(arr))

    def test_sort_empty(self):
        arr = list()
        self.assertEqual(arr, sort012(arr))
