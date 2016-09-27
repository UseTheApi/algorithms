//
//  main.cpp
//  alphabetic_numbers
//
//  Created by alifar on 8/21/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "alphabetic_numbers.hpp"

/*
 Given an mapped alphabet A=1, B=2, C=3 ...Z=26 
 Calculate how many words can you form from a given number.

 Section: DP.
 	1 method: calculate from the begining of the number: d[i] = [di-1] + (d[i-2] if d[i-1]+arr[i] < 27) - requires to cast number to an array
 	2 method: calculate from the end of the number: cur_number%100 < 27 ? then d[i] = [di-1] + d[i-2] - no need to cast number to an array
*/

int main(int argc, const char *argv[]){
	int code;
	std::cout << "Enter an code (integer) (ctrl+d to stop): ";
	while(std::cin >> code){ // ctrl+d to stop
		std::cout << "Number of words to be formed from the code: " << WordsCount(code) << std::endl;
	}

	// Another useful Test:

	// std::cout << WordsCountStraight(2143) << std::endl;
	// std::cout << WordsCountBackwards(2113) << std::endl;
	// std::cout << WordsCount(20102143) << std::endl;
	return 0;
}