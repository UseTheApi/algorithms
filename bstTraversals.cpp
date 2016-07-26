//
//  bstTraversals.cpp
//  algorithms
//
//  Created by alifar on 6/30/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include "bstTraversals.hpp"

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

void inOrderTraversalNoRecursion(Tnode *root){
    /*
     Morris Traversal
     */
    Tnode *pre = 0;
    Tnode *current = root;
    if(!root){
        return;
    }
    while(current){
        if(!current->left){
            std::cout << current->data << " ";
            current = current->right;
        } else{
            pre = current->left;
            if(pre->right && pre->right!=current){
                pre = pre->right;
            }
            if(!pre->right){
                pre->right = current;
                current = current->left;
            } else{
                pre->right = 0;
                std::cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

void breadthFirstTraversalQueue(Tnode *root){
    /*
     Level Order Traversal. Using Queue
     */
    if(!root) return;
    std::queue<Tnode *> q;
    q.push(root);
    while (!q.empty()) {
        Tnode *current = q.front();
        std::cout << current->data << " ";
        q.pop();
        if(current->left){
            q.push(current->left);
        }
        if(current->right){
            q.push(current->right);
        }
    }
}

int height(Tnode *root){
    if(!root) return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if(lheight > rheight)
        return lheight+1;
    else
        return rheight+1;
}

void printLevelNodes(Tnode *root, int level){
    if(!root) return;
    if(level == 1){
        std::cout << root->data << " ";
    } else{
        printLevelNodes(root->left, level-1);
        printLevelNodes(root->right, level-1);
    }
}

void breadthFirstTraversalHeight(Tnode *root){
    /*
     This function prints nodes level by level using height of the tree
     */
    int h = height(root);
    for(int i=1; i <= h; ++i){
        printLevelNodes(root, i);
    }
}
