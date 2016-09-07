//
//  main.cpp
//  algorithms
//
//  Created by alifar on 9/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "detect_remove_loop.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	LinkedList<int> *list = new LinkedList<int>();

	int item;
	cout << "Enter integer nodes: ";
	do{
		cin >> item;
		list->append(item);
	} while(cin.get() != '\n');

	cout << "Given list: ";
	list->print_list();
	cout << endl;

	cout << "Enter a cycle node (0 for no loop): ";
	int cycle_node_data;
	cin >> cycle_node_data;
	LinkedList<int> *cycle_node = list->get_node(cycle_node_data);

	LinkedList<int> *last = list->get_last();
	last->set_next(cycle_node);

	cout << "Detection: ";

	if(detect_loop(*list)){
		cout << "loop detected" << endl;
		detect_and_remove_loop(*list);
		cout << "loop removed: ";
		list->print_list();
	} else{
		cout << "loop not detected" << endl;
	}
}
