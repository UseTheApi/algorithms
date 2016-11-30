//
//  main.cpp
//  algorithms. BST applications. not related nodes.
//
//  Created by alifar on 11/30/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "not_related_nodes.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "Binart Search Tree. Not Related Nodes" << endl;
	BinarySearchTree<int> tree;
	cout << "Insert integers into Tree: " << endl;
	int item;
	do{
		cin >> item;
		tree.Insert(item);
	} while(cin.get() != '\n');
	vector<Tnode<int> *> result = NotRelatedNodes(tree.get_root());
	for(auto it: result){
		cout << it << " ";
	}
	return 0;
}