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

void Bst::insertHelper(Tnode *root, int data){
    
}