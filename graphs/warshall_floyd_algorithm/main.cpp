//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "warshall_algorithm_dp.hpp"

/*
	Graphs.
 Reachability: Warshall's Algorithm.

 Given an adjacency matrix of the digraph G = (V,E). Constract a reachability matrix R=(rij) of G, where:

 	rij = 1, if G has a directed vi-vj path.
 	rij = 0, otherwise
*/

using namespace std;

int main(int argc, const char *argv[]){
	int size;
	cout << "--> Size of Adjacency Matrix: ";
	cin >> size;
	cout << endl;

	vector< vector<int> > mat = init_matrix(size);
	cout << "--> Adjacency Matrix: " << endl;
	print_matrix(mat);
	cout << endl;
	vector< vector<int> > res = transitive_closure_warshall(mat);
	cout << "--> Reachability Matrix Calculated: " << endl;
	print_matrix(res);
}