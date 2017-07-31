"""
Given Tree traversals - calculate actual tree
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


def full_and_complete_tree_from_in_order(in_order, begin, end):
    if begin == end:
        return None
    root_i = (begin+end)//2
    t_root = TreeNode(in_order[root_i])
    t_root.left = full_and_complete_tree_from_in_order(in_order, begin, root_i)
    t_root.right = full_and_complete_tree_from_in_order(in_order, root_i+1, end)
    return t_root


def full_and_complete_tree_from_pre_order(pre_order, begin, end):
    if begin == end:
        return None
    t_root = TreeNode(pre_order[begin])
    begin += 1
    t_root.left = full_and_complete_tree_from_pre_order(pre_order, begin, (begin+end)//2)
    t_root.right = full_and_complete_tree_from_pre_order(pre_order, (begin+end)//2, end)
    return t_root


def a_tree_from_in_pre_orders(in_order, pre_order):
    if not in_order or not pre_order:
        return None
    root_i = in_order.index(pre_order[0])
    t_root = TreeNode(in_order[root_i])
    t_root.left = a_tree_from_in_pre_orders(in_order[0:root_i], pre_order[1:root_i+1])
    t_root.right = a_tree_from_in_pre_orders(in_order[root_i+1:], pre_order[root_i+1:])
    return t_root


if __name__ == "__main__":
    traversal = [1, 2, 3, 5, 6, 8, 9]
    root = full_and_complete_tree_from_in_order(in_order=traversal, begin=0, end=len(traversal))
    traverse(root)
    pre_traversal = [5, 2, 1, 3, 8, 6, 9]
    pre_root = full_and_complete_tree_from_pre_order(pre_order=pre_traversal, begin=0, end=len(pre_traversal))
    print()
    traverse(pre_root)

    in_order_a_tree = [1, 3, 5, 6, 8, 10]
    pre_order_a_tree = [5, 3, 1, 8, 6, 10]
    a_tree_root = a_tree_from_in_pre_orders(in_order_a_tree, pre_order_a_tree)
    print()
    traverse(a_tree_root)
