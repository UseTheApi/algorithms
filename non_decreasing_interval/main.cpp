//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/8/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "non_decreasing_interval.hpp"

int main(int argc, const char *argv[]){
	std::vector<int> init = {0, 1, 3, 2, -1, 4, 7, 9};
	std::vector<int> result = max_increasing_interval(init);

	for(auto it: result){
		std::cout << it << " ";
	}
	std::cout << std::endl;
}