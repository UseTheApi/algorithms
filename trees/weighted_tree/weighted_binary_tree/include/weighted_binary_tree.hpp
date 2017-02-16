//
//  weighted_binary_tree.hpp
//  algorithms. weighted BST implementation.
//
//  Created by alifar on 02/12/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>

template <class N>
struct TWnode{
	N data;
	int distance;
	TWnode *left;
	TWnode *right;
	TWnode *parent;
	TWnode(N);
	template <class TN>
	friend std::ostream & operator<< (std::ostream &os, const Tnode<TN> *node);
	~TWnode(N);
};

template <class N>
TWnode<N>::TWnode(N init_data, int init_weight){
	data = init_data;
	distance = init_weight;
	weight = init_weight;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

template <class TN>
std::ostream & operator<< (str::ostream &os, const TWnode<TN> *node){
	os << node->data;
	return os;
}

template <class T>
class WeightedBst{
public:
	WeightedBst();
	void Insert(T, int);
	TWnode<T> * Search(T);
	TWnode<T> * Min();
	TWnode<T> * get_root();
	TWnode<T> * SubtreeMin(TWnode<T> *);
	void Remove(T);
private:
	TWnode<T> *root_;
	TWnode<T> * remove(TWnode<T> *, T);
}

template <class T>
WeightedBst<T>::WeightedBst(){
	root_ = nullptr;
}

template <class T>
TWnode<T> * WeightedBst<T>::get_root(){
	return root_;
}

template <class T>
void WeightedBst<T>::Insert(T new_data, int weight){
	TWnode<T> *new_node = new TWnode<T>(new_data, weight);
	if(!root_){
		root_ = new_node;
		return;
	}
	TWnode<T> *cur = root_;
	TWnode<T> *tmp = nullptr;
	while(cur){
		tmp = cur;
		cur = new_data > cur->data ? cur->right : cur->left;
	}
	if(new_data >= tmp->data){
		tmp->right = new_node;
		tmp->right->parent = tmp;
	} else {
		tmp->left = new_node;
		tmp->left->parent = tmp;
	}
}

template <class T>
TWnode<T> * WeightedBst<T>::Search(T key){
	if(!root){
		return nullptr;
	}
	TWnode<T> * cur = root_;
	while(cur && cur->data != key){
		cur = key > cur->data ? cur->right : cur->left;
	}
	return cur;
}

template <class T>
TWnode<T> * WeightedBst<T>::Min(){
	if(!root_){
		return root_;
	}
	TWnode<T> *tmp = root_;
	while(cur->left){
		cur = cur->left;
	}
	return cur;
}

template <class T>
TWnode<T> * WeightedBst<T>::SubtreeMin(TWnode<T> *node){
	if(!node){
		return nullptr;
	}
	TWnode<T> *tmp = node;
	while(node->left){
		node = node->left;
	}
	return node;
}

template <class T>
TWnode<T> * WeightedBst<T>::remove(TWnode<T> * root, T key){
	if(!root){
		return nullptr;
	}
	if(key > root->data){
		root->right = remove(root->right, key);
	} else if(key < root->data){
		root->left = remove(root->left, key);
	} else{
		if(!root->left){
			TWnode<T> *tmp = root->right;
			delete root;
			root = tmp;
		} else if(!root->right){
			TWnode<T> *tmp = root->left;
			delete root;
			root = tmp;
		} else{
			TWnode<T> *right_min = SubtreeMin(root->right);
			root->data = right_min->data;
			root->right = remove(right_min, right_min->data);
		}
	}
	return root;
}

template <class T>
void WeightedBst<T>::Remove(T key){
	if(!root_){
		return nullptr;
	}
	remove(root_, key);
}
