//
//  queue_stack.hpp
//  algorithms. stack and queue implementations.
//
//  Created by alifar on 10/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <stack_linked_list.hpp>

template <class T>
class QueueFromStack{
public:
	QueueFromStack();
	void Enqueue(T);
	void Dequeue();
	Stack<T> *Top();
	bool empty();
private:
	Stack<T> *stack1;
	Stack<T> *stack2;
};

template <class T>
QueueFromStack<T>::QueueFromStack(){
	stack1 = new Stack<T>();
	stack2 = new Stack<T>();
}

template <class T>
void QueueFromStack<T>::Enqueue(T new_data){
	/* Expensive Enqueue: 
	   1. popping everything from stack 1 to stack 2 until empty
	   2. pushing an item to stack1
	   3. popping from stack2 back to stack1, so item to be Dequeue is on top
	*/
	while(!stack1->empty()){
		stack2->Push(stack1->Top()->get_data());
		stack1->Pop();
	}
	stack1->Push(new_data);
	while(!stack2->empty()){
		stack1->Push(stack2->Top()->get_data());
		stack2->Pop();
	}
}

template <class T>
void QueueFromStack<T>::Dequeue(){
	/*
	 Now Pop normally
	*/
	stack1->Pop();
}

template <class T>
Stack<T> * QueueFromStack<T>::Top(){
	return stack1->Top();
}

template <class T>
bool QueueFromStack<T>::empty(){
	return stack1->empty();
}
