//
//  biggest_interval.cpp
//  algorithms. biggest_interval
//
//  Created by alifar on 02/05/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "biggest_interval.hpp"
#include <algorithm>
#include <iostream>

bool compare(std::pair<int, int> &left, std::pair<int, int> &right){
	return left.first < right.first;
}

std::pair<int, int> CalculateInterval(std::vector<std::pair<int, int>> intervals){
	std::sort(intervals.begin(), intervals.end(), compare);
	int cur_start = intervals[0].first;
	int cur_end = intervals[0].second;
	for(int i = 0; i < intervals.size(); ++i){
		if(intervals[i].first > intervals[i-1].second){
			if(intervals[i].second - intervals[i].first > cur_end - cur_start){
				cur_end = intervals[i].second;
				cur_start = intervals[i].first;
			}
		} else{
			cur_end = intervals[i].second;
		}
	}
	return std::pair<int, int>(cur_start, cur_end);
}
