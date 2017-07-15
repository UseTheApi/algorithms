"""
Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.
We are given two arrays which represent arrival and departure times of trains that stop

Examples:

Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
        dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

Output: 3
There are at-most three trains at a time (time between 11:00 to 11:20)

Notes: For the simplicity all times are represented as integers: 9:00 -> 900
"""


def min_number_of_platforms(arrivals, departures):
    assert len(arrivals) == len(departures), "expected an equal number of trains"

    arrivals.sort()
    departures.sort()

    i = 0
    j = 0

    min_platforms_num = 1
    not_departed_trains = 1
    while i < len(arrivals) - 1 and j < len(departures) - 1:
        if arrivals[i+1] < departures[j]:
            i += 1
            not_departed_trains += 1
            min_platforms_num = max(not_departed_trains, min_platforms_num)
        else:
            j += 1
            not_departed_trains -= 1

    return min_platforms_num


if __name__ == "__main__":
    arr = [900, 940, 950, 1100, 1500, 1800]
    dep = [910, 1200, 1120, 1130, 1900, 2000]
    print(min_number_of_platforms(arr, dep))
