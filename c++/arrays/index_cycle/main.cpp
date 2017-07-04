//
//  main.cpp
//  algorithms. determing a cycle, index_cycle
//
//  Created by alifar on 10/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "index_cycle.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	cout << "==== Finding a cycle in Array of relative indices==== " << endl;
	vector<int> arr;
	int item;

	cout << "Enter elements of array: ";
	do{
		cin >> item;
		arr.push_back(item);
	} while(cin.get() != '\n');

	if(HasCompleteCycle(arr)){
		cout << "Array represents a Complete Cycle" << endl;
	} else{
		cout << "There is no Complete Cycle found in array" << endl;
	}
	return 0;
}