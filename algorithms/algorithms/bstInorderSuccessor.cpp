//
//  bstInorderSuccessor.cpp
//  algorithms
//
//  Created by alifar on 7/2/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "bstWithParent.hpp"
#include "bstInorderSuccessor.hpp"

/*
 Write a function that will find an In-order successor (next node after given node in inOrder traversal) for a give node in BST
 
 Method 1 (when each node has a parent pointer)
 Method 2 (when root is provided)
*/

BstNodeWithParent * bstSuccessor::findSuccessorByParent(BstNodeWithParent *node){
    if(!node) return node;
    if(node->right){
        return this->findMin(node->right);
    } else{
        BstNodeWithParent *p = node->parent;
        while(p && node == p->right){
            node = p;
            p = p->parent;
        }
        return p;
    }
}

BstNodeWithParent * bstSuccessor::findSuccessorByRoot(BstNodeWithParent *root, BstNodeWithParent *node){
    if(!node) return node;
    if(node->right){
        return this->findMin(node->right);
    }
    BstNodeWithParent *successor = 0;
    while(root){
        if(node->data < root->data){
            successor = root;
            root = root->left;
        } else if(node->data > root->data){
            root = root->right;
        } else
            break;
    }
    return successor;
}
