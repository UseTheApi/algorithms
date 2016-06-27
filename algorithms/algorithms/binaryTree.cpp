//
//  binaryTree.cpp
//  algorithms
//
//  Created by alifar on 6/25/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "binaryTree.hpp"
#include <iostream>

Tnode::Tnode(int data){
    this->data = data;
    this->left = 0;
    this->right = 0;
}

BinaryTree::BinaryTree(int data){
    this->root = new Tnode(data);
}

// not right
void BinaryTree::inOrderTraversal(){
    if (!this->root){
        return;
    }
    Tnode *current = root;
    while(current!=0){
        if(current->left == 0){
            std::cout << current->data << " ";
            current = current->right;
        }
        if(current != 0){
            Tnode * left_child = current->left;
            while(left_child->left !=0){
                left_child = left_child->left;
            }
            current = left_child;
        }
    }
}