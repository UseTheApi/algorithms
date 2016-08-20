//
//  warshall_algorithm_dp.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "warshall_algorithm_dp.hpp"

using namespace std;

/*
	Graphs.
 Reachability: Warshall's Algorithm.

 Given an adjacency matrix of the digraph G = (V,E). Constract a reachability matrix R=(rij) of G, where:

 	rij = 1, if G has a directed vi-vj path.
 	rij = 0, otherwise

 Conclusion: If there is a path from vi to vj, then we have some k for which correct: rik && rkj = 1;

 Adjacency matrix has size n*n where n is number of vertices in G.
*/

vector< vector<int> > transitive_closure_warshall(vector< vector<int> > &adjacency_matrix){
	int k_max = adjacency_matrix.size();
	for(int k = 0; k < k_max; ++k){
		for(int i = 0; i < k_max; ++i){
			for(int j = 0; j < k_max; ++j){
				adjacency_matrix[i][j] = adjacency_matrix[i][j] || (adjacency_matrix[i][k] && adjacency_matrix[k][j]);
			}
		}
	}
	return adjacency_matrix;
}

