//
//  main.cpp
//  algorithms. stack and queue implementations. stack_linked_list
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "stack_linked_list.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "Stack Implemented with Linked List" << endl;

	Stack<int> stack;
	
	int item;
	cout << "Add items to Stack (press Enter to proceed): ";
	do{
		cin >> item;
		stack.Push(item);
	} while(cin.get() != '\n');

	cout << "ForEach loop on Stack: ";
	for(auto it: stack){
		cout << it << " ";
	}

	cout << "Popping 1 item from Stack" << endl;
	stack.Pop();
	cout << "Top of Stack: " << stack.Top() << endl;

	cout << "Add some more items to Stack (press Enter when done): ";
	do{
		cin >> item;
		stack.Push(item);
	} while(cin.get() != '\n');

	cout << "ForEach loop on Stack: ";
	for(auto it: stack){
		cout << it << " ";
	}
	cout << endl;

	cout << "Popping items until Empty: ";
	while(!stack.empty()){
		stack.Pop();
	} 
	cout << endl;

	return 0;
}