//
//  matrix_utilities.hpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <vector>
#include <iostream>

using namespace std;

void print_matrix(const vector< vector<int> > &matrix){
	for(auto it = matrix.begin(); it != matrix.end(); ++it){
 		for(auto el = it->begin(); el != it->end(); ++el){
 			cout << *el << " ";
 		}
 		cout << endl;
 	}
 	return;
};

vector< vector<int> > init_matrix(int size){
 	vector< vector<int> > mat(size, vector<int>(size));
 	for(int i = 0; i < size; ++i){
 		cout << i+1 << "st row: ";
 		for(int j = 0; j < size; ++j){
 			cin >> mat[i][j];
 		}
 	}
 	return mat;
};