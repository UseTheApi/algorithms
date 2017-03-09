//
//  optimal_bst.cpp
//  algorithms. Dynamic Programming. Optimal BST 
//
//  Created by alifar on 03/09/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "optimal_bst.hpp"
#include <climits>

int sum(std::vector<int> weights, size_t i, size_t j){
    /*
    int res_sum = 0;
    while(i!=j){
        res_sum += weights[i];
        ++i;
    }
    std::cout << "RES: " << res_sum;
    return res_sum;
    */
    int res_sum = 0;
    for(size_t k = i; k <= j; ++k){
        res_sum += weights[k];
    }
    return res_sum;
}

int OptimalBst(std::vector<int> keys, std::vector<int> weights){
    int cost[keys.size()][keys.size()];
    size_t j;
    int cur_cost;
    for(size_t i = 0; i < weights.size(); ++i){
        cost[i][i] = weights[i];
    }
    for(size_t l=2; l <= keys.size(); ++l){
        for(size_t i = 0; i < keys.size() - l + 1; ++i){
            j = i + l - 1;
            cost[i][j] = INT_MAX;
            for(size_t r = i; r <= j; ++r){
                cur_cost = ((r > j) ? cost[i][r-1] : 0) + 
                           ((r < j) ? cost[r+1][j]:0) + 
                           sum(weights, i, j);
                if(cost[i][j] > cur_cost){
                    cost[i][j] = cur_cost;
                }
            }
        }
    }
    /*
    std::cout << std::endl;
    for(size_t i = 0; i < keys.size(); ++i){
        for(size_t j = 0; j < keys.size(); ++j){
            std::cout << cost[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    return cost[0][keys.size()-1];
}

