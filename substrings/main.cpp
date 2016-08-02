//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "substrings.hpp"

int main(int argc, const char *argv[]){
	auto *substrings = find_all_substrings("abc");
	for(auto it: *substrings){
		std::cout << it << std::endl;
	}
	return 1;
}