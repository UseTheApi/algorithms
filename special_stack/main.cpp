//
//  main.cpp
//  algorithms
//
//  Created by alifar on 7/29/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "special_stack.hpp"
#include <iostream>

int main(int argc, const char * argv[]){
	std::cout << "--> creating simple stack" << std::endl;
	SimpleStack *stack = new SimpleStack();
	std::cout << "--> push 4" << std::endl;
	stack->push(4);
	std::cout << "current top: " << stack->top()->get_data() << std::endl;
	std::cout << "--> push 6" << std::endl;
	stack->push(6);
	std::cout << "--> push 7" << std::endl;
	stack->push(7);
	std::cout << "current top: " << stack->top()->get_data() << std::endl;
	while(!stack->empty()){
		std::cout << "current top: " << stack->top()->get_data() << std::endl;
		std::cout << "--> pop from simple stack" << std::endl;
		stack->pop();
	}

	std::cout << "--> creating special stack" << std::endl;
	StackWithMin *special_stack = new StackWithMin();
	std::cout << "--> push 4" << std::endl;
	special_stack->push(4);
	std::cout << "--> push 6" << std::endl;
	special_stack->push(6);
	std::cout << "--> push 3" << std::endl;
	special_stack->push(3);
	std::cout << "current top: " << special_stack->top()->get_data() << std::endl;
	std::cout << "current min: " << special_stack->get_min()->get_data() << std::endl;
	special_stack->pop();
	std::cout << "current top: " << special_stack->top()->get_data() << std::endl;
	std::cout << "current min: " << special_stack->get_min()->get_data() << std::endl;
}