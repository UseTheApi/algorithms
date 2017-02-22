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
	WeightedKTree<char> tree;
	int number_of_items;
	cout << "---> Enter a number of items to insert into a tree: ";
	cin >> number_of_items;
	char item, parent_item;
	int weight;
	for(int i = 0; i < number_of_items; ++i){
		cout << "---> Enter item [char, weight and parent_char]: ";
		cin >> item;
		cin >> weight;
		cin >> parent_item;
		KTNode<char> * parent = tree.Search(parent_item);
		if(!parent && i > 0){
			cout << "nonono" << endl;
			continue;
		}
		tree.Insert(item, weight, parent);
		cout << "Current size: " << tree.k_tree_size << endl;
	}
	// cout << "---> Traversing Result Tree: ";
	// tree.Traverse();
	// cout << endl;
	// tree.Insert('a', 1, nullptr);
	// KTNode<char> *p = tree.Search('a');
	// tree.Insert('b', 2, p);
	// tree.Traverse();
	return 0;
}
