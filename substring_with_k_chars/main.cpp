//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/22/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "substr_with_k_chars.hpp"

int main(int argc, const char *argv[]){
	std::cout << "String: abbaaaccb" << std::endl; 
	std::cout << "Max Length of One Char String: " << std::endl;
	std::cout << max_length_one_char("abbaaaccb") << std::endl;
	std::cout << "Max Length of Two Char String: " << std::endl;
	std::cout << max_length_k_distinct_chars("abbaaaccb", 2) << std::endl;
}