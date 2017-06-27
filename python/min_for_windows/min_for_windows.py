import unittest

"""
Find a min(max) for every window of size k in a given array
"""


def _create_lr(array: list, window_size, n_windows):
    lr = [0] * len(array)
    for i in range(len(array)):
        lr[i] = array[i] if not i%window_size else min(array[i], array[i-1])
    return lr


def _create_rl(array: list, window_size, n_windows):
    rl = [0] * len(array)
    for i in range(len(array)-1, -1, -1):
        rl[i] = array[i] if i == len(array)-1 or i%window_size == window_size-1 else min(array[i], array[i+1])
    return rl


def min_for_window(array: list, window_size):
    n_windows = len(array) - window_size+1
    lr = _create_lr(array, window_size, n_windows)
    rl = _create_rl(array, window_size, n_windows)
    res = [0]*n_windows

    for i in range(n_windows):
        res[i] = min(rl[i], lr[i+window_size-1])
    return res


class MinForWindowTest(unittest.TestCase):
    def test_ascending_ordered_array(self):
        arr = [-2, 1, 3, 5, 7, 10, 14]
        k = 3
        expected_res = [-2, 1, 3, 5, 7]
        self.assertEquals(min_for_window(arr, k), expected_res)

    def test_descending_ordered_array(self):
        arr = [14, 10, 7, 5, 3, 1, -2]
        k = 2
        expected_res = [10, 7, 5, 3, 1, -2]
        self.assertEquals(min_for_window(arr, k), expected_res)

    def test_random_array_size_3(self):
        arr = [1, -2, 5, 3, 4, 6, 8, 10]
        k = 3
        expected_res = [-2, -2, 3, 3, 4, 6]
        self.assertEquals(min_for_window(arr, k), expected_res)

    def test_random_array_size_2(self):
        arr = [1, -2, 5, 3, 4, 6, 8, 10]
        k = 2
        expected_res = [-2, -2, 3, 3, 4, 6, 8]
        self.assertEquals(min_for_window(arr, k), expected_res)

    def test_empty_array(self):
        arr = list()
        k = 4
        expected_res = list()
        self.assertEquals(min_for_window(arr, k), expected_res)

    def test_array_of_one_element(self):
        arr = [5]
        k = 1
        expected_res = [5]
        self.assertEquals(min_for_window(arr, k), expected_res)

