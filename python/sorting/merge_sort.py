"""
Merge Sort
"""


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
