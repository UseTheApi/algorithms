# Trees

A tree is a widely used abstract data type (ADT)—or data structure implementing this ADT—that simulates a hierarchical tree structure, with a root value and subtrees of children with a parent node, represented as a set of linked nodes.

A tree data structure can be defined recursively (locally) as a collection of nodes (starting at a root node), where each node is a data structure consisting of a value, together with a list of references to nodes (the "children"), with the constraints that no reference is duplicated, and none points to the root.

## Binary Tree

Binary Tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. A recursive definition using just set theory notions is that a (non-empty) binary tree is a tuple ```(L, S, R)```, where L and R are binary trees or the empty set and S is a singleton set. Some authors allow the binary tree to be the empty set as well.

# Tasks

### All Paths With ```sum```

Given a **binary tree** in which each node contains a value and a **value**. Design an algorithm
to print all paths which sum up to the given value.

 *[Note]*: that it can be any path in the tree - it does not have to start at the root.

 [*source*](all_paths_with_sum.py)

 ### Duplicated Subtrees

 Given a binary tree, find all duplicate subtrees.
 Two trees are duplicate if they have the same structure with same node values.

  **Example**:

  Input :
  ```
       1
      / \
     2   3
    /   / \
   4   2   4
      /
     4
```

Output :
```
   2           
  /    and    4
 4
```
Explanation: Above Trees are two duplicate subtrees.
Therefore, you need to return above trees traversals in the
form of a list.

  [*source*](duplicated_subtrees.py)

 To run tests:

 ```pytest <name_of_file>```

 To run source:

 ```python3 <name_of_file>```
