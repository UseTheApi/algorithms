//
//  bstTraversals.hpp
//  algorithms
//
//  Created by alifar on 6/30/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef bstTraversals_hpp
#define bstTraversals_hpp

#include <stdio.h>
#include "binarySearchTree.hpp"

void preOrderTraversal(Tnode *root);
void inOrderTraversal(Tnode *root);
void postOrderTraversal(Tnode *root);
void inOrderTraversalStack(Tnode *root);
void inOrderTraversalNoRecursion(Tnode *root);
void breadthFirstTraversalQueue(Tnode *root);
void breadthFirstTraversalHeight(Tnode *root);


#endif /* bstTraversals_hpp */
