//
//  traversals.hpp
//  algorithms. BST traversals.
//
//  Created by alifar on 11/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <binary_search_tree.hpp>
#include <iostream>

template <class I>
void InOrder(Tnode<I> *root){
	if(root){
		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}
}

template <class I>
void PostOrder(Tnode<I> *root){
	if(root){
		PostOrder(root->left);
		PostOrder(root->right);
		std::cout << root->data << " ";
	}
}

template <class I>
void PreOrder(Tnode<I> *root){
	if(root){
		std::cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
