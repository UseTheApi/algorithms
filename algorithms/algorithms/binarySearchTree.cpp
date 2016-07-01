//
//  binaryTree.cpp
//  algorithms
//
//  Created by alifar on 6/25/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "binarySearchTree.hpp"
#include <iostream>

Tnode::Tnode(int data){
    this->data = data;
    this->left = 0; // same as NULL
    this->right = 0;
}

Bst::Bst(){
    this->root = 0;
}

Tnode * Bst::getRoot(){
    return this->root;
}

void Bst::insertHelper(Tnode *root, int data){
    // Inserts a node to a tree with given root
    Tnode *node = new Tnode(data);
    if(data >= root->data){
        if(!root->right){
            root->right = node;
        } else{
            this->insertHelper(root->right, data);
        }
    } else{
        if(!root->left){
            root->left = node;
        } else{
            this->insertHelper(root->left, data);
        }
    }
}

void Bst::insert(int data){
    // inserts a node to a tree using private insertHelper
    if(!this->root){
        this->root = new Tnode(data);
    } else{
        this->insertHelper(root, data);
    }
}

Tnode * Bst::searchHelper(Tnode *root, int key){
    if(root->data == key) return root;
    if(key >= root->data){
        return this->searchHelper(root->right, key);
    }
    return this->searchHelper(root->left, key);
}

Tnode * Bst::search(int key){
    if(!root) return this->root;
    else return this->searchHelper(this->root, key);
}

Tnode * Bst::findMinHelper(Tnode *root){
    Tnode *cur = root;
    while(cur->left){
        cur = cur->left;
    }
    return cur;
}

Tnode * Bst::findMin(){
    if(!this->root) return this->root;
    return this->findMinHelper(this->root);
}

Tnode * Bst::findSubtreeMin(Tnode *node){
    if(!node) return node;
    return this->findMinHelper(node);
}