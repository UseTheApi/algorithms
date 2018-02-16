# coding=utf-8
"""
Given a binary tree, find all duplicate subtrees.
Two trees are duplicate if they have the same structure with same node values.
"""

import unittest


class TNode(object):
    """ Binary Tree Class """
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

    def __str__(self):
        return str(self.val)


def traverse(root, res):
    """ Traverse Binary Tree """
    if not root:
        return
    traverse(root.left, res)
    res.append(root.val)
    traverse(root.right, res)



def _duplicates(root, buffer, res):
    """
    Count Duplicated Subtrees for a Tree Helper
    :param root: Tree root
    :param buffer: buffer to store current subtree
    :param res: result list of duplicated subtrees
    :rtype: void
    """
    if not root:
        return
    l_tr = list()
    traverse(root.left, l_tr)
    if l_tr and l_tr not in buffer:
        buffer.append(l_tr)
    else:
        if l_tr and l_tr not in res:
            res.append(l_tr)

    r_tr = list()
    traverse(root.right, r_tr)
    if r_tr and r_tr not in buffer:
        buffer.append(r_tr)
    else:
        if r_tr and r_tr not in res:
            res.append(r_tr)

    _duplicates(root.left, buffer, res)
    _duplicates(root.right, buffer, res)


def duplicated_subtrees(tree):
    """
    Calculate Duplicated subtrees in a given tree
    :param tree: Tree Root
    :return: result list of duplicated subtrees
    :rtype: list
    """
    buff = list()
    re = list()
    _duplicates(tree, buffer=buff, res=re)
    return re


class TestDuplicatedSubtrees(unittest.TestCase):
    """ Test Duplicated Subtrees """
    def setUp(self):
        self.tree = TNode(1)
        self.tree.left = TNode(2)
        self.tree.left.left = TNode(4)
        self.tree.right = TNode(3)
        self.tree.right.left = TNode(2)
        self.tree.right.left.left = TNode(4)
        self.tree.right.right = TNode(4)

    def test_duplicates(self):
        expected_result = [[4, 2], [4]]
        self.assertEqual(expected_result, duplicated_subtrees(self.tree))

if __name__ == "__main__":
    tree = TNode(1)
    tree.left = TNode(2)
    tree.left.left = TNode(4)
    tree.right = TNode(3)
    tree.right.left = TNode(2)
    tree.right.left.left = TNode(4)
    tree.right.right = TNode(4)

    result = duplicated_subtrees(tree)
    print(result)
