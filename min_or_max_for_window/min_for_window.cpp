//
//  min_for_window.hpp
//  algorithms
//
//  Created by alifar on 8/23/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "min_for_window.hpp"
#include <algorithm>

/*
 Given an array [1,-2,5,6,9,8,0,2]. Calculate all minimums for every window of a given size.

 Section; DP.
 The approach is to calculate mins from left to right and from right to left without shifting a window.
 LR: |1,-2,-2|6,6,6|0,0|
 RL: |-2,-2,5|6,8,8|0,2|

 Then we can calculate result[i] = min(RL[i], LR[i+w-1])

*/

void print_vector(const std::vector<int> &arr){
	for(auto it: arr){
		std::cout << it << " ";
	}
	std::cout << std::endl;
}

std::vector<int> min_for_window(std::vector<int> arr, int w){
	int size = arr.size();
	int n_windows = size - w+1;
	std::vector<int> LR(size);
	std::vector<int> RL(size);
	std::vector<int> res(n_windows);

	for(int i = 0; i < size; ++i){ // filling out LR
		if(!(i % w)){
			LR[i] = arr[i];
		} else{
			LR[i] = std::min(LR[i-1], arr[i]);
		}
	}

	std::cout << "Printing Left-Right array: " << std::endl;
	print_vector(LR);

	for(int i = size-1; i >= 0; --i){ // filling out RL
		if(i == size-1 || i % w == w-1){
			RL[i] = arr[i];
		} else{
			RL[i] = std::min(RL[i+1], arr[i]);
		}
	}

	std::cout << "Printing Right-Left array: " << std::endl;
	print_vector(RL);

	for(int i = 0; i < n_windows; ++i){ // filling out result array
		res[i] = std::min(RL[i], LR[i+w-1]);
	}

	return res;
}
