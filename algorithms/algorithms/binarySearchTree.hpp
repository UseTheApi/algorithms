//
//  binaryTree.hpp
//  algorithms
//
//  Created by alifar on 6/25/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef binarySearchTree_hpp
#define binarySearchTree_hpp

#include <stdio.h>

struct Tnode{
    int data;
    Tnode *left;
    Tnode *right;
    Tnode(int data);
private:
    Tnode();
};

class Bst {
public:
    Tnode * getRoot();
    void * setRoot();
    void insert(int data);
    Tnode * search(int key);
    Tnode * findMin();
    Tnode * findMinSubtree(Tnode *node);
    Tnode * remove(int key);
    Bst();
private:
    Tnode *root;
    void insertHelper(Tnode *root, int data);
    Tnode * searchHelper(Tnode *root, int key);
    Tnode * findMinHelper(Tnode *root);
    Tnode * removeHelper(Tnode *root, int key); // remove noe with given key and return new root of the tree
};

void preOrderTraversal(Tnode *root);
void inOrderTraversal(Tnode *root);
void postOrderTraversal(Tnode *root);

#endif /* binaryTree_hpp */
