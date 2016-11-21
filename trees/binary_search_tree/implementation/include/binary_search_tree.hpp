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
		Tnode *parent;
		Tnode(N);
		template <class TN>
		friend std::ostream & operator<< (std::ostream &os, const Tnode<TN> *node);
};

template <class T>
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(T);
	void Insert(T);
	Tnode<T> * Search(T);
	Tnode<T> * Min();
	Tnode<T> * get_root();
	Tnode<T> * SubtreeMin(Tnode<T> *);
	void Remove(T);

private:
	Tnode<T> *root_;
	Tnode<T> * remove(Tnode<T> *, T);
	
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

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root_ = nullptr;
}

template <class T>
Tnode<T> * BinarySearchTree<T>::get_root(){
	return root_;
}

template <class T>
Tnode<T> * BinarySearchTree<T>::Search(T key){
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
void BinarySearchTree<T>::Insert(T new_data){
	Tnode<T> *new_node = new Tnode<T>(new_data);
	if(!root_){
		root_ = new_node;
		return;
	}
	Tnode<T> *tmp = nullptr;
	Tnode<T> *cur = root_;
	while(cur){
		tmp = cur;
		cur = new_data >= cur->data ? cur->right : cur->left;
	}
	if(new_data >= tmp->data){
		tmp->right = new_node;
		tmp->right->parent = tmp;
	} else{
		tmp->left = new_node;
		tmp->left->parent = tmp;
	}
}

template <class T>
Tnode<T> * BinarySearchTree<T>::Min(){
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
Tnode<T> * BinarySearchTree<T>::SubtreeMin(Tnode<T> *node){
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
Tnode<T> * BinarySearchTree<T>::remove(Tnode<T> *root, T key){
	if(!root_){
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
    return root;
}

template <class T>
void BinarySearchTree<T>::Remove(T key){
	if(!root_){
		return;
	}
	remove(root_, key);
}
