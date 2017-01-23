//
//  main.cpp
//  algorithms. array_from_array
//
//  Created by alifar on 01/17/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "array_from_array.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	cout << "==== Building Array from a Given Array ====" << endl;
	vector<int> a;
	int item;
	cout << "Enter items to array: ";
	do{
		cin >> item;
		a.push_back(item);
	} while(cin.get() != '\n');

	vector<int> b = ComputeArray(a);
	cout << "Calculated array: ";
	for(auto it: b){
		cout << it << " ";
	}
	cout << endl;
}