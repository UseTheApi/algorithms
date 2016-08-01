//
//  main.cpp
//  algorithms
//
//  Created by alifar on 7/30/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "bits_in_integer.hpp"
#include <iostream>

int main(int argc, const char *argv[]){
	std::cout << "Counting 1 in interger" << std::endl;
	std::cout << "--> Simple method" << std::endl;
	int i = 10;
	while(i){
		std::cout << "number " << i << " -> " << binary_int(i) << " - ";
		std::cout << "result: " << count_bits_int(i) << std::endl;
		--i;
	}
}