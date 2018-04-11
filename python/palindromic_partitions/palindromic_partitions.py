"""
Print all palindromic partitions of a string
Given a string s, partition s such that every string of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example :

Input  : s = "bcc"
Output : [["b", "c", "c"], ["b", "cc"]]

Input  : s = "geeks"
Output : [["g", "e", "e", "k", "s"],
          ["g", "ee", "k", "s"]]

Recursion Tree:
                geeks
                  |
          (g)     +        eeks
           |                \
    (g), (e) + eks         (g), (ee) + ks
          |                     \
    (g), (e), (e) + ks      (g), (ee), (k) + s
          |                         \
    (g), (e), (e), (k) + s     (g), (ee), (k), (s)
          |
    (g), (e), (e), (k), (s)
"""


def palindrom(s):
    for i in range(len(s)):
        if s[i] != s[len(s)-1-i]:
            return False
    return True


def add_string(result, collected_parts, index, s):
    cur_str = ''
    if index == 0:
        collected_parts[:] = []
    cur_parts = collected_parts.copy()
    for i in range(index, len(s)):
        cur_str += s[i]
        if palindrom(cur_str):
            print('cur_str', cur_str, 'cur_parts', collected_parts, sep=' = ')
            collected_parts.append(cur_str)
            if i+1 < len(s):
                add_string(result, collected_parts, i+1, s)
            else:
                result.append(collected_parts)
            collected_parts = cur_parts


def collect_all_palindromic_parts(given_string):
    result = list()
    collected_parts = list()
    add_string(result, collected_parts, 0, given_string)
    return result


def collect_partitions(s, result=None, pal_size=1):
    if pal_size == 1:
        result = [list(s)]
        return collect_partitions(s, result, pal_size+1)
    if pal_size == len(s):
        return result
    parts = list()
    i = 0
    while i < len(s) - pal_size + 1:
        cur_str = ''
        for _ in range(pal_size):
            cur_str += s[_+i]
        if palindrom(cur_str):
            parts.append(cur_str)
            i += pal_size
        else:
            parts.append(s[i])
            i += 1
    while i < len(s):
        parts.append(s[i])
        i += 1
    if parts not in result:
        result.append(parts)
    return collect_partitions(s, result, pal_size+1)
if __name__ == "__main__":
    print(collect_all_palindromic_parts('banana'))