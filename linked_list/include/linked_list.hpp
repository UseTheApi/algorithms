//
//  detect_remove_loop.cpp
//  algorithms
//
//  Created by alifar on 9/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <vector>
#include <iostream>

template <class T>
class LinkedList{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	LinkedList();
	LinkedList(T);
	T get_data();
	void set_data(T);
	LinkedList<T> * top();
	LinkedList<T> * next();
	void set_next(LinkedList<T> *);
	void push(T);
	void append(T);
	void remove_head();
	void remove_last();
	void remove(T);
	void print_list();
	LinkedList<T> * get_last();
	LinkedList<T> * get_node(T);
	iterator begin() { return &store_[0]; };
	const_iterator begin() const { return &store_[0]; };
	iterator end() { return &store_[size_]; };
	const_iterator end() const { return &store_[size_]; };
private:
	T data_;
	LinkedList<T> *next_node_;
	LinkedList<T> *head_;
	std::vector<T> store_;
	int size_;
};

template <class T>
LinkedList<T>::LinkedList(){
	next_node_ = 0;
	head_ = 0;
	size_ = 0;
}

template <class T>
LinkedList<T>::LinkedList(T init_data){
	data_ = init_data;
	next_node_ = 0;
	head_ = 0;
	size_ = 1;
}

template <class T>
T LinkedList<T>::get_data(){
	return data_;
}

template <class T>
void LinkedList<T>::set_data(T new_data){
	data_ = new_data;
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
	++size_;
	store_.insert(store_.begin(), new_data);
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
	++size_;
	store_.push_back(new_data);
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
	--size_;
	store_.erase(store_.begin());
	LinkedList<T> *tmp = head_;
	delete head_;
	head_ = tmp->next_node_;
}

template <class T>
void LinkedList<T>::remove_last(){
	--size_;
	store_.pop_back();
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
}

template <class T>
void LinkedList<T>::remove(T some_data){
	--size_;
	int shift = 0;
	for(auto it: store_){
		if(some_data == it){
			break;
		}
		++shift;
	}
	store_.erase(store_.begin()+shift);
	if(!head_){
		return;
	}
	LinkedList<T> *last = head_;
	while(last->next_node_){
		if(last->next_node_->data_ == some_data){
			LinkedList<T> *tmp = last->next_node_;
			last->next_node_ = tmp->next_node_;
			delete tmp;
			return;
		}
		last = last->next_node_;
	}
}

template <class T>
void LinkedList<T>::print_list(){
	LinkedList<T> *cur = head_;
	while(cur){
		std::cout << cur->data_ << " ";
		cur = cur->next_node_;
	}
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
		if(cur->get_data() == given_data){
			return cur;
		}
		cur = cur->next_node_;
	}
	return 0;
}
