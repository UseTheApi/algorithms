class TNode(object):
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None


def traverse(root, res):
    if not root:
        return
    traverse(root.left, res)
    traverse(root.right, res)
    res.append(root.val)


def duplicates(root, buffer, res):
    if not root:
        return
    l_tr = list()
    traverse(root.left, l_tr)
    if l_tr and l_tr not in buffer:
        buffer.append(l_tr)
    else:
        if l_tr not in res:
            res.append(l_tr)

    r_tr = list()
    traverse(root.right, r_tr)
    if r_tr and r_tr not in buffer:
        buffer.append(r_tr)
    else:
        if r_tr not in res:
            res.append(r_tr)

    duplicates(root.left, buffer, res)
    duplicates(root.right, buffer, res)


if __name__ == "__main__":
    tree = TNode(1)
    tree.left = TNode(2)
    tree.left.left = TNode(4)
    tree.right = TNode(3)
    tree.right.left = TNode(2)
    tree.right.left.left = TNode(4)
    tree.right.right = TNode(4)

    buff = list()
    result = list()
    duplicates(tree, buffer=buff, res=result)
    print(result)
