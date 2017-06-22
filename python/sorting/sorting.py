import unittest


def insertion_sort(arr: list):
    """
    Insertion Sort
    :param arr: given array
    :return: sorted array
    """
    for i in range(1, len(arr)):
        cur = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > cur:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = cur
    return arr


def selection_sort(arr: list):
    """
    Selection Sort
    :param arr: given array
    :return: sorted array
    """
    for i in range(len(arr)):
        min_index = i
        for j in range(i+1, len(arr)):
            min_index = j if arr[j] < arr[min_index] else min_index
        arr[min_index], arr[i] = arr[i], arr[min_index]
    return arr


def _merge(array, middle, left, right):
    left_len = middle - left+1
    right_len = right - middle

    left_arr = [0]*left_len
    right_arr = [0]*right_len

    for g in range(0, left_len):
        left_arr[g] = array[left+g]
    for g in range(0, right_len):
        right_arr[g] = array[middle+1+g]

    i = 0
    j = 0
    k = left

    while i < left_len and j < right_len:
        if left_arr[i] <= right_arr[j]:
            array[k] = left_arr[i]
            i += 1
        else:
            array[k] = right_arr[j]
            j += 1
        k += 1
    while i < left_len:
        array[k] = left_arr[i]
        i += 1
        k += 1
    while j < right_len:
        array[k] = right_arr[j]
        j += 1
        k += 1


def merge_sort(array: list, l, r):
    """
    Merge Sort
    :param array: given array
    :param l: beginning
    :param r: ending
    :return: sorted array
    """
    if l < r:
        middle = (l + (r - 1)) // 2
        merge_sort(array, l, middle)
        merge_sort(array, middle+1, r)
        _merge(array, middle, l, r)
    return array


class SortTest(unittest.TestCase):

    def check_helper(self, arr):
        # Insertion Sort Test
        self.assertEquals(insertion_sort(arr.copy()), sorted(arr))
        # Selection Sort Test
        self.assertEquals(selection_sort(arr.copy()), sorted(arr))
        # Merge Sort Test
        self.assertEquals(merge_sort(arr.copy(), 0, len(arr)-1), sorted(arr))

    def test_ascending_ordered_array(self):
        arr = [1, 3, 6, 8, 19]
        self.check_helper(arr)

    def test_descending_ordered_array(self):
        arr = [19, 8, 6, 3, 1]
        self.check_helper(arr)

    def test_random_array(self):
        arr = [5, 2, 7, 19, 3, 9, 12]
        self.check_helper(arr)

    def test_empty_array(self):
        arr = list()
        self.check_helper(arr)

    def test_single_element_in_array(self):
        arr = [3]
        self.check_helper(arr)

if __name__ == "__main__":
    pass
