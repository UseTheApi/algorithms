//
//  detect_remove_loop.cpp
//  algorithms
//
//  Created by alifar on 9/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "linked_list.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	LinkedList<int> *list = new LinkedList<int>();
	int num_of_push = 4;
	int item;
	cout << "Push 4 items into the list: ";
	while(num_of_push){
		cin >> item;
		list->push(item);
		--num_of_push;
	}
	cout << "List: ";
	list->print_list();
	cout << endl;
	cout << "Getting top: ";
	cout << list->top()->get_data() << endl;
	cout << "Getting top->next: ";
	cout << list->top()->next()->get_data() << endl;

	cout << "Remove head: ";
	list->remove_head();
	list->print_list();
	cout << endl;

	cout << "Remove last: ";
	list->remove_last();
	list->print_list();
	cout << endl;

	cout << "Append 2 items: ";
	num_of_push = 2;
	while(num_of_push){
		cin >> item;
		list->append(item);
		--num_of_push;
	}
	cout << "List: ";
	list->print_list();
	cout << endl;
	int to_remove;
	cout << "Enter a node to remove: ";
	cin >> to_remove;
	list->remove(to_remove);
	cout << "List: ";
	list->print_list();
	cout << endl;
	cout << "End of test" << endl;

	return 0;
}