//
//  t_node.hpp
//  algorithms. BST implementation.
//
//  Created by alifar on 12/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <iostream>

template <class N>
struct Tnode{
		N data;
		int height; // height of node is used in AVL implementation
		Tnode *left;
		Tnode *right;
		Tnode *parent;
		Tnode(N);
		template <class TN>
		friend std::ostream & operator<< (std::ostream &os, const Tnode<TN> *node);
};

template <class N>
Tnode<N>::Tnode(N init_data){
	data = init_data;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

template <class TN>
std::ostream & operator<<(std::ostream &os, const Tnode<TN> *node){
	os << node->data;
	return os;
}
