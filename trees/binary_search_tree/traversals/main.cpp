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
	cout << "BST Traversals: " << endl;
	BinarySearchTree<int> tree;
	tree.Insert(5);
	tree.Insert(7);
	tree.Insert(9);
	tree.Insert(3);
	tree.Insert(2);
	tree.Insert(1);

	cout << "In Order: ";
	InOrder(tree.get_root());
	cout << endl;
	cout << "Pre Order: ";
	PreOrder(tree.get_root());
	cout << endl;
	cout << "Post Order: ";
	PostOrder(tree.get_root());
	cout << endl;
	cout << "In Order Stack: ";
	InOrderStack(tree.get_root());
	cout << endl;
	cout << "In Order Morris: ";
	InOrderMorris(tree.get_root());
	cout << endl;
	cout << "Breadth First: ";
	BreadthFirst(tree.get_root());
	cout << endl;
	cout << "Level Order: ";
	LevelOrder(tree.get_root());
	cout << endl;
	cout << endl;

	cout << "AVL tree Traversals: " << endl;
	BinarySearchTree<int> avl;
	avl.Insert(5);
	avl.Insert(7);
	avl.Insert(9);
	avl.Insert(3);
	avl.Insert(2);
	avl.Insert(1);

	cout << "In Order: ";
	InOrder(avl.get_root());
	cout << endl;
	cout << "Pre Order: ";
	PreOrder(avl.get_root());
	cout << endl;
	cout << "Post Order: ";
	PostOrder(avl.get_root());
	cout << endl;
	cout << "In Order Stack: ";
	InOrderStack(avl.get_root());
	cout << endl;
	cout << "In Order Morris: ";
	InOrderMorris(avl.get_root());
	cout << endl;
	cout << "Breadth First: ";
	BreadthFirst(avl.get_root());
	cout << endl;
	cout << "Level Order: ";
	LevelOrder(avl.get_root());
	cout << endl;

 	return 0;
}
