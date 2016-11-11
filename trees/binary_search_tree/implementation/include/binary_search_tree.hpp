//
//  binary_search_tree.hpp
//  algorithms. BST implementation.
//
//  Created by alifar on 10/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>
#include <iostream>

template <class T>
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(T);
	void Insert(T);
	// Tnode * Search(T);
	// Tnode * Min();
	// Tnode * SubtreeMin(Tnode *);
	// void Remove(T);
	T get_root(){
		return root->data;
	}

protected:
	struct Tnode{
		T data;
		Tnode *left;
		Tnode *right;
	};
	//Tnode(): data(0), left(nullptr), right(nullptr){};
	// Tnode(T init_data){
	// 	data = init_data;
	// 	left = nullptr;
	// 	right = nullptr;
	// }; 

	Tnode *root;

private:
	Tnode * get_min(BinarySearchTree<T> *);
	
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	Tnode();
	root = nullptr;
}

// template <class T>
// BinarySearchTree<T>::BinarySearchTree(T init_data){
// 	Tnode(init_data);
// 	root = nullptr;
// }

template <class T>
void BinarySearchTree<T>::Insert(T new_data){
	Tnode *new_node = new Tnode();
	new_node->data = new_data;
	Tnode *tmp = nullptr;
	if(!root){
		root = new_node;
		return;
	}

	Tnode * current = root;
	while(current){
		tmp = current;
		current = new_node->data >= current->data ? current->right : current->left;
	}

	if(new_node->data >= tmp->data){
		tmp->right = new_node;
	} else{
		tmp->left = new_node;
	}
}

// template <class T>
// BinarySearchTree<T> * BinarySearchTree<T>::Search(T key){
// 	if(!root_){
// 		return root_;
// 	}
// 	if(root_->data_ == key){
// 		return root_;
// 	}
// 	if(key > root_->data_){
// 		root_->right_->Search(key);
// 	} else{
// 		root_->left_->Search(key);
// 	}
// }

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
// test 
