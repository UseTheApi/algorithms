//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/14/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "merge_lists_median.hpp"

int main(int argc, const char *argv[]){
	std::vector<int> arr1 = {1, 3, 4, 6};
	std::vector<int> arr2 = {5, 7, 8, 9};

	int size = static_cast<int>(arr1.size());

	std::cout << MedianOfMergedArray(arr1, arr2, size) << std::endl;
}