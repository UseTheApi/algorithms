//
//  binary_search.cpp
//  algorithms
//
//  Created by alifar on 7/8/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "binary_search.hpp"
#include <iostream>

/*
 Given a sorted arr[] of elements. Write a function to search a given element x in arr[]. Time complexity is O(logn)
*/

int BinarySearch(const std::vector<int> &array, int num){
    int begin = 0;
    int end = static_cast<int>(array.size()) - 1;
    int median;
    while(begin <= end){
        median = (end+begin)/2;
        if(num == array[median]){
            return median;
        } else if(num > array[median]){
            begin = median+1;
        } else{
            end = median-1;
        }
    }
    return -1;
}
