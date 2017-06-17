
"""
Problem: Given an array of integers. Find a pair with a sum closest to 0.
Write 2 functions:
    * return closest sum;
    * return pair;
"""


def abs_min(first, second):
    if first < 0 and second < 0:
        return max(first, second)
    if first > 0 and second > 0:
        return min(first, second)
    cur = min(abs(first), abs(second))
    return first if abs(first) == cur else second


def closest_sum_to_zero(array):
    """
    If array is sorted we can determine the answer using two pointers

    :param array: array of integers (any order)
    :type array: list

    :return: closest sum to zero
    :rtype: int
    """
    array.sort()
    print(array)
    begin = 0
    end = len(array) - 1
    min_abs_sum = 9999999999
    while(begin != end):
        cur_sum = arr[begin] + arr[end]
        print("cur_sum", cur_sum)
        min_abs_sum = abs_min(min_abs_sum, cur_sum)
        print("min_sum", min_abs_sum)
        if cur_sum > 0:
            end -= 1
        else:
            begin += 1
    return min_abs_sum


if __name__ == "__main__":
    # arr = [2, 4, 3, -1, -2, 5]
    # arr = [3, 1, 5, -7, -100, 8, 4, 2]
    arr = [-45, -20, -2, -1, 12, 15, 30]
    print(closest_sum_to_zero(arr))



