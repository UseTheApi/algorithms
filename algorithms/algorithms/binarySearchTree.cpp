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

void inOrderTraversal(Tnode *root){
    // recursive in order traversal
    if(root){
        preOrderTraversal(root->left);
        std::cout << root->data << " ";
        preOrderTraversal(root->right);
    }
}

void preOrderTraversal(Tnode *root){
    // recursive pre order traversal
    if(root){
        std::cout << root->data << " ";
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(Tnode *root){
    // recursive post order traversal
    if(root){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data << " ";
    }
}