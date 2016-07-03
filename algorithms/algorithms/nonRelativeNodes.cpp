//
//  nonRelativeNodes.cpp
//  algorithms
//
//  Created by alifar on 7/2/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "nonRelativeNodes.hpp"
#include "binarySearchTree.hpp"

/*
 Given a pointer to the root of BST. Write a function that will return the max set of nodes that are not children or parents for each other.
 Solution:
    1. Calculate height of a given tree
    2. Create a function that returns vector of nodes for given level
    3. Iterate through a hight and collect all even and odd level nodes
    4. Return a vector of max size
*/

int heightTree(Tnode *root){ // O(n) complexity
    if(!root) return 0;
    int lheight = heightTree(root->left);
    int rheight = heightTree(root->right);
    if(lheight > rheight){
        return lheight+1;
    } else{
        return rheight+1;
    }
}

std::vector<Tnode *> collectLevelNodes(Tnode *root, int level, std::vector<Tnode *> &result){ // level = 1, root=7, res=7
    if(!root) return result;                                                                  // level = 2, root=10, res=10,5
    if(level == 1){                                                                           // O(l) complexity
        result.push_back(root);
        return result;
    }
    else{
        collectLevelNodes(root->right, level-1, result);
        collectLevelNodes(root->left, level-1, result);
    }
    return result;
}

std::vector<Tnode *> nonRelativeNodes(Tnode *root){ // O(h)*O(l) + O(n) complexity of the solution
    int h = heightTree(root);
    std::vector<Tnode *> even_nodes;
    std::vector<Tnode *> odd_nodes;
    for(int i=1; i <= h; ++i){
        if(i%2 == 0){
            std::vector<Tnode *> result;
            result = collectLevelNodes(root, i, result);
            even_nodes.insert(even_nodes.end(), result.begin(), result.end());
        }
        else{
            std::vector<Tnode *> result;
            result = collectLevelNodes(root, i, result);
            odd_nodes.insert(odd_nodes.end(), result.begin(), result.end());
        }
    }
    if(even_nodes.size() > odd_nodes.size()) return even_nodes;
    else return odd_nodes;
}