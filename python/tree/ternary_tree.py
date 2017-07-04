"""
Build a binary tree from a given ternary string: a ? b ? c : d : e
"""


class TreeNode(object):
    def __init__(self, init_data=None):
        self.data = init_data
        self.left = None
        self.right = None

    def __str__(self):
        return str(self.data)


def traverse(tree_root):
    if not tree_root:
        return
    traverse(tree_root.left)
    print(tree_root, end=' ')
    traverse(tree_root.right)


if __name__ == "__main__":
    s = 'a?b?c:d:e'
    print(s)
    root = TreeNode(5)
    root.left = TreeNode(4)
    root.right = TreeNode(7)
    traverse(root)
    print()
    for i in range(len(s)):
        print(s[i])
