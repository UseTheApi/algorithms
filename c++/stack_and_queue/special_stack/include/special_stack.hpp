//
//  special_stack.hpp
//  algorithms
//
//  Created by alifar on 7/29/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <stack>

class StackWithMin{
public:
	void Push(int);
	void Pop();
	int get_min();
	int Top();
	bool empty();
	StackWithMin(){};
private:
	std::stack<int> stack;
	std::stack<int> min_collection;
};

void StackWithMin::Push(int data){
	// 4, 5, 3: push->[3, 5, 4]; get_min = 4
	if(stack.empty() || data < min_collection.top()){
		min_collection.push(data);
	} else{
		min_collection.push(min_collection.top());
	}
	stack.push(data);
}

void StackWithMin::Pop(){
	if(stack.empty()){
		return;
	}
	if(stack.top() == min_collection.top()){
		min_collection.pop();
	}
	stack.pop();
}

int StackWithMin::Top(){
	return stack.top();
}

bool StackWithMin::empty(){
	return stack.empty();
}

int StackWithMin::get_min(){
	return min_collection.empty() ? 0 : min_collection.top();
}
