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
	Tnode<T> * Min();
	Tnode<T> * get_root();
	Tnode<T> * SubtreeMin(Tnode<T> *);
	void Remove(T);

	//Tnode(): data(0), left(nullptr), right(nullptr){};
	// Tnode(T init_data){
	// 	data = init_data;
	// 	left = nullptr;
	// 	right = nullptr;
	// }; 
	

private:
	Tnode<T> *root_;
	Tnode<T> * remove(Tnode<T> *, T);
	
};

template <class N>
Tnode<N>::Tnode(N init_data){
	data = init_data;
	left = nullptr;
	right = nullptr;
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
		cur = key > cur->data ? cur=cur->right : cur=cur->left;
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
		cur = new_data >= root_->data ? cur->right : cur->left;
	}
	if(new_data >= tmp->data){
		tmp->right = new_node;
	} else{
		tmp->left = new_node;
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

template <class I>
void InOrder(Tnode <I> *root){
	if(root){
		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}
}

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
