//
//  binaryTree.hpp
//  algorithms
//
//  Created by alifar on 6/25/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef binaryTree_hpp
#define binaryTree_hpp

#include <stdio.h>

struct Tnode{
    int data;
    Tnode *left;
    Tnode *right;
    Tnode(int data);
private:
    Tnode();
};

struct BinaryTree{
    Tnode *root;
    BinaryTree(int data);
    void inOrderTraversal();
};

#endif /* binaryTree_hpp */
