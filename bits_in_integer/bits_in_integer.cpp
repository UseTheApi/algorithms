//
//  bits_in_integer.cpp
//  algorithms
//
//  Created by alifar on 7/30/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "bits_in_integer.hpp"
#include <iostream>

/*
 Write an efficient program to count number of 1s in binary representation of an integer.
*/

int count_set_bits_int(int number){
	// simple method
	unsigned int bits = 0;
	while(number){
		bits += number & 1; // + either 0 or 1
		number >>= 1;
	}
	return bits;
}

int count_set_bits_int_Kernighan(int number){
	// Kernighan method using bitwise & of number with number-1
	unsigned int bits = 0;
	while(number){
		number = number & (number-1);
		++bits;
	}
	return bits;
}

int quick_pow10(int n){
    static int pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };

    return pow10[n]; 
}

int convert_vector_to_int(std::vector<int> &binary_array){
 	unsigned int number_of_digits = binary_array.size();
 	int result_num = 0;
 	for(auto it: binary_array){
 		int cur_digit = quick_pow10(number_of_digits-1);
 		result_num += it*cur_digit;
 		--number_of_digits;
 	}
 	return result_num;
}

int binary_int(int number){
	std::vector<int> binary_representaiton;
	while(number){
		int bit = number & 1;
		binary_representaiton.insert(binary_representaiton.begin(), bit);
		number >>= 1;
	}
	int result = convert_vector_to_int(binary_representaiton);
	return result;
}

