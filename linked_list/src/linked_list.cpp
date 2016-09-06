//
//  detect_remove_loop.cpp
//  algorithms
//
//  Created by alifar on 9/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <iostream>

template <class T>
class LinkedList{
public:
	LinkedList();
	LinkedList(T);
	T get_data();
	void set_data(T);
	void push(T);
	void append(T);
	void remove_head();
	void remove_last();
	void remove(T);
	void print_list();
private:
	T data;
	LinkedList<T> *next;
	LinkedList<T> *head;
};

template <class T>
LinkedList<T>::LinkedList(){
	next = 0;
	head = 0;
}

template <class T>
LinkedList<T>::LinkedList(T init_data){
	data = init_data;
	next = 0;
	head = 0;
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
void LinkedList<T>::push(T new_data){
	if(!head){
		head = new LinkedList<T>(new_data);
		return;
	}
	LinkedList<T> *new_node = new LinkedList<T>(new_data);
	new_node->next = head;
	head = new_node;
}

template <class T>
void LinkedList<T>::append(T new_data){
	if(!head){
		head = new LinkedList<T>(new_data);
		return;
	}
	LinkedList<T> *last = head;
	while(last->next){
		last = last->next;
	}
	LinkedList<T> *new_node = new LinkedList<T>(new_data);
	last->next = new_node;
}

template <class T>
void LinkedList<T>::remove_head(){
	if(!head){
		return;
	}
	LinkedList<T> *tmp = head;
	delete head;
	head = tmp->next;
}

template <class T>
void LinkedList<T>::remove_last(){
	if(!head){
		return;
	}
	LinkedList<T> *last = head;
	while(last->next->next){
		last = last->next;
	}
	LinkedList<T> *to_remove = last->next;
	last->next = 0;
	delete to_remove;
}

template <class T>
void LinkedList<T>::remove(T some_data){
	if(!head){
		return;
	}
	LinkedList<T> *last = head;
	while(last->next){
		if(last->next->data == some_data){
			LinkedList<T> *tmp = last->next;
			last->next = tmp->next;
			delete tmp;
			return;
		}
		last = last->next;
	}
}

template <class T>
void LinkedList<T>::print_list(){
	LinkedList<T> *cur = head;
	while(cur){
		std::cout << cur->data << " ";
		cur = cur->next;
	}
}


