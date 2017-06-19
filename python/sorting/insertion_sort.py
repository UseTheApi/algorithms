import unittest

def insertion_sort(arr: list):
    for i in range(1, len(arr)):
        cur = arr[i]
        j = i - 1
        while(j >= 0 and arr[j] > cur):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = cur
    return arr


def _find_min(arr: list):
    cur_min = arr[0]
    for i in range(1, len(arr)):
        cur_min = arr[i] if arr[i] < cur_min else cur_min
    return cur_min

def selection_sort(arr: list):
   return 


class InsertionSortTest(unittest.TestCase):

    def check_helper(self, arr):
        self.assertEquals(insertion_sort(arr.copy()), sorted(arr))

    def test_ascending_oedered_array(self):
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
    arr = [5, 2, 7, 19, 4, 3, 9, 12]
    print(arr)
    #insertion_sort(arr)
    #print(arr)
    print(_find_min(arr))

