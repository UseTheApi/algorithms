//
//  hopSomeStairs.cpp
//  algorithms
//
//  Created by alifar on 6/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <iostream>
#include "hopSomeStairs.hpp"

/*
 A child is running up a staircase with n steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
 Implement a method to count how many possible ways the child can run up the stairs.
 Solution:
    n=0 => 1 (exaclty 1 possibility)
    n=1 => 1
    n=2 => 2: 11, 2
    n=3 => 4: 111, 12, 21, 3
    n=4 => 7: 1111, 112, 121, 211, 31, 13 => f(n-1)+f(n-2)+f(n-3) - a child can step into 4th stair either: 
                                                                    from the stair 1,2 or 3 below
*/

int walkThroughStairs(int n){
    int hops[n+1];
    hops[0] = 1; // we don't use this item for calculations but stil filling it
    hops[1] = 1;
    hops[2] = 2;
    hops[3] = 4;
    for(int i=4; i<n+1; ++i){ // i=4 because hops[0-3] is already filled out
        hops[i] = hops[i-1]+hops[i-2]+hops[i-3];
    }
    std::cout << "Calculated array of values" << std::endl;
    for(int i=0; i<n+1; ++i){
        std::cout << hops[i] << " ";
    }
    std::cout << std::endl;
    return hops[n];
}
