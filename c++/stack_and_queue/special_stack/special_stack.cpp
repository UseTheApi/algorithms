//
//  special_stack.cpp
//  algorithms
//
//  Created by alifar on 7/29/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "special_stack.hpp"

// push: 4, 5, 6 -> [6, 5, 4]

SimpleStack::SimpleStack(){
	head = 0;
	next = 0;
}

void SimpleStack::push(int data){
	if(!head){
		head = new SimpleStack();
		head->data = data;
		head->next = 0;
		return;
	}
	SimpleStack *node = new SimpleStack();
	node->data = data;
	node->next = head;
	head = node;
}

void SimpleStack::pop(){
	if(!head){
		return;
	}
	SimpleStack *tmp = head;
	delete head;
	head = tmp->next;
}

SimpleStack * SimpleStack::top(){
	return head ? head : 0;
}

bool SimpleStack::empty(){
	return !head;
}

int SimpleStack::get_data(){
	return data;
}

StackWithMin::StackWithMin(){
	stack = new SimpleStack();
	min_collection = new SimpleStack();
}

void StackWithMin::push(int data){
	// 4, 5, 3: push->[3, 5, 4]; get_min = 4
	if(stack->empty() || data < min_collection->top()->get_data()){
		min_collection->push(data);
	} else{
		min_collection->push(min_collection->top()->get_data());
	}
	stack->push(data);
}

void StackWithMin::pop(){
	if(stack->empty()){
		return;
	}
	if(stack->top()->get_data() == min_collection->top()->get_data()){
		min_collection->pop();
	}
	stack->pop();
}

SimpleStack * StackWithMin::top(){
	return stack->top();
}

SimpleStack * StackWithMin::get_min(){
	return min_collection->empty() ? 0 : min_collection->top();
}