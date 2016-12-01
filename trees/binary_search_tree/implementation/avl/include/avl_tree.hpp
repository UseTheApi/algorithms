//
//  avl.hpp
//  algorithms. BST implementation with balancing.
//
//  Created by alifar on 12/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "t_node.hpp"
#include <algorithm>

template <class T>
class AVLTree{
public:
	AVLTree();
	AVLTree(T);
	void Insert(T);
	Tnode<T> * Search(T);
	Tnode<T> * Min();
	Tnode<T> * get_root();
	Tnode<T> * SubtreeMin(Tnode<T> *);
	void Remove(T);
private:
	Tnode<T> *root_;
	Tnode<T> * remove(Tnode<T> *, T);
	Tnode<T> * insert(Tnode<T> *, T);
	Tnode<T> * rotate_left(Tnode<T> *);
	Tnode<T> * rotate_right(Tnode<T> *);
	int height(Tnode<T> *);
	int bfactor(Tnode<T> *);
	void update_height(Tnode<T> *);
}

template <class T>
AVLTree<T>::AVLTree(){
	root_ = nullptr;
}

template <class T>
AVLTree<T>::AVLTree(T init_key){
	root_ = new Tnode(init_key);
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
	return max(lheight, rheight) + 1;
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
	if(!node->right){
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
		cur = cur->data > key ? cur->right : cur->left;
	}
	return cur;
}

template <class T>
Tnode<T> * AVLTree<T>::insert(Tnode<T> *root, T key){
	if(!root){
		return new Tnode(key);
	}
	if(key > root->right){
		root->right = insert(root->right, key);
	} else{
		root->left = insert(root->left, key);
	}
	balance(root);
}

template <class T>
void AVLTree<T>::Insert(T key){
	root_ = insert(root_, key);
}
