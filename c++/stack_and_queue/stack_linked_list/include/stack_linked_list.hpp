//
//  stack_linked_list.hpp
//  algorithms. stack and queue implementations.
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <vector>

template <class T>
class Stack{
public:
	// Functionality
	void Push(T); // adds new item to stack
	void Pop(); // removes an item from stack
	bool empty();
	Stack<T> * Top(); // returns top of stack (next to be removed item)
	T get_data();
	void set_data(T);
	Stack * get_next();
	void set_next(Stack *);
	// Infrastructure
	template <class S>
	friend std::ostream & operator<<(std::ostream &os, const Stack<S> *node);
	Stack(){};
	Stack(T);
	~Stack();
private:
	T data_ = 0;
	Stack *next_ = nullptr;
	Stack *head_ = nullptr;
	size_t size_ = 0;
};

template <class T>
Stack<T>::Stack(T init_data){
	data_ = init_data;
	size_ = 1;
}

template <class T>
Stack<T>::~Stack(){
	if(!head_){
		return;
	}
	Stack<T> *next;
	while(head_){
		next = head_->next_;
		delete head_;
		head_ = next;
	}
}

template <class T>
void Stack<T>::Push(T new_data){
	++size_;
	if(!head_){
		head_ = new Stack<T>(new_data);
		return;
	}
	Stack<T> *new_node = new Stack<T>(new_data);
	new_node->next_ = head_;
	head_ = new_node;
}

template <class T>
void Stack<T>::Pop(){
	if(!head_){
		return;
	}
	--size_;
	Stack<T> *tmp = head_;
	delete head_;
	head_ = tmp->next_;
}

template <class T>
bool Stack<T>::empty(){
	return !head_;
}

template <class T>
Stack<T> * Stack<T>::Top(){
	return head_;
}

template <class T>
T Stack<T>::get_data(){
	return data_;
}

template <class T>
void Stack<T>::set_data(T new_data){
	data_ = new_data;
}

template <class T>
Stack<T> * Stack<T>::get_next(){
	return next_;
}

template <class T>
void Stack<T>::set_next(Stack<T> *new_next){
	next_ = new_next;
}

template <class S>
std::ostream & operator<<(std::ostream &os, const Stack<S> *node){
	os << node->data_;
	return os;
}
