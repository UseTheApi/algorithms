"""
Given a string: '()())()'

Check if string is valid ( no single opening or closing parenthesis )
"""


def valid_parenthesis_using_stack(given_string):
    stack = list()
    for i in range(len(given_string)):
        if given_string[i] == '(':
            stack.append(given_string[i])
        elif given_string[i] == ')':
            if stack:
                stack.pop()
            else:
                return False
    return True


def valid_parenthesis(given_string):
    valid_counter = 0
    for i in range(len(given_string)):
        if given_string[i] == '(':
            valid_counter += 1
        elif given_string[i] == ')':
            valid_counter -= 1
            if valid_counter < 0:
                return False
    return valid_counter == 0


"""
Remove Invalid Parentheses

An expression will be given which can contain open and close parentheses and optionally some characters, No other operator will be there in string. We need to remove minimum number of parentheses to make the input string valid. If more than one valid output are possible removing same number of parentheses then print all such output.
Examples:

Input  : str = “()())()” -
Output : ()()() (())()
There are two possible solutions
"()()()" and "(())()"

Input  : str = (v)())()
Output : (v)()()  (v())()
"""


def remove_invalid_parenthesis(given_string):
    queue = list()
    visited = set()
    queue.insert(0, given_string)
    visited.add(given_string)
    level = False
    while queue:
        cur_str = queue.pop()
        if valid_parenthesis(cur_str):
            print(cur_str)
            level = True
        if level:
            continue
        for i in range(len(cur_str)):
            tmp_str = cur_str[0:i] + cur_str[i+1:len(cur_str)]
            if tmp_str not in visited:
                queue.insert(0, tmp_str)
                visited.add(tmp_str)
