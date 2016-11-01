//
//  main.cpp
//  algorithms. BST traversals.
//
//  Created by alifar on 11/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "traversals.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	BinarySearchTree<int> tree;
	tree.Insert(4);
	tree.Insert(7);
	tree.Insert(9);
	tree.Insert(6);
	tree.Insert(2);
	tree.Insert(1);

	InOrder(&tree);
	cout << endl;
	PreOrder(&tree);
	cout << endl;
	PostOrder(&tree);
	cout << endl;
	return 0;
}
