//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "max_without_comparison.hpp"

int main(int argc, char *agrv[]){
	std::cout << "Calculating max number without comparison\n";

	std::cout << "Case 1:\n";
	int result = max_number_without_comparison(4, 5);
	std::cout << "--> result: " << result << std::endl;

	std::cout << "Case 2:\n";
	result = max_number_without_comparison(6, 3);
	std::cout << "--> result: " << result << std::endl;

	std::cout << "Case 3:\n";
	result = max_number_without_comparison(100, 0);
	std::cout << "--> result: " << result << std::endl;

	std::cout << "Case 4:\n";
	result = max_number_without_comparison(123, 123);
	std::cout << "--> result: " << result << std::endl;

	std::cout << "Case 5:\n";
	result = max_number_without_comparison(-1, -5);
	std::cout << "--> result: " << result << std::endl;

	return 0;
}