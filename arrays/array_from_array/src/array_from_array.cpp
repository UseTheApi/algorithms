//
//  array_from_array.cpp
//  algorithms. array_from_array
//
//  Created by alifar on 01/17/17.
//  Copyright © 2016 alifar. All rights reserved.
//

/*
 Given an int array A, return an int array B that A[i + B[i]] is the first element in A after A[i] that is greater than or equal to A[i]
*/

#include "array_from_array.hpp"
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool pair_compare(const pair<int, int> p1, const pair<int, int> p2){
	return p1.first < p2.first;
}

vector<int> SortAndCopy(const vector<int> &arr){
	vector< pair<int, int> > vector_pais;
	pair<int, int> tmp;
	for(int i = 0; i < arr.size(); ++i){
		tmp.first = arr[i];
		tmp.second = i;
		vector_pais.push_back(tmp);
	}
	sort(vector_pais.begin(), vector_pais.end(), pair_compare);

	vector<int> sorted_arr_indices;
	
	for(auto it: vector_pais){
		sorted_arr_indices.push_back(it.second);
	}
	return sorted_arr_indices;
}

vector<int> ComputeArray(const vector<int> &array1){
	vector<int> array1_sorted_indices = SortAndCopy(array1);
	vector<int> array2(array1.size()); // result array

	for(int i = 0; i < array1.size(); ++i){
		if(i == array1.size() - 1){ // for the biggest number in a given array I just leave 0 in B array
			break;
		}
		array2[array1_sorted_indices[i]] = array1_sorted_indices[i+1] - array1_sorted_indices[i];
	}
	 return array2;
}
