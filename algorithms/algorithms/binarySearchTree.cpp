//
//  binaryTree.cpp
//  algorithms
//
//  Created by alifar on 6/25/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "binarySearchTree.hpp"
#include <iostream>
#include <stack>

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
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Tnode *root){
    // recursive pre order traversal
    if(root){
        std::cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
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

void inOrderTraversalStack(Tnode *root){
    /*
     Recursion uses a memory stack to store all function calls
     In this case we use our own dynamic stack
    */
    std::stack<Tnode *> s;
    Tnode * current = root;
    int done = 0;
    while(!done){
        if(current){
            s.push(current);
            current = current->left;
        } else{
            if(!s.empty()){
                std::cout << s.top()->data << " ";
                current = s.top();
                s.pop();
                current = current->right;
            } else{
                done = 1;
            }
        }
    }
}