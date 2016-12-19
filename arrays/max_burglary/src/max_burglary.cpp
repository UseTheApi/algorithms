//
//  max_burglary.hpp
//  algorithms. determing a cycle
//
//  Created by alifar on 12/19/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "max_burglary.hpp"

/*
 The burglar wants to get the max profit from the street of houses. 
 Given array represents amount of money in each house.
 The robber cannot get into two houses in a row - the alarm will work and he will get caught.

*/

int MaxProfit(const std::vector<int> &array){
	int sum_cur = 0;
	int tmp;
	int sum_res = array[0];
	for(int i = 1; i < array.size(); ++i){
		if(sum_cur+array[i] > sum_res){
		tmp = sum_cur;
		sum_cur = sum_res;
		sum_res = tmp + array[i];
		} else{
			sum_cur = sum_res;
		}
	}
	return sum_res;
}
