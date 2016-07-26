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
 
    Solution 1 - if root of a tree is given:
        1. if node1 and node2 are in different subtrees of root (left and right), then the most common ancestor is root
        2. else if node1 and node2 are in left subtree then recursively call the function from root->left
        3. else - recursively call function with root->right
    Solution 2 - use a point to parent for nodes:
        1. collect parents for both n1 and n2
        2. if n1->data > n2->data then climb from n2 to top until reached n1->parent or n2->parent greater then n1->parent
        3. else: same for n1->data < n2->data
 */

BstNodeWithParent *Lca::lowestCommonAncesrotRoot(BstNodeWithParent *root, BstNodeWithParent *n1, BstNodeWithParent *n2){
    if(!root) return root;
    if(n1->data > root->data && n2->data > root->data){
        return lowestCommonAncesrotRoot(root->right, n1, n2);
    } else if(n1->data < root->data && n2->data < root->data){
        return lowestCommonAncesrotRoot(root->left, n1, n2);
    }
    return root;
}

BstNodeWithParent *Lca::lowestCommonAncestorParent(BstNodeWithParent *n1, BstNodeWithParent *n2){
    BstNodeWithParent *p1 = n1->parent;
    BstNodeWithParent *p2 = n2->parent;
    
    if(n1->data >= n2->data){
        while(p2->parent && p2->data != p1->data){
            if(p2->parent->data > p1->parent->data)
                return p2;
            else
                p2 = p2->parent;
        }
        return p2;
    } else{
        while(p1->parent && p1->data != p2->data){
            if(p1->parent->data > p2->parent->data)
                return p1;
            else
                p1 = p1->parent;
        }
        return p1;
    }
}
