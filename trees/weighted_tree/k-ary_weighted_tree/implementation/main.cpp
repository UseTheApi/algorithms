//
//  main.cpp
//  algorithms. weighted k-ary tree implementation.
//
//  Created by alifar on 02/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "weighted_k_tree.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "==== Weighted K-ary Tree ====" << endl;
	WeightedKTree<char> tree;
	char item, parent_char;
	int weight;
	int number_of_items = 0;
	cout << "---> Enter a number of items to be inserted into a tree: ";
	cin >> number_of_items;
	for(int i = 0; i < number_of_items; ++i){
		cout << "---> Enter item, weight and parent to insert into a tree: ";
		cin >> item;
		cin >> weight;
		cin >> parent_char;
		KWNode<char> *parent_node = tree.Search(parent_char);
		tree.Insert(item, weight, parent_node);
	}
	cout << "Traversing tree:" << endl;
	tree.Traverse();
	cout << endl;
	return 0;
}
