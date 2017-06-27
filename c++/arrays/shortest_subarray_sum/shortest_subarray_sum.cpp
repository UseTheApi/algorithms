//
//  shortest_subarray_sum.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "shortest_subarray_sum.hpp"
#include <algorithm>

/*
 Smallest subarray with sum greater than a given value:
 arr = [1, 4, 45, 6, 0, 19, 39] num = 51 output-> length of shortest subarray with sum of elements > num.
*/

using namespace std;

int shortest_len_with_greater_sum(const vector<int> &arr, int num){
	int sum = 0;
	int j = 0;
	int min_len = static_cast<int>(arr.size());
	for(int i = 0; i < arr.size(); ++i){
		sum += arr[i];
		while(sum - arr[j] > num){
			sum -= arr[j]; 
			++j; 
		}
		if(sum > num){
			min_len = min(min_len, i-j+1); 
			j = i;
			sum = arr[j];
		}
	}
	return min_len;
}