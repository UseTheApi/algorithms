//
//  main.cpp
//  algorithms. two_arrays_pairs
//
//  Created by alifar on 12/21/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "two_arrays_pairs.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
	vector<int> arr1 = {2, 4, 7, 9};
	vector<int> arr2 = {1, 6, 8, 10};

	// cout << PairsBruteForce(arr1, arr2, 6) << endl;
	// int num;
	// cout << "Enter number of elements in arrays: ";
	// cin >> num;

	// vector<vector<int>> matrix;
	// matrix.resize(num+1);

	// for(int i = 0; i < num; ++i){
	// 	cout << i+1 << "st row: ";
	// 	matrix[i].resize(num);
	// 	for(int j = 0; j < num; ++j){
	// 		cin >> matrix[i][j];
	// 	}
	// }

	int num = PairsDP(arr1, arr2, 9);
	cout << num << endl;

}
