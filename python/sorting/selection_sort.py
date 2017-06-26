"""
Selection Sort
"""


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
