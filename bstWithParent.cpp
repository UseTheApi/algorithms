//
//  bstWithParent.cpp
//  algorithms
//
//  Created by alifar on 7/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "bstWithParent.hpp"

BstNodeWithParent::BstNodeWithParent(int new_data){
    data = new_data;
    left = 0;
    right = 0;
    parent = 0;
}

BstWithParent::BstWithParent(){
    root = 0;
}

BstNodeWithParent * BstWithParent::getRoot(){
    return root;
}

void BstWithParent::setRoot(BstNodeWithParent *node){
    root = node;
}

BstNodeWithParent * BstWithParent::insert(BstNodeWithParent *root, int new_data) {
    BstNodeWithParent *node = new BstNodeWithParent(new_data);
    if(!root){
        return node;
    }
    BstNodeWithParent *tmp = 0;
    if(new_data >= root->data){
        tmp = insert(root->right, new_data);
        root->right = tmp;
        tmp->parent = root;
    } else{
        tmp = insert(root->left, new_data);
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
        return search(root->right, key);
    }
    return search(root->left, key);
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
        root->right = remove(root->right, key);
    } else if(key < root->data){
        root->left = remove(root->left, key);
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
            BstNodeWithParent *minRight = findMin(root->right);
            root->data = minRight->data;
            root->right = remove(root->right, minRight->data);
        }
    }
    return root;
}
