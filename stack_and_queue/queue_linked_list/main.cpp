//
//  main.cpp
//  algorithms. stack and queue implementations. queue_linked_list
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "queue_linked_list.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "Queue implemented with Linked List" << endl;
	Queue<int> queue;
	int item;
	cout << "Add items to Queue (press Enter when done): ";
	do{
		cin >> item;
		queue.Enqueue(item);
	} while(cin.get() != '\n');

	cout << "ForEach loop on Queue: ";
	for(auto it: queue){
		cout << it << " ";
	}
	cout << endl;

	cout << "Dequeue 1 item from Queue" << endl;
	queue.Dequeue();
	cout << "Top of Queue: " << queue.Top() << endl;

	cout << "Add some more items to Queue (press Enter when done): ";
	do{
		cin >> item;
		queue.Enqueue(item);
	} while(cin.get() != '\n');

	cout << "ForEach loop on Queue: ";
	for(auto it: queue){
		cout << it << " ";
	}
	cout << endl;

	cout << "Dequeue items until Empty: ";
	while(!queue.empty()){
		queue.Dequeue();
	} 
	cout << endl;

	return 0;
}