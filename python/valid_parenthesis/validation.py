"""
Given a string: '()())()'

Check if string is valid ( no single opening or closing parenthesis )
"""


def validate_parenthesis_using_stack(given_string):
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


def validate_parenthesis(given_string):
    valid_counter = 0
    for i in range(len(given_string)):
        if given_string[i] == '(':
            valid_counter += 1
        elif given_string[i] == ')':
            valid_counter -= 1
            if valid_counter < 0:
                return False
    return valid_counter == 0
