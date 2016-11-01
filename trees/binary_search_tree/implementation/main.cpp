#include "binary_search_tree.hpp"
#include <iostream>

using namespace std;


int main(int argc, const char *argv[]){
	BinarySearchTree<int> tree;
	
	tree.Insert(4);
	tree.Insert(5);

	cout << tree.get_root() << endl;
}