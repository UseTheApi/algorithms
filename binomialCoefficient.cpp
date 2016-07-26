//
//  binomialCoeffitient.cpp
//  algorithms
//
//  Created by alifar on 6/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "binomialCoefficient.hpp"

/* Implementation shows creating a matrix representation of Pascal's triangle
   At First initial filling of the matrix fills vertical and diogonal with 1
   Then based on pre-cached results in the matrix it becomes possible to fill the matrix without recursion
 Solution:
    calculate binomial coefficients: n=5, k=4
    Building a Pascal's triangle:
 
    n/k| 0 1 2 3  4  5
     0   1
     1   1 1
     2   1 2 1
     3   1 3 3 1
     4   1 4 6 4 1
     5   1 5 10 10 5 1 solution is 5
*/

int ** fillInitial(int ** matrix, int size){
    for(int i=0; i < size; ++i){
        matrix[i][i] = 1;
        matrix[i][0] = 1;
    }
    return matrix;
}

void printMatrix(int **matrix, int size){
    for(int i=0; i < size; ++i){
        std::cout << i << ": ";
        for (int j = 0; j < size; ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int ** initMatrix(int size){
    
    int ** matrix = new int *[size];
    for(int i=0; i < size; ++i){
        matrix[i] = new int[size];
        for(int j=0; j < size; ++j){
            matrix[i][j] = 0;
        }
    }
    return fillInitial(matrix, size);
}

int bimonialCoefficient(int n, int k){
    int max_size = std::max(n, k);
    int **matrix = initMatrix(max_size);
    std::cout << "Initial matrix" << std::endl;
    printMatrix(matrix, max_size);
    
    for(int i = 2; i < max_size; ++i){
        for(int j = 1; j < i; ++j){
            matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
        }
    }
    std::cout << "Final filled out Matrix" << std::endl;
    printMatrix(matrix, max_size);
    return matrix[n-1][k-1];
}
