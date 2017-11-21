//
//  stack_queue.hpp
//  algorithms. stack and queue implementations.
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <queue>

template <class T>
class StackFromQueue{
public:
	void Push(T);
	void Pop();
	T Top();
	bool empty();
	StackFromQueue(){};
private:
	std::queue<T> queue1;
	std::queue<T> queue2;
};

template <class T>
void StackFromQueue<T>::Push(T new_data){
	/* Expensive Push operation:
			1. enqueue item into queue2
			2. dequeue everything from queue1 to queue2
			3. swap two queues
	*/
	queue2.push(new_data);
	while(! queue1.empty()){
		queue2.push(queue1.front());
		queue1.pop();
	}
	std::queue<T> tmp = queue2;
	queue2 = queue1;
	queue1 = tmp;
}

template <class T>
void StackFromQueue<T>::Pop(){
	/*
	Now Dequeue normally
	*/
	queue1.pop();
}

template <class T>
T StackFromQueue<T>::Top(){
	return queue1.front();
}

template <class T>
bool StackFromQueue<T>::empty(){
	return queue1.empty();
}
