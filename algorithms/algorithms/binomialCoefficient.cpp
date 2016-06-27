//
//  binomialCoeffitient.cpp
//  algorithms
//
//  Created by alifar on 6/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "binomialCoeffitient.hpp"

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
    printMatrix(matrix, max_size);
    //std::cout << matrix[2-1][0] << " " << matrix[2][1] << std::endl;
    
    for(int i = 2; i < max_size; ++i){
        for(int j = 1; j < i; ++j){
            matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
        }
    }
    
    printMatrix(matrix, max_size);
    return matrix[n-1][k-1];
}