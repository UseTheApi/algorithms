"""
Quick Sort
"""


def _partition(array: list, left, right):
    """
    partition with last element as a pivot
    """
    pivot = array[right]
    smaller = left - 1

    for i in range(left, right):
        if array[i] <= pivot:
            smaller += 1
            array[i], array[smaller] = array[smaller], array[i]
    array[smaller+1], array[right] = array[right], array[smaller+1]
    return smaller+1


def quick_sort(arr: list, low, high):
    if low < high:
        pi = _partition(arr, low, high)
        quick_sort(arr, low, pi-1)
        quick_sort(arr, pi+1, high)
    return arr
