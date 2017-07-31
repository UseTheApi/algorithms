"""
Build a binary tree from a given ternary string: a ? b ? c : d : e
"""

import unittest
from .tree import TreeNode


def construct_tree_from_ternary_operator(operator: str):
    """
    This function constructs a binary tree from a given ternary operator in O(n) time
    :param operator: Given Ternary Operator
    :type operator: str
    :return: root of a constructed tree
    :rtype: TreeNode
    """
    if not operator:
        return None
    root = TreeNode(operator[0])
    parent = dict(
        root=None
    )
    cur = root
    for i in range(1, len(operator)):
        if operator[i] == '?':
            i += 1
            cur.left = TreeNode(operator[i])
            parent[cur.left] = cur
            cur = cur.left
        elif operator[i] == ':':
            i += 1
            cur_parent = parent[cur]
            while cur_parent.right:
                cur_parent = parent[cur_parent]
            cur_parent.right = TreeNode(operator[i])
            parent[cur_parent.right] = cur_parent
            cur = cur_parent.right
    return root


def _traverse_helper(tree, traverse_list=None):
        traverse_list = list() if not traverse_list else traverse_list
        if not tree:
            return traverse_list
        traverse_list = _traverse_helper(tree.left, traverse_list)
        traverse_list.append(tree.data)
        traverse_list = _traverse_helper(tree.right, traverse_list)
        return traverse_list


class TestTernaryTree(unittest.TestCase):

    def test_empty_operator(self):
        print()
        print("==== Test Empty Operator ====")
        operator = ''
        self.assertFalse(construct_tree_from_ternary_operator(operator))

    def test_one_ternary_operator(self):
        print()
        print("==== Test One Ternary Operator ====")
        operator = 'a?b:c'
        expected_traverse = list('bac')
        tree = construct_tree_from_ternary_operator(operator)
        actual_traverse = _traverse_helper(tree)
        print(actual_traverse)
        self.assertEquals(expected_traverse, actual_traverse)

    def test_ternary_simple_sequence(self):
        print()
        print("==== Test Simple Ternary Operator ====")
        operator = 'a?b?c:d:e'
        expected_traverse = list('cbdae')
        tree = construct_tree_from_ternary_operator(operator)
        actual_traverse = _traverse_helper(tree)
        print(actual_traverse)
        self.assertEquals(expected_traverse, actual_traverse)

    def test_complex_ternary_operator(self):
        print()
        print("==== Test Complex Ternary Operator ====")
        operator = 'a?b?c:d?e:f:g'
        expected_traverse = list('cbedfag')
        tree = construct_tree_from_ternary_operator(operator)
        actual_traverse = _traverse_helper(tree)
        print(actual_traverse)
        self.assertEquals(expected_traverse, actual_traverse)
