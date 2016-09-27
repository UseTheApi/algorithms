//
//  non_decreasing_interval.cpp
//  algorithms
//
//  Created by alifar on 8/8/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "non_decreasing_interval.hpp"
#include <utility>

/*
 Given an array of intergers. Write a funtion that returns an array of max length 
  with non-decreasing elements from a given array
*/

using namespace std;

vector<int> max_increasing_interval(vector<int> &array){
	int start = 0;
	int end = 1;
	array.push_back(INT_MIN);

    // start of interval and length
	pair<int, int> max_interval (0,0);

	for(int i = 0; i < array.size(); ++i){
		if(array[end] > array[i]){
			++end;
		} else{
			if(max_interval.second < end-start){
				max_interval.first = start;
				max_interval.second = end-start;
			}
			start = end;
			++end;
		}
		++i;
	}

	auto it = array.begin();

	return vector<int>(it+max_interval.first, it+max_interval.first+max_interval.second);
}