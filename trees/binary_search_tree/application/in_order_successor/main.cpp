//
//  main.cpp
//  algorithms. BST application. In Order Successor
//
//  Created by alifar on 11/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "in_order_successor.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "Binary Search Tree. Lowest Common Ancestor" << endl;
	BinarySearchTree<int> tree;
	cout << "Insert integers into Tree: " << endl;
	int item;
	do{
		cin >> item;
		tree.Insert(item);
	} while(cin.get() != '\n');
	cout << "Enter an item for the task: " << endl;
	cin >> item;
	Tnode<int> *n1 = tree.Search(item);
	Tnode<int> *result = InOrderSuccessorRoot(tree.get_root(), n1);
	cout << "From Root: " << result->data << endl;
	
	result = InOrderSuccessorParent(n1);
	cout << "Using Parent Pointer: " <<  result->data << endl;
	return 0;
}

