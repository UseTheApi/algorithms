//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/21/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "alphabetic_numbers.hpp"

/*
 Given an mapped alphabet A=1, B=2, C=3 ...Z=26 
 Calculate how many words can you from a given number.

 Section: DP.
 	1 method: calculate from the begining of the number: d[i] = [di-1] + (d[i-2] if d[i-1]+arr[i] < 27) - requires to cast number to an array
 	2 method: calculate from the end of the number: cur_number%100 < 27 ? then d[i] = [di-1] + d[i-2] - no need to cast number to an array
*/

int main(int argc, const char *argv[]){
	std::cout << WordsCountStraight(2113) << std::endl;
	std::cout << WordsCountBackwards(2113) << std::endl;
	return 0;
}