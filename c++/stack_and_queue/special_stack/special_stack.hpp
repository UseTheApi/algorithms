//
//  special_stack.hpp
//  algorithms
//
//  Created by alifar on 7/29/16.
//  Copyright © 2016 alifar. All rights reserved.
//

class SimpleStack{
public:
	void push(int);
	void pop();
	SimpleStack * top();
	bool empty();
	SimpleStack();
	int get_data();
private:
	int data;
	SimpleStack *next;
	SimpleStack *head;
};

class StackWithMin{
public:
	void push(int);
	void pop();
	SimpleStack * get_min();
	SimpleStack * top();
	StackWithMin();
private:
	SimpleStack *stack;
	SimpleStack *min_collection;
};