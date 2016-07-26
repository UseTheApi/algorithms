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
    Tnode(int);
private:
    Tnode();
};

class Bst {
public:
    Tnode * getRoot();
    void setRoot(Tnode *);
    void insert(int);
    Tnode * search(int);
    Tnode * findMin();
    Tnode * findSubtreeMin(Tnode *);
    Tnode * remove(int);
    Bst();
private:
    Tnode *root;
    void insertHelper(Tnode *, int);
    Tnode * searchHelper(Tnode *, int);
    Tnode * findMinHelper(Tnode *);
    Tnode * removeHelper(Tnode *, int); // remove noe with given key and return new root of the tree
};
#endif /* binaryTree_hpp */
