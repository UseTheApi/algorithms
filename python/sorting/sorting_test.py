import unittest
from .merge_sort import merge_sort
from .insertion_sort import insertion_sort
from .selection_sort import selection_sort


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
