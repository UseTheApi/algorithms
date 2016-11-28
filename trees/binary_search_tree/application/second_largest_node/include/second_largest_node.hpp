//
//  second_largest_node.hpp
//  algorithms. BST application.
//
//  Created by alifar on 10/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <binary_search_tree.hpp>

/*
 Write a function to return the second largest node of a tree/subtree
*/

template <class T>
Tnode<T> * LargestNode(Tnode<T> *root){
	if(!root){
		return nullptr;
	}
	while(root->right){
		root = root->right;
	}
	return root;
}

template <class T>
Tnode<T> * SecondLargestNode(Tnode<T> *root){
	if(!root){
		return nullptr;
	}
	while(root){
		if(!root->right && root->left){
			return LargestNode(root->left);
		} else if(root->right && (!root->right->right && !root->right->left)){
			return root;
		}
		if(!root->right){
			return root;
		}
		root = root->right;
	}
}
