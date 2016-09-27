//
//  pascalsTriangle.cpp
//  algorithms
//
//  Created by alifar on 7/5/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "pascals_triangle.hpp"

/*
 Given an index k, return the kth row of the Pascal's triangle.
 
 For example, given k = 3,
 Return [1,3,3,1].
 
 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 
    Solution 1 - brute force:
        1. create a matrix that would represent Pascal's triangle (like in binomialCoefficient.cpp)
        2. fill out matrix until have kth row filled
        3. return kth row
    Solution 2 - O(k) space:
        Pascal's Triangle:
      k
      0: 1
      1: 1 1
      2: 1 2 1
      3: 1 3 3 1 - answer
      4: 1 4 6 4 1
        
        Actual representation of Pascal's Triangle let us see a pattern that is a key to effitient solution
        
        1. Length of row = k+1 for any k
        2. Each next element of a row can be calculated based on length of the row and previous element: ((length - cur_column)/cur_column)*prev_element
 */

std::vector<int> rowInPascalsTriangle(int k){
    int length = k+1; // length of kth row
    std::vector<int> row(k+1);
    row[0] = 1;
    for(int i=1; i < length; ++i){
        row[i] = row[i-1]*(length - i)/i;
    }
    return row;
}
