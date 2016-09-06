//
//  main.cpp
//  algorithms
//
//  Created by alifar on 9/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "linked_list.cpp"
#include <iostream>

int main(int argc, const char *argv[]){
	LinkedList<int> *list = new LinkedList<int>();
	list->push(3);
	list->push(5);
	list->print_list();
	std::cout << std::endl;
}