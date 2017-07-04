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


"""
Quick Sort. Median of Three
"""


def _median(array: list, left, right, middle):
    if array[left] < array[right]:
        return right if array[right] < array[middle] else middle
    else:
        return left if array[left] < array[middle] else middle


def _partition_mot(array: list, left, right):  # median of three partition
    i = left
    j = right
    pivot = array[_median(array, left, right, (left + right)//2)]

    while True:
        while array[i] < pivot:
            i += 1
        while array[j] > pivot:
            j -= 1
        if i < j:
            array[i], array[j] = array[j], array[i]
        else:
            return j


def quick_sort_mot(array: list, left, right):
    if right-left < 2:
        return array
    pi = _partition_mot(array, left, right)
    quick_sort_mot(array, left, pi)
    quick_sort_mot(array, pi+1, right)
    return array
