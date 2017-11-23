//
//  linked_list.hpp
//  algorithms. Linked List. Implementation
//
//  Created by alifar on 11/22/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <vector>
#include <iostream>
#include <limits>

template <class T>
class LinkedList{
public:
	// public fields
	T value = 0;
	size_t size = 0;
	// Functionality
	LinkedList<T> * top();
	LinkedList<T> * next();
	void push(T);
	void append(T);
	void remove_head();
	void remove_last();
	void remove(T);
	void print_list();
	LinkedList<T> * get_last();
	LinkedList<T> * get_node(T);
	void set_next(LinkedList<T> *);
	bool empty();
	// Infrastructure
	LinkedList(){};
	LinkedList(T);
	~LinkedList();
	template <class S>
	friend std::ostream & operator<<(std::ostream &os, const LinkedList<S> &node);
	// Iterator
	class iterator;
	friend class iterator;
	class iterator{
	public:
		iterator(const LinkedList* begin): it_(begin){};
		iterator& operator++(){
			it_ = it_->next_node_;
			return *this;
		}
		bool operator==(const iterator& rhs) const{
			return it_ == rhs.it_;
		}
		bool operator!=(const iterator& rhs) const{
			return !(*this == rhs);
		}
		T operator*() const{
			return it_->value;
		}
	private:
		const LinkedList* it_;
	};

	iterator begin() const{
		return iterator(head_);
	}
	iterator end() const{
		return iterator(nullptr);
	}

private:
	LinkedList<T> *next_node_ = nullptr;
	LinkedList<T> *head_ = nullptr;
};

template <class T>
LinkedList<T>::LinkedList(T init_data){
	value = init_data;
	size = 1;
}

template <class T>
LinkedList<T>::~LinkedList(){
	LinkedList<T> *tmp;
	while(head_){
		tmp = head_;
		head_ = head_->next_node_;
		delete tmp;
	}
	size = 0;
}

template <class T>
bool LinkedList<T>::empty(){
	return !head_;
}

template <class T>
LinkedList<T> * LinkedList<T>::top(){
	return head_;
}

template <class T>
LinkedList<T> * LinkedList<T>::next(){
	return next_node_;
}

template <class T>
void LinkedList<T>::set_next(LinkedList<T> *new_node){
	next_node_ = new_node;
}

template <class T>
void LinkedList<T>::push(T new_data){
	++size;
	if(!head_){
		head_ = new LinkedList<T>(new_data);
		return;
	}
	LinkedList<T> *new_node = new LinkedList<T>(new_data);
	new_node->next_node_ = head_;
	head_ = new_node;
}

template <class T>
void LinkedList<T>::append(T new_data){
	++size;
	if(!head_){
		head_ = new LinkedList<T>(new_data);
		return;
	}
	LinkedList<T> *last = head_;
	while(last->next_node_){
		last = last->next_node_;
	}
	LinkedList<T> *new_node = new LinkedList<T>(new_data);
	last->next_node_ = new_node;
}

template <class T>
void LinkedList<T>::remove_head(){
	if(!head_){
		return;
	}
	LinkedList<T> *tmp = head_;
	delete head_;
	head_ = tmp->next_node_;
	size > 0 ? --size : size = 0;
}

template <class T>
void LinkedList<T>::remove_last(){
	if(!head_){
		return;
	}
	LinkedList<T> *last = head_;
	while(last->next_node_->next_node_){
		last = last->next_node_;
	}
	LinkedList<T> *to_remove = last->next_node_;
	last->next_node_ = 0;
	delete to_remove;
	size > 0 ? --size : size = 0;
}

template <class T>
void LinkedList<T>::remove(T some_data){
	if(!head_){
		return;
	}
	if(head_->value == some_data){
		remove_head();
		return;
	}
	LinkedList<T> *last = head_;
	while(last){
		if(last->value == some_data){
			LinkedList<T> *tmp = last;
			last = tmp->next_node_;
			delete tmp;
			return;
		}
		last = last->next_node_;
	}
	size > 0 ? --size : size = 0;
}

template <class S>
std::ostream & operator<<(std::ostream &os, const LinkedList<S> &node){
	for(auto it: node){
		os << it << " ";
	}
	return os;
}

template <class T>
LinkedList<T> * LinkedList<T>::get_last(){
	LinkedList<T> *last = head_;
	while(last->next_node_){
		last = last->next_node_;
	}
	return last;
}

template <class T>
LinkedList<T> * LinkedList<T>::get_node(T given_data){
	LinkedList<T> *cur = head_;
	while(cur){
		if(cur->value == given_data){
			return cur;
		}
		cur = cur->next_node_;
	}
	return 0;
}
