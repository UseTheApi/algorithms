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
	iterator begin() { return &store[0]; };
	const_iterator begin() const { return &store[0]; };
	iterator end() { return &store[size]; };
	const_iterator end() const { return &store[size-1]; };
private:
	T data;
	LinkedList<T> *next_node;
	LinkedList<T> *head;
	std::vector<T> store;
	int size;
};

template <class T>
LinkedList<T>::LinkedList(){
	next_node = 0;
	head = 0;
	size = 0;
}

template <class T>
LinkedList<T>::LinkedList(T init_data){
	data = init_data;
	next_node = 0;
	head = 0;
	size = 1;
}

template <class T>
T LinkedList<T>::get_data(){
	return data;
}

template <class T>
void LinkedList<T>::set_data(T new_data){
	data = new_data;
}

template <class T>
LinkedList<T> * LinkedList<T>::top(){
	return head;
}

template <class T>
LinkedList<T> * LinkedList<T>::next(){
	return next_node;
}

template <class T>
void LinkedList<T>::set_next(LinkedList<T> *new_node){
	next_node = new_node;
}

template <class T>
void LinkedList<T>::push(T new_data){
	++size;
	store.insert(store.begin(), new_data);
	if(!head){
		head = new LinkedList<T>(new_data);
		return;
	}
	LinkedList<T> *new_node = new LinkedList<T>(new_data);
	new_node->next_node = head;
	head = new_node;
}

template <class T>
void LinkedList<T>::append(T new_data){
	++size;
	store.push_back(new_data);
	if(!head){
		head = new LinkedList<T>(new_data);
		return;
	}
	LinkedList<T> *last = head;
	while(last->next_node){
		last = last->next_node;
	}
	LinkedList<T> *new_node = new LinkedList<T>(new_data);
	last->next_node = new_node;
}

template <class T>
void LinkedList<T>::remove_head(){
	--size;
	store.erase(store.begin());
	if(!head){
		return;
	}
	LinkedList<T> *tmp = head;
	delete head;
	head = tmp->next_node;
}

template <class T>
void LinkedList<T>::remove_last(){
	--size;
	store.pop_back();
	if(!head){
		return;
	}
	LinkedList<T> *last = head;
	while(last->next_node->next_node){
		last = last->next_node;
	}
	LinkedList<T> *to_remove = last->next_node;
	last->next_node = 0;
	delete to_remove;
}

template <class T>
void LinkedList<T>::remove(T some_data){
	--size;
	int shift = 0;
	for(auto it: store){
		if(some_data == it){
			break;
		}
		++shift;
	}
	store.erase(store.begin()+shift);
	if(!head){
		return;
	}
	LinkedList<T> *last = head;
	while(last->next_node){
		if(last->next_node->data == some_data){
			LinkedList<T> *tmp = last->next_node;
			last->next_node = tmp->next_node;
			delete tmp;
			return;
		}
		last = last->next_node;
	}
}

template <class T>
void LinkedList<T>::print_list(){
	LinkedList<T> *cur = head;
	while(cur){
		std::cout << cur->data << " ";
		cur = cur->next_node;
	}
}

template <class T>
LinkedList<T> * LinkedList<T>::get_last(){
	LinkedList<T> *last = head;
	while(last->next_node){
		last = last->next_node;
	}
	return last;
}

template <class T>
LinkedList<T> * LinkedList<T>::get_node(T given_data){
	LinkedList<T> *cur = head;
	while(cur){
		if(cur->get_data() == given_data){
			return cur;
		}
		cur = cur->next_node;
	}
	return 0;
}
