//
//  main.cpp
//  algorithms. pair_with_sum
//
//  Created by alifar on 02/05/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "pair_with_sum.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "==== Find Pair with Given Sum ====" << endl;
	int item;
	vector<int> array;
	cout << "Enter items into array: ";
	do{
		cin >> item;
		array.push_back(item);
	} while(cin.get() != '\n');
	cout << "Enter Sum: ";
	cin >> item;
	cout << "Looking for pait in not sorted array using Set: " << endl;
	if(HasPair(array, item)){
		cout << "++ Found the pair ++" << endl;
	} else{
		cout << "++ Pair was not found ++" << endl;
	}
	cout << "Looking for pair in sorted array: " << endl;
	sort(array.begin(), array.end());
	if(HasPairSortedArray(array, item)){
		cout << "++ Found the pair ++" << endl;
	} else{
		cout << "++ Pair was not found ++" << endl;
	}
	return 0;
}
