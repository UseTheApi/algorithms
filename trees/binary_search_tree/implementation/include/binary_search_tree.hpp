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
class BinaryTree{
public:
	BinaryTree();
	BinaryTree(T);
	void Insert(T);
	BinaryTree<T> * Search(T);
	BinaryTree<T> * Min();
	BinaryTree<T> * SubtreeMin(BinaryTree<T> *);
	void Remove(T);

	T get_data();
	void set_data(T);
	BinaryTree<T> * get_right();
	void set_right(BinaryTree<T> *);
	BinaryTree<T> * get_left();
	void set_left(BinaryTree<T> *);
	BinaryTree<T> * get_root();
	void set_root(BinaryTree<T> *);

private:
	T data_;
	BinaryTree<T> *right_;
	BinaryTree<T> *left_;
	BinaryTree<T> *root_;
	BinaryTree<T> * get_min(BinaryTree<T> *);
	
};

template <class T>
BinaryTree<T>::BinaryTree(){
	right_ = 0;
	left_ = 0;
	root_ = 0;
}

template <class T>
BinaryTree<T>::BinaryTree(T init_data){
	data_ = init_data;
	right_ = 0;
	left_ = 0;
	root_ = 0;
}

template <class T>
T BinaryTree<T>::get_data(){
	return data_;
}

template <class T>
void BinaryTree<T>::set_data(T new_data){
	data_ = new_data;
}

template <class T>
BinaryTree<T> * BinaryTree<T>::get_right(){
	return right_;
}

template <class T>
void BinaryTree<T>::set_right(BinaryTree<T> *new_right){
	right_ = new_right;
}

template <class T>
BinaryTree<T> * BinaryTree<T>::get_left(){
	return left_;
}

template <class T>
void BinaryTree<T>::set_left(BinaryTree<T> *new_left){
	left_ = new_left;
}

template <class T>
BinaryTree<T> * BinaryTree<T>::get_root(){
	return root_;
}

template <class T>
void BinaryTree<T>::set_root(BinaryTree<T> *new_root){
	root_ = new_root;
}

template <class T>
void BinaryTree<T>::Insert(T new_data){
	if(!root_){
		root_ = new BinaryTree<T>(new_data);
		return;
	}
	if(new_data >= root_->data_){
		if(!root_->right_){
			BinaryTree<T> *new_node = new BinaryTree<T>(new_data);
			root_->right_ = new_node;
		} else{
			root_->right_->Insert(new_data);
		}
	} else{
		if(!root_->left_){
			BinaryTree<T> *new_node = new BinaryTree<T>(new_data);
			root_->left_ = new_node;
		} else{
			root_->left_->Insert(new_data);
		}
	}
}

template <class T>
BinaryTree<T> * BinaryTree<T>::Search(T key){
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
BinaryTree<T> * BinaryTree<T>::get_min(BinaryTree *node){
	BinaryTree<T> *current = node;
	while(current->left_){
		current = current->left_;
	}
	return current;
}

template <class T>
BinaryTree<T> * BinaryTree<T>::Min(){
	if(!root_){
		return root_;
	}
	return get_min(root_);
}

template <class T>
BinaryTree<T> * BinaryTree<T>::SubtreeMin(BinaryTree<T> *node){
	if(!node){
		return node;
	}
	return get_min(node);
}

template <class T>
void BinaryTree<T>::Remove(T key){
	if(!root_){
		return;
	}
	if(key > root_->data_){
		root_->right_->Remove(key);
	} else if(key < root_->data_){
		root_->left_->Remove(key);
	} else{
		if(!root_->left_){
			BinaryTree * tmp = root_->right_;
			delete root_;
			root_ = tmp;
		} else if(!root_->right_){
			BinaryTree * tmp = root_->left_;
			delete root_;
			root_ = tmp;
		} else{
			BinaryTree *right_min = root_->SubtreeMin(root_->right_);
			root_->data_ = right_min->data_;
			root_->right_->Remove(right_min->data_);
		}
	}
}
