//
//  amountWithCoins.cpp
//  algorithms
//
//  Created by alifar on 6/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <iostream>
#include "amountWithCoins.hpp"

/*
 Write a function that, given:
 1. an amount of money
 2. a list of coin denominations
 computes the number of ways to make amount of money with coins of the available denominations.
 
 This problem is related to hopSomeStairs problem, but amount of steps that a child can hop is now given as an input
 
 so for amount of 5 we got coins [1,3,5]
    n=0 => 1
    n=1 => 1
    n=2 => 1: 11  (2 is not given)
    n=3 => 2: 111, 3 - how can we figure out how to calculate possibilities of 3?
    n=4 => 2: 1111, 13 (4 is not given)
    n=5 => 3: 11111, 113, 5 => f(n-2)+f(n-4) = f(n=3)+f(n=1) = 2+1 = 3.
 
 Indexes of array that we use for caching calculations is representing a given number: arr[5+1] = [0,0,0,0,0,0] (indices are: 0,1,2,3,4,5). 
 0: [1,0,0,0,0,0] - 0 amount we can fill by only 1 way
 1: [1,1,1,1,1,1] - if we have an amount=1(following indices) we can figure out how much is left in amount by substraction actual coin value from current amount (1) = 0. now we can sum(res[0]+res[1] = res[1] = 1) and so on until array is filled out
 3: [1,1,1,2,2,2] - with 3 we start from 3 because we cannot fill amount of 2 with coin of 3 value. following the same directions getting a result
 5: [1,1,1,2,2,3] => answer is res[n=5] = 3
*/

int waysToGetAmount(int amount, int *denominations){
    int result[amount+1];
    for(int i=0; i<amount+1; ++i){ // just feeling empty array with 0
        result[i]=0;
    }
    int den_length = sizeof(denominations)/sizeof(*denominations) + 1; //hack to get a length of an array (not given in inputs)
    std::cout << "number of coins: " << den_length << std::endl;
    result[0] = 1; // for amount of 0 there is only 1 possibility
    for(int i=0; i < den_length; ++i){ // loop through denominations
        int coin = denominations[i];
        for(int j=coin; j<amount+1; ++j){ // loop through the result array starting with amount of a coin
            int rest = j-coin;            // calculating the rest to cover it with other coins
            result[j] += result[rest];    // calculating a result
        }
        std::cout << "for current coin " << coin << " result array is:" << std::endl;
        for(int k=0; k<amount+1; ++k){
            std::cout << result[k] << " ";
        }
        std::cout << std::endl;
    }
    return result[amount];
}
