"""
Given a large Log File. Every line contains a start_time, end_time, how much RAM the job consumed.

Example:

700 715 2
730 900 1
815 915 3
740 850 2
845 855 4


700 715 2 <-- cur_mem = 2
730 900 1 <-- cur_mem = 1
740 850 2 <-- cur_mem = 3
815 915 3 <-- cur_mem = 6
845 855 4 <-- cur_mem = 10

700 715 2 <-- cur_mem = 2
730 900 1 <-- cur_mem = 1
740 840 2 <-- cur_mem = 3
815 915 3 <-- cur_mem = 6
845 855 4 <-- cur_mem = 8

700 -2
715 +2
730 -1
740 -2
815 -3
840 +2
845 -4
855 +4
900 +1
915 +3
"""


def max_memory_consumed(log_file):
    timeline = list()
    for entry in log_file:
        timeline.append((entry[0], 0-entry[2]))
        timeline.append((entry[1], entry[2]))
    timeline.sort(key=lambda x: x[0])
    max_memory = 0
    cur_mem = 0
    for entry in timeline:
        cur_mem += entry[1]
        max_memory = min(max_memory, cur_mem)
    return 0-max_memory
