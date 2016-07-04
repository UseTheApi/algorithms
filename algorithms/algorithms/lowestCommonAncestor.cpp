//
//  lowestCommonAncestor.cpp
//  algorithms
//
//  Created by alifar on 7/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "lowestCommonAncestor.hpp"

/*
    Given two nodes in a tree. Write a function that will return the lowest common ancestor for given two nodes in BST.
 
    Solution 1 - use a point to parent for nodes:
        1. if node1 and node2 are in different subtrees of root (left and right), then the most common ancestor is root
        2. else if node1 and node2 are in left subtree then recursively call the function from root->left
        3. else - recursively call function with root->right
 */

