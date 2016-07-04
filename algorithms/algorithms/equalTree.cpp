//
//  equalTree.cpp
//  algorithms
//
//  Created by alifar on 7/3/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <queue>
#include <iostream>
#include "equalTree.hpp"
#include "binarySearchTree.hpp"

/*
 Given pointers to two trees. Write a function to determine whether trees are equal or not.
*/

bool equalTrees(Tnode *root1, Tnode *root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    std::queue<Tnode *> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() && !q2.empty()){
        Tnode *n1 = q1.front();
        Tnode *n2 = q2.front();
        q1.pop();
        q2.pop();
        if(n1->data != n2->data) return false;
        if(n1->left && n2->left){
            q1.push(n1->left);
            q2.push(n2->left);
        } else if(n1->left || n2->left){
            return false;
        }
        if(n1->right && n2->right){
            q1.push(n1->right);
            q2.push(n2->right);
        } else if(n1->right || n2->right){
            return false;
        }
    }
    return true;
}