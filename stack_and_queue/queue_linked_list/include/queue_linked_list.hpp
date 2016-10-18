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

	template <class Q>
	friend std::ostream & operator<<(std::ostream &os, const Queue<T> *node);
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
	size_t size_;
	std::vector<T> store_;
};

template <class T>
Queue<T>::Queue(){
	next_ = 0;
	head_ = 0;
	size_ = 0;
}

template <class T>
Queue<T>::Queue(T init_data){
	data_ = init_data;
	next_ = 0;
	head_ = 0;
	size_ = 1;
}



