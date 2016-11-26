//
//  in_order_successor.hpp
//  algorithms. BST application
//
//  Created by alifar on 11/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <binary_search_tree.hpp>

/*
 Write a function that will find an In-order successor (next node after given node in inOrder traversal) for a give node in BST
 
 Method 1 (when each node has a parent pointer)
 Method 2 (when root is provided)
*/

template <class T>
Tnode<T> * MinNode(Tnode<T> *node){
	if(!node){
		return nullptr;
	}
	while(node->left){
		node = node->left;
	}
	return node;
}

template <class T>
Tnode<T> * InOrderSuccessorRoot(Tnode<T> *root, Tnode<T> *node){
	if(!root){
		return nullptr;
	}
	if(node->right){
		return MinNode(node->right);
	}
	Tnode<T> *successor = nullptr;
	while(root){
		if(node->data < root->data){
			successor = root
			root = root->left;
		} else if(node->data > root->data){
			root = root->right;
		} else{
			break;
		}
	}
	return successor;
}

template <class T>
Tnode<T> * InOrderSuccessorParent(Tnode<T> *node){
	if(node->right){
		return MinNode(node->right);
	}
	Tnode<T> *p = node->parent;
	while(p && node == p->right){
		node = p;
		p = p->parent;
	}
	return p;
}
