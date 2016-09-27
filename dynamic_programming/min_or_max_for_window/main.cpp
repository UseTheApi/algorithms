//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/23/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "min_for_window.hpp"

int main(int argc, const char *argv[]){
	
	int size;
	std::cout << "Enter size of array: ";
	std::cin >> size;
	std::cout << "Enter elements of the array: ";
	std::vector<int> arr(size); // 1 -2 5 3 4 6 8 10
	for(int i = 0; i < size; ++i){
		std::cin >> arr[i];
	}

	for(auto it: arr){
		std::cout << it << " ";
	}
	std::cout << std::endl;
	int window_size;
	std::cout << "Enter size of window: ";
	std::cin >> window_size;

	std::cout << std::endl;
	std::cout << "Min for Window:" << std::endl;

	std::vector<int> result = min_for_window(arr, window_size);

	std::cout << "Result: " << std::endl;
	for(auto it: result){
		std::cout << it << " ";
	}
	std::cout << std::endl;
}