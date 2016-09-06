//
//  main.cpp
//  algorithms
//
//  Created by alifar on 9/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "detect_remove_loop.hpp"
#include <iostream>

int main(int argc, const char *argv[]){
	LinkedList<int> *list = new LinkedList<int>();
	list->push(3);
	list->push(5);
	list->append(6);
	list->append(1);
	list->print_list();
	std::cout << std::endl;
	std::cout << list->top()->get_data() << std::endl;
	std::cout << list->top()->next()->get_data() << std::endl;

	std::cout << "detection" << std::endl;

	std::cout << detect_loop(*list) << std::endl;
}
