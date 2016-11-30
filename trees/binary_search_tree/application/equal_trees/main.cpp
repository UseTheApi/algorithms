//
//  main.cpp
//  algorithms. BST application. equal nodes.
//
//  Created by alifar on 11/30/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "equal_trees.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "Binary Search Tree. Equal Trees" << endl;
	BinarySearchTree<int> tree1;
	cout << "Insert integers into Tree1: " << endl;
	int item;
	do{
		cin >> item;
		tree1.Insert(item);
	} while(cin.get() != '\n');

	BinarySearchTree<int> tree2;
	cout << "Insert integers into Tree2: " << endl;
	do{
		cin >> item;
		tree2.Insert(item);
	} while(cin.get() != '\n');
	bool res = Equal(tree1.get_root(), tree2.get_root());
	cout << "Equality of Trees: " <<  res << endl;
	return 0;
}