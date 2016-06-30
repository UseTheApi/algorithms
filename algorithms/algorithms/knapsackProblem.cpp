//
//  knapsack problem.cpp
//  algorithms
//
//  Created by alifar on 6/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include "knapsackProblem.hpp"

/*
 KnapSack Problem:
 We are given:
  1. A collection of n items
  2. Each item has an associated non-negative weight, wi
  3. Each item has an associated value (cost), ci
  4. And we are given a knapsack that can hold total weight W
 Our task is:
  * Determine the set S of items of maximum total value (cost) that can be contained in the knapsack subject to the constraint that the total weight is no greater than W
 
 Ex.: item | Value | Weight   W(capacity) = 11
        1  |   1   |   1
        2  |   6   |   2
        3  |   18  |   5
        4  |   22  |   6
        5  |   28  |   7
 
 In order to determine wether item will be put in a sack or not the total weight of combined items cannot be bigger then capacity of a knapsack. we create a table that will represent an increasing weight from 0 to 11 in columns and combination of items in rows. each cell will represent a summarized value for the current weight
 
 For each current cell we take the value above where the value is filled for other items in a current set and then check if new item can bring more profit to the value without exiding weights (like in a problem amountWithCoint.cpp we want to fill up to the maximum current weight in a table using previous results of the table: substraction of current weight maximum and current weight of an item that we work with).
 
 n/w | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
  0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |  0 |  0 |
  1  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |  1 |  1 |
  2  | 0 | 1 | 6 | 7 | 7 | 7 | 7 | 7 | 7 | 7 |  7 |  7 |
  3  | 0 | 1 | 6 | 7 | 7 | 18| 19| 22| 23| 23| 23 | 23 | cell[3][5]: we put 18 because the current max weight is 5 and item 3 weighs exactly 5. for cell[3][6]: we put 19 which is calculated from value of item 3 (18), then subtract current item weight from current max weight 6-5 = 1 and take cell[3][1] to sum with current 18.
  ... an so on filling the table untill done
*/

void printMat(int **matrix, int columns, int rows){
    for (int i=0; i<columns; ++i) {
        std::cout << i << " ";
        for(int j=0; j<rows; ++j){
            std::cout << matrix[i][j] << " ";
        }
    }
}

int maxValueforKnapsack(int capacity, int n_items, int *values, int *weights){
    /* 
     Assuming we need to find total maximum value we can put in a knapsack of capacity W
    */
    int res_matrix[capacity+1][n_items+1];
    for(int i=0; i<capacity+1; ++i){
        for(int j=0; j<n_items+1; ++j){
            res_matrix[i][j] = 0;
        }
    }
    
    for(int i=1; i<capacity+1; ++i){
        for(int j=1; j<n_items+1; ++j){
            res_matrix[i][j] = res_matrix[i][j-1];
            if(weights[j-1] <= i){ // if weight of current item higher then current max weight - skip
                //trying to add value of current item and sum it with the rest of allowed weight
                int new_value = values[j-1] + res_matrix[i-weights[j-1]][j-1];
                if(new_value > res_matrix[i][j]){
                    res_matrix[i][j] = new_value; // assigning new value if it's higher then previous
                }
            }
        }
    }
    
    std::cout << "RESULT:" << std::endl;
    for(int i=0; i<capacity+1; ++i){
        if(i==0){
            std::cout << "   ";
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for(int i=0; i<n_items+1; ++i) {
        std::cout << i << ": ";
        for(int j=0; j<capacity+1; ++j){
            std::cout << res_matrix[j][i] << " ";
        }
        std::cout << std::endl;
    }    return 0;
}