//
//  multiply_number.hpp
//  algorithms
//
//  Created by alifar on 8/7/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <stack>

class MultiplyXPlusOne{
public: 
	int MinimalSteps(int, int);
	MultiplyXPlusOne();
private:
	int square_step(int);
	int cubical_step(int);
	int module_square(int);
	int module_cubical(int);
	int perform_square_step(int &);
	int perform_cubical_step(int &);
	std::stack<int> steps;
	int min_steps_number;
};