//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/14/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "merge_lists_median.hpp"

int main(int argc, const char *argv[]){
    std::cout << "==== Merged List Median ====" << std::endl;
    int size;
    std::cout << "Enter size of arrays: ";
    std::cin >> size;

	std::vector<int> arr1;
	std::vector<int> arr2;

	int item;

	std::cout << "Enter elements of the first array: ";
    for(int i = 0; i < size; ++i){
        std::cin >> item;
        arr1.push_back(item);
    }

	std::cout << "Enter elements of the second array: ";
	for(int i = 0; i < size; ++i){
        std::cin >> item;
        arr2.push_back(item);
    }

    std::cout << "Median of Merged Array: ";
	std::cout << MedianOfMergedArray(arr1, arr2, size) << std::endl;
}