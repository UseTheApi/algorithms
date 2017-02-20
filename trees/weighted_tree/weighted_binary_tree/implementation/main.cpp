//
//  main.cpp
//  algorithms. weighted BST implementation.
//
//  Created by alifar on 02/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "weighted_binary_tree.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	cout << "===== Weighted Binary Search Tree =====" << endl;

	WeightedBst<int> *tree = new WeightedBst<int>();
	tree->Insert(3, 5);
	tree->Insert(2, 3);
	tree->Insert(5, 1);
	tree->Insert(4, 4);
	tree->Insert(1, 2);

	cout << tree->get_root()->weight << endl;
	cout << tree->Min()->weight << endl;

	return 0;
}
