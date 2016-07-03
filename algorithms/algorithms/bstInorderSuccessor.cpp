//
//  bstInorderSuccessor.cpp
//  algorithms
//
//  Created by alifar on 7/2/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "bstInorderSuccessor.hpp"

/*
 Write a function that will find an In-order successor (next node after given node in inOrder traversal) for a give node in BST
 
 Method 1 (when each node has a parent pointer)
 Method 2 (when root is provided)
*/

BstNodeWithParent::BstNodeWithParent(int data){
    this->data = data;
    this->left = 0;
    this->right = 0;
    this->parent = 0;
}

BstWithParent::BstWithParent(){
    this->root = 0;
}

BstNodeWithParent * BstWithParent::getRoot(){
    return this->root;
}

void BstWithParent::setRoot(BstNodeWithParent *node){
    this->root = node;
}

BstNodeWithParent * BstWithParent::insert(BstNodeWithParent *root, int data) {
    BstNodeWithParent *node = new BstNodeWithParent(data);
    if(!root){
        return node;
    }
    BstNodeWithParent *tmp = 0;
    if(data >= root->data){
        tmp = this->insert(root->right, data);
        root->right = tmp;
        tmp->parent = root;
    } else{
        tmp = this->insert(root->left, data);
        root->left = tmp;
        tmp->parent = root;
    }
    return root;
}

BstNodeWithParent * BstWithParent::search(BstNodeWithParent *root, int key){
    if(!root || root->data == key){
        return root;
    }
    if(key > root->data){
        return this->search(root->right, key);
    }
    return this->search(root->left, key);
}

BstNodeWithParent * BstWithParent::findMin(BstNodeWithParent *node){
    if(!node) return node;
    while(!node){
        node = node->left;
    }
    return node;
}

BstNodeWithParent * BstWithParent::remove(BstNodeWithParent *root, int key){
    if(!root) return root;
    if(key > root->data){
        root->right = this->remove(root->right, key);
    } else if(key < root->data){
        root->left = this->remove(root->left, key);
    } else{
        if(!root->left){
            BstNodeWithParent *tmp = root->right;
            delete root;
            return tmp;
        } else if(!root->right){
            BstNodeWithParent *tmp = root->left;
            delete root;
            return tmp;
        } else{
            BstNodeWithParent *minRight = this->findMin(root->right);
            root->data = minRight->data;
            root->right = this->remove(root->right, minRight->data);
        }
    }
    return root;
}

BstNodeWithParent * BstWithParent::findSuccessorByParent(BstNodeWithParent *node){
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

BstNodeWithParent * BstWithParent::findSuccessorByRoot(BstNodeWithParent *root, BstNodeWithParent *node){
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