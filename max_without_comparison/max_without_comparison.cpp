//
//  max_without_comparison.cpp
//  algorithms
//
//  Created by alifar on 8/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "max_without_comparison.hpp"

/*
 Write a function that returns max of two numbers without using any comparison operators.
*/

 int max_number_without_comparison(int first, int second){
 	std::cout << "--> numbers: " << first << " and "<< second << std::endl;
 	int delta = first - second; // either negative or positive
 	std::cout << "--> delta: " << delta << std::endl;
 	int sign_bit = (delta >> 31) & 1; // 31 bit is a sign bit. 0 if positive and -1 if negative. thus & 1
 	std::cout << "--> sign_bit: " << sign_bit << std::endl;
 	int max_number = first - delta*sign_bit; // either first is max or first+delta (second)
 	std::cout << "--> max_number: " << max_number << std::endl;
 	return max_number;
 }