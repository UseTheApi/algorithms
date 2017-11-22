//
//  main.cpp
//  algorithms. Linked List. Implementation
//
//  Created by alifar on 11/22/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "linked_list.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	cout << "== Single Linked List implementation ==" << endl;
	LinkedList<int> list;
	int num_of_push = 4;
	int item;
	cout << "Push 4 items into the list: ";
	while(num_of_push){
		cin >> item;
		list.push(item);
		--num_of_push;
	}
	cout << "List: " << list << endl;
	cout << "Getting top: ";
	cout << list.top()->value << endl;
	cout << "Getting top->next: ";
	cout << list.top()->next()->value << endl;

	cout << "Remove head\n";
	list.remove_head();
	cout << "List: " << list << endl;

	cout << "Remove last\n";
	list.remove_last();
	cout << "List: " << list << endl;

	cout << "Append 2 items: ";
	num_of_push = 2;
	while(num_of_push){
		cin >> item;
		list.append(item);
		--num_of_push;
	}
	cout << "List: " << list << endl;
	int to_remove;
	cout << "Enter a node to remove: ";
	cin >> to_remove;
	list.remove(to_remove);
	cout << "List: " << list << endl;
	cout << "End of test" << endl;
	cout << "Iteration using ForEach loop" << endl;
	for(auto it: list){
		cout << it << " ";
	}
	cout << endl;

	return 0;
}
