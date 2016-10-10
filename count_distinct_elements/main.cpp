//
//  main.cpp
//  algorithms
//
//  Created by alifar on 10/10/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "count_elements.hpp"
#include <iostream>

using namespace std;

// TEST: Count distinct absolute numbers in array: countElementsInArray.hpp
//    std::vector<int> numbers = {-3, -2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 3};
//    std::cout << noDistinctValues(numbers) << std::endl;

int main(int argc, const char *argv[]){
	vector<int> numbers;

	int item;
	do{
		cin >> item;
		numbers.push_back(item);
	} while(cin.get() != '\n');
	
	return 0;
}