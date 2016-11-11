//
//  binary_search_tree.hpp
//  algorithms. BST implementation.
//
//  Created by alifar on 10/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>
#include <iostream>

template <class N>
struct Tnode{
		N data;
		Tnode *left;
		Tnode *right;
		Tnode(N);
};

template <class T>
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(T);
	void Insert(T);
	Tnode<T> * Search(T);
	// Tnode * Min();
	// Tnode * SubtreeMin(Tnode *);
	// void Remove(T);
	T get_root(){
		return root->data;
	}

	//Tnode(): data(0), left(nullptr), right(nullptr){};
	// Tnode(T init_data){
	// 	data = init_data;
	// 	left = nullptr;
	// 	right = nullptr;
	// }; 
	Tnode<T> *root;

// private:
	
// 	Tnode * get_min(BinarySearchTree<T> *);
	
};

template <class N>
Tnode<N>::Tnode(N init_data){
	data = init_data;
	left = nullptr;
	right = nullptr;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root = nullptr;
}

template <class T>
Tnode<T> * BinarySearchTree<T>::Search(T key){
	if(!root){
		return nullptr;
	}
	Tnode<T> *cur = root;
	while(cur && cur->data != key){
		cur = key > cur->data ? cur=cur->right : cur=cur->left;
	}
	return cur;
}

template <class T>
void BinarySearchTree<T>::Insert(T new_data){
	Tnode<T> *new_node = new Tnode<T>(new_data);
	if(!root){
		root = new_node;
		return;
	}
	Tnode<T> *tmp = nullptr;
	Tnode<T> *cur = root;
	while(cur){
		tmp = cur;
		cur = new_data >= root->data ? cur->right : cur->left;
	}
	if(new_data >= tmp->data){
		tmp->right = new_node;
	} else{
		tmp->left = new_node;
	}
}

template <class T>

// template <class T>
// BinarySearchTree<T> * BinarySearchTree<T>::get_min(BinarySearchTree *node){
// 	BinarySearchTree<T> *current = node;
// 	while(current->left_){
// 		current = current->left_;
// 	}
// 	return current;
// }

// template <class T>
// BinarySearchTree<T> * BinarySearchTree<T>::Min(){
// 	if(!root_){
// 		return root_;
// 	}
// 	return get_min(root_);
// }

// template <class T>
// BinarySearchTree<T> * BinarySearchTree<T>::SubtreeMin(BinarySearchTree<T> *node){
// 	if(!node){
// 		return node;
// 	}
// 	return get_min(node);
// }

// template <class T>
// void BinarySearchTree<T>::Remove(T key){
// 	if(!root_){
// 		return;
// 	}
// 	if(key > root_->data_){
// 		root_->right_->Remove(key);
// 	} else if(key < root_->data_){
// 		root_->left_->Remove(key);
// 	} else{
// 		if(!root_->left_){
// 			BinarySearchTree * tmp = root_->right_;
// 			delete root_;
// 			root_ = tmp;
// 		} else if(!root_->right_){
// 			BinarySearchTree * tmp = root_->left_;
// 			delete root_;
// 			root_ = tmp;
// 		} else{
// 			BinarySearchTree *right_min = root_->SubtreeMin(root_->right_);
// 			root_->data_ = right_min->data_;
// 			root_->right_->Remove(right_min->data_);
// 		}
// 	}
// } 
