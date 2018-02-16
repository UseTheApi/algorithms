# coding=utf-8
"""
You are given a binary tree in which each node contains a value
and another value.
Design an algorithm
to print all paths which sum up to that value.
Note that it can be any path in the tree
- it does not have to start at the root.
"""

import unittest


class TNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def __str__(self):
        return str(self.val)


def visit(root):
    if not root:
        return 0
    leaves = list()

    visited = [root]
    parent = dict()
    parent[root] = None
    cur = root
    cur_sum = cur.val
    while cur:
        if cur.left and cur.left not in visited:
            visited.append(cur.left)
            parent[cur.left] = cur
            cur = cur.left
            cur_sum += cur.val
        elif cur.right and cur.right not in visited:
            visited.append(cur.right)
            parent[cur.right] = cur
            cur = cur.right
            cur_sum += cur.val
        else:
            if not cur.left and not cur.right:
                leaves.append(cur)
            cur = parent[cur]

    return leaves, parent


def paths_for_sum(root, limit, leaves, parent):
    if not root:
        return
    result_paths = []
    for leaf in leaves:
        cur = leaf
        cur_sum = 0
        buffer_path = []
        while cur and cur_sum < limit:
            cur_sum += cur.val
            buffer_path.append(cur.val)
            cur = parent[cur]
        if cur_sum == limit:
            result_paths.append(buffer_path)
    return result_paths


class TestPathsForSum(unittest.TestCase):

    def setUp(self):
        self.tree = TNode(5)
        self.tree.left = TNode(3)
        self.tree.right = TNode(4)
        self.tree.left.left = TNode(7)
        self.tree.left.right = TNode(1)
        self.tree.left.right.left = TNode(6)
        self.tree.right.left = TNode(2)
        self.tree.right.right = TNode(6)
        self.tree.right.left.left = TNode(1)
        self.tree.right.left.right = TNode(3)
        self.tree.right.left.right.left = TNode(6)

    def test_tree(self):
        test_limit = 15
        expected_paths = [[7, 3, 5], [6, 1, 3, 5], [6, 3, 2, 4], [6, 4, 5]]
        leaves, parent = visit(self.tree)
        self.assertEqual(expected_paths, paths_for_sum(self.tree, test_limit, leaves, parent))

        test_limit = 10
        expected_paths = [[7, 3], [6, 1, 3], [6, 4]]
        self.assertEqual(expected_paths, paths_for_sum(self.tree, test_limit, leaves, parent))

        test_limit = 5
        expected_paths = []
        self.assertEqual(expected_paths, paths_for_sum(self.tree, test_limit, leaves, parent))


if __name__ == "__main__":
    tree = TNode(5)
    tree.left = TNode(3)
    tree.right = TNode(4)
    tree.left.left = TNode(7)
    tree.left.right = TNode(1)
    tree.left.right.left = TNode(6)
    tree.right.left = TNode(2)
    tree.right.right = TNode(6)
    tree.right.left.left = TNode(1)
    tree.right.left.right = TNode(3)
    tree.right.left.right.left = TNode(6)

    leaves, parent = visit(tree)
    for i in leaves:
        print(i)
    print('==========')
    for item in parent:
        print(item, ": ", parent[item])
    limit = 10
    res = paths_for_sum(tree, limit, leaves, parent)
    print(res)
