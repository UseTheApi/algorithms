//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/7/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "multiply_number.hpp"
#include <iostream>

int main(int argc, const char *argv[]){
	MultiplyXPlusOne *test = new MultiplyXPlusOne();
	std::cout << test->MinimalSteps(55555, 100000) << std::endl;
}