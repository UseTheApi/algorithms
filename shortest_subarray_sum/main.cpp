//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "shortest_subarray_sum.hpp"

/*
 Smallest subarray with sum greater than a given value:
 arr = [1, 4, 45, 6, 0, 19, 39] num = 51 output-> length of shortest subarray with sum of elements > num.
*/

 using namespace std;

 int main(int argc, const char *argv[]){
 	vector<int> array = {1, 4, 45, 6, 0, 19, 39};
 	int num = 51;
 	cout << "Case 1: " << endl;
 	cout << "--> array: ";
 	for(auto it: array){
 		cout << it << " ";
 	}
 	cout << endl;
 	cout << "--> number given: " << num << endl;
 	cout << "--> Result: " << shortest_len_with_greater_sum(array, num) << endl;

 	array = {1, 2, 50, 3, 5, 100};
 	num = 57;
 	cout << "Case 2: " << endl;
 	cout << "--> array: ";
 	for(auto it: array){
 		cout << it << " ";
 	}
 	cout << endl;
 	cout << "--> number given: " << num << endl;
 	cout << "--> Result: " << shortest_len_with_greater_sum(array, num) << endl;
 }