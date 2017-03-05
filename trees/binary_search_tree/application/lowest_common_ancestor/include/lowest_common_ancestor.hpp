//
//  lowest_common_ancestor.hpp
//  algorithms. BST applications.
//
//  Created by alifar on 11/26/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "binary_search_tree.hpp"

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

template <class T>
Tnode<T> * LowestCommonAncestorRoot(Tnode<T> *root, Tnode<T> *n1, Tnode<T> *n2){
    /*
       This method will return one of the given nodes if they are ancestor to each other.
       */
    if(!root){
        return nullptr;
    }
    if(n1==root || n2==root){
        return nullptr;
    }
    if(n1->data >= root->data && n2->data >= root->data){
        return LowestCommonAncestorRoot(root->right, n1, n2);
    } else if(n1->data < root->data && n2->data < root->data){
        return LowestCommonAncestorRoot(root->left, n1, n2);
    }
    return root;
}

template <class T>
Tnode<T> * LowestCommonAncestorParent(Tnode<T> *n1, Tnode<T> *n2){
    /*
       This method will return an ancestor of the higher node from the given ones.
       */
    Tnode<T> *p1 = n1->parent;
    Tnode<T> *p2 = n2->parent;
    if(!p1 || !p2){
        return nullptr;
    }
    if(n1->data >= n2->data){
        while(p2->parent && p2->data != p1->data){
            if(p2->parent->data > p1->parent->data){
                return p2;
            } else{
                p2 = p2->parent;
            }
        }
        return p2;
    } else{
        while(p1->parent && p1->data != p2->data){
            if(p1->parent->data > p2->parent->data){
                return p1;
            } else{
                p1 = p1->parent;
            }
        }
        return p1;
    }
}
