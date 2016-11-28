//
//  main.cpp
//  algorithms. BST applications. second largest node.
//
//  Created by alifar on 11/26/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "second_largest_node.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "Binart Search Tree. Second Largest Node" << endl;
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
	Tnode<int> *result = SecondLargestNode(tree.get_root());
	cout << "For Whole Tree: " << result->data << endl;
	
	result = SecondLargestNode(n1);
	cout << "For Given Node: " <<  result->data << endl;
	return 0;
}
