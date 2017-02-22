//
//  weighted_k_tree.hpp
//  algorithms. weighted k-ary tree implementation.
//
//  Created by alifar on 02/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <linked_list.hpp>
#include <iostream>
#include <set>

template <class N>
struct KTNode{
	N data;
	int weight;
	KTNode<N> *f_child;
	KTNode<N> *parent;
	LinkedList<KTNode<N> *> siblings;
	KTNode(N, int);
	template <class TN>
	friend std::ostream & operator<< (std::ostream &os, const KTNode<TN> *node);
	~KTNode();
};

template <class N>
KTNode<N>::KTNode(N init_data, int init_weight){
	data = init_data;
	weight = init_weight;
	f_child = nullptr;
	parent = nullptr;
	// siblings = new LinkedList<KTNode<N> *>();
}

template <class TN>
std::ostream & operator<< (std::ostream &os, const KTNode<TN> *node){
	os << node->data;
	return os;
}

template <class T>
class WeightedKTree{
public:
	WeightedKTree();
	void Insert(T, int, KTNode<T> *);
	KTNode<T> * Search(T);
	void Traverse();
	KTNode<T> * get_root();
	int k_tree_size;
private:
	KTNode<T> *root_;
};

template <class T>
WeightedKTree<T>::WeightedKTree(){
	root_ = nullptr;
	k_tree_size = 0;
}

template <class T>
KTNode<T> * WeightedKTree<T>::get_root(){
	return root_;
}

template <class T>
void WeightedKTree<T>::Insert(T new_data, int weight, KTNode<T> *parent){
	if(!root_){
		root_ = new KTNode<T>(new_data, 0);
		++k_tree_size;
		return;
	}
	if(!parent){
		std::cout << "Parent not Found for: " << new_data << std::endl;
		return;
	}
	KTNode<T> *new_node = new KTNode<T>(new_data, weight);
	new_node->parent = parent;
	++k_tree_size;
	if(!parent->f_child){
		parent->f_child = new_node;
	} else{
		parent->siblings.append(new_node);
	}
}

template <class T>
KTNode<T> * WeightedKTree<T>::Search(T key){
	if(!root_){
		return nullptr;
	}
	KTNode<T> *cur = root_;
	std::set<KTNode<T> *> visited;
	while(cur && cur->data != key && visited.size() < k_tree_size){
		if(visited.find(cur) != visited.end()){
			continue;
		}
		visited.insert(cur);
		if(cur->f_child){
			cur = cur->f_child;
		} else if(cur->siblings.top()){
			cur = cur->siblings.top()->get_data();
		} else{
			cur = cur->parent;
		}
	}
	return cur;
}

template <class T>
void WeightedKTree<T>::Traverse(){
	if(!root_){
		return;
	}
	KTNode<T> *cur = root_;
	std::set<KTNode<T> *> visited;
	while(cur && visited.size() < k_tree_size){
		std::cout << cur->data << " ";
		if(visited.find(cur) != visited.end()){
			continue;
		}
		visited.insert(cur);
		if(cur->f_child){
			cur = cur->f_child;
		} else if(cur->siblings.top()){
			cur = cur->siblings.top()->get_data();
		} else{
			cur = cur->parent;
		}
	}
}
