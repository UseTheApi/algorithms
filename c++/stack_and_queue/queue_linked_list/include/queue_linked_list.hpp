//
//  queue_linked_list.hpp
//  algorithms. stack and queue implementations.
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>
#include <iostream>

template <class T>
class Queue{
public:
	Queue();
	Queue(T);
	void Enqueue(T);
	void Dequeue();
	Queue<T> * Top();
	bool empty();
	T get_data();
	void set_data(T);
	Queue<T> * get_next();
	void set_next(Queue<T> *);
	Queue<T> * get_rear();

	template <class Q>
	friend std::ostream & operator<<(std::ostream &os, const Queue<Q> *node);
	// This part to allow foreach loop for this DS
	typedef T* iterator;
	typedef const T*  const_iterator;
	iterator begin() { return &store_[0]; };
	const_iterator begin() const { return &store_[0]; };
	iterator end() { return &store_[size_]; };
	const_iterator end() const { return &store_[size_]; };
private:
	T data_;
	Queue<T> *next_;
	Queue<T> *head_;
	Queue<T> *rear_;
	size_t size_;
	std::vector<T> store_;
};

template <class T>
Queue<T>::Queue(){
	next_ = 0;
	head_ = 0;
	rear_ = 0;
	size_ = 0;
}

template <class T>
Queue<T>::Queue(T init_data){
	data_ = init_data;
	next_ = 0;
	head_ = 0;
	rear_ = 0;
	size_ = 1;
}

template <class T>
T Queue<T>::get_data(){
	return data_;
}

template <class T>
void Queue<T>::set_data(T new_data){
	data_ = new_data;
}

template <class T>
Queue<T> * Queue<T>::get_next(){
	return next_;
}

template <class T>
void Queue<T>::set_next(Queue<T> *new_next){
	next_ = new_next;
}

template <class T>
Queue<T> * Queue<T>::get_rear(){
	return rear_;
}

template <class T>
void Queue<T>::Enqueue(T new_data){
	++size_;
	store_.push_back(new_data);
	if(!head_){
		head_ = rear_ = new Queue<T>(new_data);
		return;
	}
	Queue<T> *new_node = new Queue<T>(new_data);
	rear_->next_ = new_node;
	rear_ = new_node;
}

template <class T>
void Queue<T>::Dequeue(){
	if(!head_){
		return;
	}
	--size_;
	store_.pop_back();
	Queue<T> *tmp = head_;
	delete head_;
	head_ = tmp->next_;
	if(!head_){
		rear_ = 0;
	}
}

template <class T>
Queue<T> * Queue<T>::Top(){
	return head_;
}

template <class T>
bool Queue<T>::empty(){
	return !head_;
}

template <class Q>
std::ostream & operator<<(std::ostream &os, const Queue<Q> *node){
	os << node->data_;
	return os;
}
