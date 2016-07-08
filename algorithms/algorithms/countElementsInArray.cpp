//
//  countElementsInArray.cpp
//  algorithms
//
//  Created by alifar on 7/7/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "countElementsInArray.hpp"
#include <iostream>

/*
 Given a sorted array. Write a function that calculates all distinct absolute values in this array.
 Ex.: arr = [-3, -2, 0, 1, 2, 3], answer is 4 (0, 1, 2, 3)
 
 Solution 1 - keep a set of absolute values and then return it's size
 Solution 2 - O(n) time and O(1) space: 
    1. initialize count with total number of elements in array
    2. point to beginning and to the end of array
    3. if absolute values are equal then count--, else move forward or reverse iterator
    4. return count
*/

int abs(int number){
    return number>0 ? number : number*(-1);
}

size_t noDistinctValues(std::vector<int> numbers){
    size_t abs_count = numbers.size();
    auto f_it = numbers.begin();
    auto r_it = numbers.rbegin();
    while(f_it != numbers.end() && r_it != numbers.rend()){
        
        //std::cout << "Forward iterator: " << *f_it << std::endl;
        //std::cout << "Reverse iterator: " << *r_it << std::endl;
        
        if((f_it - numbers.begin()) + (r_it - numbers.rbegin()) == numbers.size()-1) break;
        if(*f_it == *(f_it+1)){ // considering duplicates on the left side of an array
            --abs_count;
            ++f_it;
            continue;
        }
        if(*r_it == *(r_it+1)){ // considering duplicates on the right side of an array
            --abs_count;
            ++r_it;
            continue;
        }
        if(abs(*f_it) == abs(*r_it)){
            --abs_count;
            ++f_it;
            ++r_it;
        } else if(abs(*f_it) > abs(*r_it))
            ++f_it;
        else
            ++r_it;
    }
    return abs_count;
}
