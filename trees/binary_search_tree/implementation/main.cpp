#include "binary_search_tree.hpp"
#include <iostream>

using namespace std;


int main(int argc, const char *argv[]){
	BinarySearchTree<int> tree;
	
	tree.Insert(4);
	tree.Insert(2);
	tree.Insert(3);
	tree.Insert(0);
	tree.Insert(1);
	tree.Insert(8);
	tree.Insert(6);
	tree.Insert(9);
	tree.Insert(7);


	// cout << tree.get_root()->data << endl;
	// cout << tree.Search(3)->data << endl;
	// cout << tree.Min()->data << endl;
	InOrder(tree.get_root());
	cout << endl;
	tree.Remove(6);
	InOrder(tree.get_root());
	cout << endl;

}