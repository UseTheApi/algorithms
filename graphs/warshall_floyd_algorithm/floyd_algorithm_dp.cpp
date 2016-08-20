//
//  floyd_algorithm_dp.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "floyd_algorithm_dp.hpp"
#include <algorithm>

using namespace std;

vector< vector<int> > transitive_closure_floyd(vector< vector<int> > &adjacency_matrix){
	int k_max = adjacency_matrix.size();
	for(int k = 0; k < k_max; ++k){
		for(int i = 0; i < k_max; ++i){
			for(int j = 0; j < k_max; ++j){
				adjacency_matrix[i][j] = min(adjacency_matrix[i][j], adjacency_matrix[i][k] + adjacency_matrix[k][j]);
			}
		}
	}
	return adjacency_matrix;
}