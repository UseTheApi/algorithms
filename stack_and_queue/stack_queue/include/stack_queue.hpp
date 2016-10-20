//
//  stack_queue.hpp
//  algorithms. stack and queue implementations.
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <queue_linked_list.hpp>
#include <iosream>

template <class T>
class StackFromQueue{
public:
	StackFromQueue();
	// StackFromQueue(T);
	void Push(T);
	void Pop();
	StackFromQueue<T> * Top();
	bool empty();
private:
	Queue<T> *queue1;
	Queue<T> *queue2;
};

template <class T>
StackFromQueue(){
	queue1 = new Queue<T>();
	queue2 = new Queue<T>();
}
