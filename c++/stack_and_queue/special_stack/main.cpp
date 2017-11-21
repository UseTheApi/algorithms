//
//  main.cpp
//  algorithms
//
//  Created by alifar on 7/29/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "special_stack.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]){

	cout << "Special Stack with get_min() method" << endl;

	StackWithMin stack;

	int item;
	cout << "Push several items to a stack: ";
	do{
		cin >> item;
		stack.Push(item);
		cout << "Current min: " << stack.get_min() << endl;
	} while(cin.get() != '\n');

	cout << "Popping items until empty" << endl;
	while(!stack.empty()){
		cout << "Top of Stack: " << stack.Top() << endl;
		stack.Pop();
	}
	cout << "Done" << endl;

	return 0;
}
