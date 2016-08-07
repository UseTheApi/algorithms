//
//  selection_sort.cpp
//  algorithms
//
//  Created by alifar on 8/7/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "selection_sort.hpp"

void swap(int &el1, int &el2){
	int tmp = el1;
	el1 = el2;
	el2 = tmp;
}

void selection_sort(std::vector<int> &arr){
	int min_index;
	for(int i = 0; i < arr.size(); ++i){
		min_index = i;
		for(int j = i+1; j < arr.size(); ++j){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		swap(arr[i], arr[min_index]);
	}
}