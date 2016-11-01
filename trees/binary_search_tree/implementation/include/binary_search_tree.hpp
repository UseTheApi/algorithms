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
	BinarySearchTree<T> * Search(T);
	BinarySearchTree<T> * Min();
	BinarySearchTree<T> * SubtreeMin(BinarySearchTree<T> *);
	void Remove(T);

	T get_data();
	void set_data(T);
	BinarySearchTree<T> * get_right();
	void set_right(BinarySearchTree<T> *);
	BinarySearchTree<T> * get_left();
	void set_left(BinarySearchTree<T> *);
	BinarySearchTree<T> * get_root();
	void set_root(BinarySearchTree<T> *);

private:
	T data_;
	BinarySearchTree<T> *right_;
	BinarySearchTree<T> *left_;
	BinarySearchTree<T> *root_;
	BinarySearchTree<T> * get_min(BinarySearchTree<T> *);
	
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	right_ = 0;
	left_ = 0;
	root_ = 0;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(T init_data){
	data_ = init_data;
	right_ = new BinarySearchTree();
	left_ = new BinarySearchTree();
	root_ = new BinarySearchTree();
}

template <class T>
T BinarySearchTree<T>::get_data(){
	return data_;
}

template <class T>
void BinarySearchTree<T>::set_data(T new_data){
	data_ = new_data;
}

template <class T>
BinarySearchTree<T> * BinarySearchTree<T>::get_right(){
	return right_;
}

template <class T>
void BinarySearchTree<T>::set_right(BinarySearchTree<T> *new_right){
	right_ = new_right;
}

template <class T>
BinarySearchTree<T> * BinarySearchTree<T>::get_left(){
	return left_;
}

template <class T>
void BinarySearchTree<T>::set_left(BinarySearchTree<T> *new_left){
	left_ = new_left;
}

template <class T>
BinarySearchTree<T> * BinarySearchTree<T>::get_root(){
	return root_;
}

template <class T>
void BinarySearchTree<T>::set_root(BinarySearchTree<T> *new_root){
	root_ = new_root;
}

template <class T>
void BinarySearchTree<T>::Insert(T new_data){
	if(!root_){
		root_ = new BinarySearchTree<T>(new_data);
		return;
	}
	if(new_data >= root_->data_){
		if(!root_->right_){
			BinarySearchTree<T> *new_node = new BinarySearchTree<T>(new_data);
			root_->right_ = new_node;
		} else{
			root_->right_->Insert(new_data);
		}
	} else{
		if(!root_->left_){
			BinarySearchTree<T> *new_node = new BinarySearchTree<T>(new_data);
			root_->left_ = new_node;
		} else{
			root_->left_->Insert(new_data);
		}
	}
}

template <class T>
BinarySearchTree<T> * BinarySearchTree<T>::Search(T key){
	if(!root_){
		return root_;
	}
	if(root_->data_ == key){
		return root_;
	}
	if(key > root_->data_){
		root_->right_->Search(key);
	} else{
		root_->left_->Search(key);
	}
}

template <class T>
BinarySearchTree<T> * BinarySearchTree<T>::get_min(BinarySearchTree *node){
	BinarySearchTree<T> *current = node;
	while(current->left_){
		current = current->left_;
	}
	return current;
}

template <class T>
BinarySearchTree<T> * BinarySearchTree<T>::Min(){
	if(!root_){
		return root_;
	}
	return get_min(root_);
}

template <class T>
BinarySearchTree<T> * BinarySearchTree<T>::SubtreeMin(BinarySearchTree<T> *node){
	if(!node){
		return node;
	}
	return get_min(node);
}

template <class T>
void BinarySearchTree<T>::Remove(T key){
	if(!root_){
		return;
	}
	if(key > root_->data_){
		root_->right_->Remove(key);
	} else if(key < root_->data_){
		root_->left_->Remove(key);
	} else{
		if(!root_->left_){
			BinarySearchTree * tmp = root_->right_;
			delete root_;
			root_ = tmp;
		} else if(!root_->right_){
			BinarySearchTree * tmp = root_->left_;
			delete root_;
			root_ = tmp;
		} else{
			BinarySearchTree *right_min = root_->SubtreeMin(root_->right_);
			root_->data_ = right_min->data_;
			root_->right_->Remove(right_min->data_);
		}
	}
}
