//
//  main.cpp
//  algorithms. stack and queue implementations. queue implementation from a stack
//
//  Created by alifar on 10/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "queue_stack.hpp"
#include <iostream>

using namespace std;

/*
 Implementing Queue from a Stack can be done using two ways: by making Dequeue() costly or Enqueue() costly
 in the case of making Dequeue() costly there is a complication of a need to perform same actions for Top(),
 so it is preferred in this implementation to use approach of an expensive Enqueue()

 Costly Dequeue() method is implemented in a private section of class QueueFromStack
*/

int main(int argc, const char *argv[]){
	cout << "Queue Implemented with Stack" << endl;

	QueueFromStack<int> *queue = new QueueFromStack<int>();

	cout << "Enqueue several items to a queue: ";
	int item;
	do{
		cin >> item;
		queue->Enqueue(item);
	} while(cin.get() != '\n');

	cout << "Dequeueing items until empty" << endl;
	while(!queue->empty()){
		cout << "Top of Stack: " << queue->Top() << endl;
		queue->Dequeue();
	}
	cout << "Done" << endl;

	return 0;
}
