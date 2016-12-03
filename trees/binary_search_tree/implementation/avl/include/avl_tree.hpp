//
//  avl.hpp
//  algorithms. BST implementation with balancing.
//
//  Created by alifar on 12/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "t_node.hpp"
#include <algorithm>
#include <iostream>

template <class T>
class AVLTree{
public:
	AVLTree();
	AVLTree(T);
	void Insert(T);
	Tnode<T> * Search(T);
	void Remove(T);
	Tnode<T> * Min();
	Tnode<T> * get_root();
	Tnode<T> * SubtreeMin(Tnode<T> *);
private:
	Tnode<T> *root_;
	Tnode<T> * remove(Tnode<T> *, T);
	Tnode<T> * insert(Tnode<T> *, T);
	Tnode<T> * rotate_left(Tnode<T> *);
	Tnode<T> * rotate_right(Tnode<T> *);
	int height(Tnode<T> *);
	int bfactor(Tnode<T> *);
	void update_height(Tnode<T> *);
	Tnode<T> * balance(Tnode<T> *);
};

template <class T>
AVLTree<T>::AVLTree(){
	root_ = nullptr;
}

template <class T>
AVLTree<T>::AVLTree(T init_key){
	root_ = new Tnode<T>(init_key);
}

template <class T>
Tnode<T> * AVLTree<T>::get_root(){
	return root_;
}

template <class T>
int AVLTree<T>::height(Tnode<T> *node){
	return node ? node->height : 0;
}

template <class T>
int AVLTree<T>::bfactor(Tnode<T> *node){
	if(!node){
		return 0;
	}
	return height(node->left) - height(node->right);
}

template <class T>
void AVLTree<T>::update_height(Tnode<T> *node){
	int lheight = height(node->left);
	int rheight = height(node->right);
	node->height = std::max(lheight, rheight) + 1;
}

template <class T>
Tnode<T> * AVLTree<T>::rotate_left(Tnode<T> *node){
	if(!node){
		return nullptr;
	}
	if(!node->right){
		return node;
	}
	Tnode<T> *new_root = node->right;
	Tnode<T> *node_to_move = new_root->left;
	new_root->left = node;
	node->right = node_to_move;
	update_height(new_root);
	update_height(node);
	return new_root;
}

template <class T>
Tnode<T> * AVLTree<T>::rotate_right(Tnode<T> *node){
	if(!node){
		return nullptr;
	}
	if(!node->left){
		return node;
	}
	Tnode<T> *new_root = node->left;
	Tnode<T> *node_to_move = new_root->right;
	new_root->right = node;
	node->left = node_to_move;
	update_height(new_root);
	update_height(node);
	return new_root;
}

template <class T>
Tnode<T> * AVLTree<T>::balance(Tnode<T> *node){
	if(!node){
		return nullptr;
	}
	update_height(node);
	if(bfactor(node) < -1){
		if(bfactor(node->right) > 0){
			node->right = rotate_right(node->right);
		}
		return rotate_left(node);
	}
	if(bfactor(node) > 1){
		if(bfactor(node->left) < 0){
			node->left = rotate_left(node->left);
		}
		return rotate_right(node);
	}
	return node;
}

template <class T>
Tnode<T> * AVLTree<T>::Search(T key){
	if(!root_){
		return nullptr;
	}
	Tnode<T> *cur = root_;
	while(cur && cur->data != key){
		cur = key > cur->data ? cur->right : cur->left;
	}
	return cur;
}

template <class T>
Tnode<T> * AVLTree<T>::Min(){
	if(!root_){
		return nullptr;
	}
	Tnode<T> *cur = root_;
	while(cur->left){
		cur = cur->left;
	}
	return cur;
}

template <class T>
Tnode<T> *AVLTree<T>::SubtreeMin(Tnode<T> *node){
	if(!node){
		return nullptr;
	}
	Tnode<T> *cur = node;
	while(cur->left){
		cur = cur->left;
	}
	return cur;
}

template <class T>
Tnode<T> * AVLTree<T>::insert(Tnode<T> *root, T key){
	if(!root){
		return new Tnode<T>(key);
	}
	if(key > root->data){
		root->right = insert(root->right, key);
	} else{
		root->left = insert(root->left, key);
	}
	return balance(root);
}

template <class T>
void AVLTree<T>::Insert(T key){
	root_ = insert(root_, key);
}

template <class T>
Tnode<T> * AVLTree<T>::remove(Tnode<T> *root, T key){
	if(!root){
		return nullptr;
	}
	if(key > root->data){
		root->right = remove(root->right, key);
	} else if(key < root->data){
		root->left = remove(root->left, key);
	} else{
		if(!root->left){
			Tnode<T> *tmp = root->right;
			delete root;
			root = tmp;
		} else if(!root->right){
			Tnode<T> *tmp = root->left;
			delete root;
			root = tmp;
		} else{
			Tnode<T> *right_min = SubtreeMin(root->right);
			root->data = right_min->data;
			root->right = remove(right_min, right_min->data);
		}
	}
	return balance(root);
}

template <class T>
void AVLTree<T>::Remove(T key){
	if(!root_){
		return;
	}
	root_ = remove(root_, key);
	root_ = balance(root_);
}
