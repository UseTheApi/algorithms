//
//  main.cpp
//  algorithms. max burglary
//
//  Created by alifar on 12/19/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "max_burglary.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]){
	cout << "Max Benefit in Robbery" << endl;
	vector<int> arr;
	int item;

	cout << "Enter elements of array: ";
	do{
		cin >> item;
		arr.push_back(item);
	} while(cin.get() != '\n');

	int res = MaxProfit(arr);
	cout << "Max profit is: " << res << endl;
}
