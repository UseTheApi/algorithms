//
//  main.cpp
//  algorithms. weighted BST application.
//
//  Created by alifar on 02/20/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "max_path_wbst.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "===== Max Path in Weight BST =====" << endl;
	WeightedBst<int> *tree = new WeightedBst<int>();
	int number_of_items;
	cout << "---> Enter number of items to insert into a tree: ";
	cin >> number_of_items;
	int item, weight;
	for(int i = 0; i < number_of_items; ++i){
		cout << "---> Enter: ";
		cin >> item;
		cin >> weight;
		tree->Insert(item, weight);
	}
	cout << "---> Calculated max Path: ";
	cout << MaxPathWbst<>(tree->get_root()) << endl;

	return 0;
}
