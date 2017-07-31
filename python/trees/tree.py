class TreeNode(object):
    def __init__(self, init_data=None):
        self.data = init_data
        self.left = None
        self.right = None

    def __str__(self):
        return str(self.data)


def traverse(root):
    if not root:
        return
    traverse(root.left)
    print(root, end=' ')
    traverse(root.right)