"""

How many binary trees can one form from a given number of nodes

n = 3

    0           0     0             0      0
  /  \         /       \           /        \
0     0       0         0         0          0
             /           \         \        /
            0             0         0      0

answer: 5



"""


def n_trees(num, cur=1):
    if cur > num:
        return 0
    if cur == num:
        return 1

    if num - cur > 2:
        tmp = n_trees(num, cur+2) * 2
    else:
        tmp = n_trees(num, cur+2)
    return tmp + n_trees(num, cur+1) * 2


def dp_n_tress(num):
    num_trees = [0]*(num+1)
    num_trees[0] = 0
    num_trees[1] = 1
    num_trees[2] = 2

    for i in range(3, num+1):
        tmp = num_trees[i-2] if i-2 < 2 else num_trees[i-2] * 2
        num_trees[i] = tmp + num_trees[i-1]*2
    print(num_trees)
    return num_trees[num]


if __name__ == "__main__":
    print(dp_n_tress(10))
    print(n_trees(10))
