//
//  main.cpp
//  products_in_array
//
//  Created by alifar on 9/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "product_all_num_except_itself.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	vector<int> numbers;
	int item;
	cout << "Enter some integers: ";
	do{
		cin >> item;
		numbers.push_back(item);
	} while(cin.get() != '\n');

	cout << "Brute Force Result: ";
	vector<int> bf_result = ProductOfAllNumExceptItself(numbers);
	for(auto it: bf_result){
		cout << it << " ";
	}
	cout << endl;

	cout << "Linear Complexity Result: ";
	vector<int> lc_result = ProductOfAllNyumbersExceptItselfLinear(numbers);
	for(auto it: lc_result){
		cout << it << " ";
	}
	cout << endl;

	return 0;
}
