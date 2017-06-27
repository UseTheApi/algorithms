//
//  insertion_sort.cpp
//  algorithms
//
//  Created by alifar on 8/8/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "merge_sort.hpp"

void merge(std::vector<int> &arr, int left, int middle, int right){
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	std::vector<int> left_part(n1);
	std::vector<int> right_part(n2);

	for(i = 0; i < n1; ++i){
		left_part[i] = arr[left + i];
	}
	for(j = 0; j < n2; ++j){
		right_part[j] = arr[middle + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while(i < n1 && j < n2){
		if(left_part[i] < right_part[j]){
			arr[k] = left_part[i];
			++i;
		} else{
			arr[k] = right_part[j];
			++j;
		}
		++k;
	}

	while(i < n1){
		arr[k] = left_part[i];
		++i;
		++k;
	}

	while(j < n2){
		arr[k] = right_part[j];
		++j;
		++k;
	}
}

void merge_sort_helper(std::vector<int> &array, int left, int right){
	if(left < right){
		int middle = left + (right - left)/2;

		merge_sort_helper(array, left, middle);
		merge_sort_helper(array, middle + 1, right);

		merge(array, left, middle, right);
	}
}

void merge_sort(std::vector<int> &array){
	merge_sort_helper(array, 0, array.size()-1);
}