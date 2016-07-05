//
//  pairs.cpp
//  algorithms
//
//  Created by alifar on 7/5/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "pairs.hpp"
#include <algorithm>
#include <iostream>

/*
 Given N integers, count the number of pairs of integers whose difference is K.
 Ex: [1,5,3,4,2], 2 => answer: 3 (3-1, 5-3, 4-2)
 
 Solution:
    1. two pointers to array: arr[0] and arr[1]
    2. iterate one or another based on appeared usecases:
        1. current subtraction > given
        2. current subtraction < given
        3. current subtraction == given
*/

int pairs(std::vector<int> &numbers, int diff){
    int i = 0; // 1st pointer to beginning of array
    int j = 1; // 2d pointer to 1st element in array
    int result = 0;
    std::sort(numbers.begin(), numbers.end());
    for(auto it: numbers){
        std::cout << it << " ";
    }
    std::cout << std::endl;
    while(i!=numbers.size() && j!=numbers.size()){
        if(numbers[j]-numbers[i] < diff) j++;
        else if(numbers[j]-numbers[i] == diff){
            result++; i++; j++;
        }
        else i++;
    }
    return result;
}