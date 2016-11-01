//
//  traversals.hpp
//  algorithms. BST traversals.
//
//  Created by alifar on 11/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <binary_search_tree.hpp>
#include <iostream>

template <class T>
void InOrder(BinarySearchTree<T> *tree){
	if(tree->get_root()){
		InOrder(tree->get_root()->get_left());
		std::cout << tree->get_root()->get_data() << " ";
		InOrder(tree->get_root()->get_right());
	}
}

template <class T>
void PreOrder(BinarySearchTree<T> *tree){
	if(tree->get_root()){
		std::cout << tree->get_root()->get_data() << " ";
		PreOrder(tree->get_root()->get_left());
		PreOrder(tree->get_root()->get_right());
	}
}

template <class T>
void PostOrder(BinarySearchTree<T> *tree){
	if(tree->get_root()){
		PreOrder(tree->get_root()->get_left());
		PreOrder(tree->get_root()->get_right());
		std::cout << tree->get_root()->get_data() << " ";
	}
}