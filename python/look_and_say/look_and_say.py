# coding=utf-8
"""
Implement a function that outputs the Look and Say sequence:

1
11
21
1211
111221
312211
13112221
1113213211
31131211131221
13211311123113112211
"""


def look_and_say(num_str):
    if not num_str or not num_str.isdigit():
        return
    count = 1

    result_str = ''
    if len(num_str) == 1:
        result_str += str(count)+num_str
        yield result_str
        yield from look_and_say(result_str)
    for i in range(len(num_str)):
        if i+1 < len(num_str) and num_str[i] == num_str[i+1]:
            count += 1
        else:
            result_str += str(count) + num_str[i]
            count = 1
    yield result_str
    yield from look_and_say(result_str)


if __name__ == "__main__":
    g = look_and_say('1')
    for i in range(20):
        print(next(g))

