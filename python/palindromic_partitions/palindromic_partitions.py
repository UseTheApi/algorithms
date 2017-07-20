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


if __name__ == "__main__":
    print(collect_all_palindromic_parts('banana'))
