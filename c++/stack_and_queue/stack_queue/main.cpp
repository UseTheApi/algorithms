//
//  main.cpp
//  algorithms. stack and queue implementations. stack implemented from queue
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <stack_queue.hpp>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "Stack Implemented with Queue" << endl;

	StackFromQueue<int> stack;

	int item;
	cout << "Push several items to a stack: ";
	do{
		cin >> item;
		stack.Push(item);
	} while(cin.get() != '\n');

	cout << "Popping items until empty" << endl;
	while(!stack.empty()){
		cout << "Top of Stack: " << stack.Top() << endl;
		stack.Pop();
	}
	cout << "Done" << endl;

	return 0;
}
