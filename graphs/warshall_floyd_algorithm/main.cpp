//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "warshall_algorithm_dp.hpp"
#include "floyd_algorithm_dp.hpp"
#include "matrix_utilities.hpp"

/*
	Graphs.
 Reachability: Warshall's Algorithm; Floyd's Algorithm;
*/

using namespace std;

int main(int argc, const char *argv[]){
	int w_size;
	cout << "Warshall Algorithm" << endl;
	cout << "--> Size of Adjacency Matrix (not-weighted digraph): ";
	cin >> w_size;
	cout << endl;

	vector< vector<int> > w_mat = init_matrix(w_size);
	cout << "--> Adjacency Matrix: " << endl;
	print_matrix(w_mat);
	cout << endl;
	vector< vector<int> > w_res = transitive_closure_warshall(w_mat);
	cout << "--> Reachability Matrix Calculated: " << endl;
	print_matrix(w_res);

	int f_size;
	cout << "Floyd Algorithm" << endl;
	cout << "--> Size of Adjacency Matrix (weighted digraph): ";
	cin >> f_size;
	cout << endl;

	vector< vector<int> > f_mat = init_matrix(f_size);
	cout << "--> Adjacency Matrix: " << endl;
	print_matrix(f_mat);
	cout << endl;
	vector< vector<int> > f_res = transitive_closure_floyd(f_mat);
	cout << "--> Reachability Matrix Calculated: " << endl;
	print_matrix(f_res);
}