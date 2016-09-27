//
//  main.cpp
//  algorithms
//
//  Created by alifar on 9/26/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include "pascals_triangle.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	int k;

	cout << "Enter a row number of Pascal's Triangle: ";
	cin >> k;
	cout << k <<  "'s row of Pascal's Triangle: ";
	vector<int> row = rowInPascalsTriangle(k);
	for(auto it: row){
		cout << it << " ";
	}
	cout << endl;
}