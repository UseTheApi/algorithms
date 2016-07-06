//
//  binaryTree.cpp
//  algorithms
//
//  Created by alifar on 6/25/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "binarySearchTree.hpp"
#include <iostream>

Tnode::Tnode(int new_data){
    data = new_data;
    left = 0; // same as NULL
    right = 0;
}

Bst::Bst(){
    this->root = 0;
}

Tnode * Bst::getRoot(){
    return this->root;
}

void Bst::setRoot(Tnode *node){
    this->root = node;
}

void Bst::insertHelper(Tnode *root, int new_data){
    // Inserts a node to a tree with given root
    Tnode *node = new Tnode(new_data);
    if(new_data >= root->data){
        if(!root->right){
            root->right = node;
        } else{
            insertHelper(root->right, new_data);
        }
    } else{
        if(!root->left){
            root->left = node;
        } else{
            insertHelper(root->left, new_data);
        }
    }
}

void Bst::insert(int new_data){
    // inserts a node to a tree using private insertHelper
    if(!root){
        root = new Tnode(new_data);
    } else{
        insertHelper(root, new_data);
    }
}

Tnode * Bst::searchHelper(Tnode *root, int key){
    if(root->data == key) return root;
    if(key > root->data){
        return searchHelper(root->right, key);
    }
    return searchHelper(root->left, key);
}

Tnode * Bst::search(int key){
    if(!root) return root;
    else return searchHelper(root, key);
}

Tnode * Bst::findMinHelper(Tnode *root){
    Tnode *cur = root;
    while(cur->left){
        cur = cur->left;
    }
    return cur;
}

Tnode * Bst::findMin(){
    if(!root) return root;
    return findMinHelper(root);
}

Tnode * Bst::findSubtreeMin(Tnode *node){
    if(!node) return node;
    return findMinHelper(node);
}

Tnode * Bst::removeHelper(Tnode *root, int key) {
    if(key > root->data){
        root->right = removeHelper(root->right, key);
    } else if(key < root->data){
        root->left = removeHelper(root->left, key);
    } else{
        if(!root->left){
            Tnode *tmp = root->right;
            delete root;
            return tmp;
        } else if(!root->right){
            Tnode *tmp = root->left;
            delete root;
            return tmp;
        } else{
            Tnode *minRight = findSubtreeMin(root->right);
            root->data = minRight->data;
            root->right = removeHelper(root->right, minRight->data);
        }
    }
    return root;
}

Tnode * Bst::remove(int key) {
    if(!this->root) return root;
    return this->removeHelper(this->root, key);
}