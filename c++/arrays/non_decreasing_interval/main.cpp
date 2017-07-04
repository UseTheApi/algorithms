//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/8/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "non_decreasing_interval.hpp"

int main(int argc, const char *argv[]){
	std::cout << "==== Non Decreasing Interval ====" << std::endl;

	std::vector<int> arr;

	int item;

	std::cout << "Enter elements of array: ";
	do{
		std::cin >> item;
		arr.push_back(item);
	} while(std::cin.get() != '\n');

	std::vector<int> result = max_increasing_interval(arr);

	for(auto it: result){
		std::cout << it << " ";
	}
	std::cout << std::endl;
}