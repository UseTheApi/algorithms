//
//  pair_with_sum.cpp
//  algorithms. pair_with_sum
//
//  Created by alifar on 02/05/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "pair_with_sum.hpp"
#include <set>

/*
 1. Given an array of integers in ascending order. Find a pair in array that sum of elements is equal to a given number.
 2. What if array is not sorted ?
*/

bool HasPairSortedArray(const std::vector<int> &arr, int sum){
	int start = 0;
	int end = arr.size() - 1;
	while(start != end){
		int cur_pair_sum = arr[start] + arr[end];
		if(cur_pair_sum > sum){
			--end;
		} else if(cur_pair_sum < sum){
			++start;
		} else{
			return true;
		}
	}
	return false;
}

bool HasPair(const std::vector<int> &arr, int sum){
	std::set<int> complements;
	for(auto it: arr){
		if(complements.find(it) != complements.end()){
			return true;
		} else{
			complements.insert(sum - it);
		}
	}
	return false;
}
