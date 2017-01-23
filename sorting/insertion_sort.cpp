//
//  insertion_sort.cpp
//  algorithms
//
//  Created by alifar on 8/7/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "insertion_sort.hpp"

void insertion_sort(std::vector<int> &array){
	int i, j, key;
	for(i = 1; i < array.size(); ++i){
		key = array[i];
		j = i - 1;
		while(j >= 0 && array[j] > key){
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
	}
}
