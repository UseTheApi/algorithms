//
//  index_cycle.cpp
//  algorithms. determing a cycle
//
//  Created by alifar on 10/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "index_cycle.hpp"
#include <iostream>

/*
 Determine whether a circular array of relative indices is composed of a single, complete cycle

 Solution:
  1. Make n steps in array, where n is number of elements in array
  2. If after n steps loop returned back to first position in array - complete cycle detected
*/

bool HasCompleteCycle(const std::vector<int> &array){
	int cur_pos = 0;
	std::cout << "Starting at: " << array[cur_pos] << std::endl;
	for(int i = 0; i < array.size(); ++i){
		cur_pos = (cur_pos + array[cur_pos]) % array.size();
		std::cout << "Current element: " << array[cur_pos] << std::endl;
		if(cur_pos == 0){
			return false;
		}
	}
	return cur_pos == 0;
}

bool HasCompleteCycleSpace(const std::vector<int> &array){
	/*
	 This method allows us to determine earlier 
	 if there is an incomplete cycle in array 
	 by storing visited positions in additional vector
	*/

	std::vector<int> visited;
	visited.push_back(0);
	int position = 0;
	while(visited.size() < array.size()){
		position = (position + array[position]) % array.size();
		if(std::find(visited.begin(), visited.end(), position) == visited.end()){
			visited.push_back(position);
		} else{
			return false;
		}
	}
	return true;
}
