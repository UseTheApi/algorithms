//
//  productAllNumsExceptItself.cpp
//  algorithms
//
//  Created by alifar on 7/5/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include "productAllNumsExceptItself.hpp"

/*
 Given an array of integrs. Write a function that will return array of products of all numbers in a given array except itslef.
 Ex: [3,2,4,1] => [2*4*1, 3*4*1, 3*2*1, 3*2*4] => [8, 12, 6, 24]
 
 Solution 1 - brute force:
    1. iterate through result array with first for loop
    2. iterate through given array and make a product
    3. return result array
 
 Solution 2 - linear complexity:
    1. calculate left portion of product for i
    2. calculate right portion of product for i
    3. merge product left and product right (can be combined within step 2)
    4. return
*/

std::vector<int> productOfAllNumExceptItself(const std::vector<int> &numbers){ // O(n^2)
    /* Brute Force Solution*/
    std::vector<int> result(numbers.size(), 1);
    for(int i=0; i < result.size(); ++i){
        for(int j=0; j < numbers.size(); ++j){
            if(i!=j)
                result[i] *= numbers[j];
        }
    }
    return result;
}

std::vector<int> productOfAllNyumbersExceptItselfLinear(const std::vector<int> &numbers){
    std::vector<int> products(numbers.size());
    int tmp = 1; // starting left side (for first element in numbers left product is 1
    for(int i=0; i < products.size(); ++i){
        products[i] = tmp;
        tmp*=numbers[i];
    }
    tmp = 1; // for the most right element right product is 1 as well
    for(int i=static_cast<int>(products.size())-1; i >= 0; --i){ // C++ method for int()
        products[i] *= tmp;
        tmp *= numbers[i];
    }
    return products;
}