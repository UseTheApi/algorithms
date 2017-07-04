//
//  stack_queue.hpp
//  algorithms. stack and queue implementations.
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <queue_linked_list.hpp>

template <class T>
class StackFromQueue{
public:
	StackFromQueue();
	// StackFromQueue(T);
	void Push(T);
	void Pop();
	Queue<T> * Top();
	bool empty();
private:
	Queue<T> *queue1;
	Queue<T> *queue2;
};

template <class T>
StackFromQueue<T>::StackFromQueue(){
	queue1 = new Queue<T>();
	queue2 = new Queue<T>();
}

template <class T>
void StackFromQueue<T>::Push(T new_data){
	queue2->Enqueue(new_data);
	while(queue1->get_rear()){
		queue2->Enqueue(queue1->Top()->get_data());
		queue1->Dequeue();
	}
	Queue<T> *tmp = queue2;
	queue2 = queue1;
	queue1 = tmp;
}

template <class T>
void StackFromQueue<T>::Pop(){
	queue1->Dequeue();
}

template <class T>
Queue<T> * StackFromQueue<T>::Top(){
	return queue1->Top();
}

template <class T>
bool StackFromQueue<T>::empty(){
	return queue1->empty();
}
