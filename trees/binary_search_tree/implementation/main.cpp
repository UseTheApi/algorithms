#include "binary_search_tree.hpp"
#include <iostream>

using namespace std;


int main(int argc, const char *argv[]){
	cout << "Binary Search Tree Representation" << endl;
	BinarySearchTree<int> tree;
	cout << "Insert integers into Tree: " << endl;
	int item;
	do{
		cin >> item;
		tree.Insert(item);
	} while(cin.get() != '\n');
	cout << "Current Root: " << tree.get_root()->data << endl;
	cout << "Removing Root..." << endl;
	tree.Remove(tree.get_root()->data);
	cout << "Current Root: " << tree.get_root()->data << endl;
	cout << "Enter an item to be found: " << endl;
	cin >> item;
	if(tree.Search(item)){
		cout << "Item Found" << endl;
	} else{
		cout << "Item Not Present" << endl;
	}
	return 0;
}