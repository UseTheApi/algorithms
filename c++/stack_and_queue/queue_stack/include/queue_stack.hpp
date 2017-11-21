//
//  queue_stack.hpp
//  algorithms. stack and queue implementations.
//
//  Created by alifar on 11/21/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <stack>

template <class T>
class QueueFromStack{
public:
	QueueFromStack(){};
	void Enqueue(T);
	void Dequeue();
	T Top();
	bool empty();
private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template <class T>
void QueueFromStack<T>::Enqueue(T new_data){
	/* Expensive Enqueue:
	   1. popping everything from stack 1 to stack 2 until empty
	   2. pushing an item to stack1
	   3. popping from stack2 back to stack1, so item to be Dequeue is on top
	*/
	while(!stack1.empty()){
		stack2.push(stack1.top());
		stack1.pop();
	}
	stack1.push(new_data);
	while(!stack2.empty()){
		stack1.push(stack2.top());
		stack2.pop();
	}
}

template <class T>
void QueueFromStack<T>::Dequeue(){
	/*
	 Now Pop normally
	*/
	stack1.pop();
}

template <class T>
T QueueFromStack<T>::Top(){
	return stack1.top();
}

template <class T>
bool QueueFromStack<T>::empty(){
	return stack1.empty();
}
