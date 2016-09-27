//
//  max_wealth.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "max_wealth.hpp"
#include <algorithm>

/*
 Given some matrix:
 Ex:
    1 2 0 0
    0 1 3 1
    2 2 0 2
    0 2 2 0
 find the max wealth accumulated while travelling from 0,0 to 3,3 but u can only go right or down
*/

using namespace std;

void init_rows(const vector< vector<int> > &matrix, vector< vector<int> > &result, int rows_num){
	int max_wealth_down = 0;
	for(int i = 0; i < rows_num; ++i){
		max_wealth_down += matrix[i][0];
		result[i][0] = max_wealth_down;
	}
}

void init_columns(const vector< vector<int> > &matrix, vector< vector<int> > &result, int column_num){
	int max_wealth_right = 0;
	for(int i = 0; i < column_num; ++i){
		max_wealth_right += matrix[0][i];
		result[0][i] = max_wealth_right;
	}
}

void print_matrix(const vector< vector<int> > &mat){
	for(auto row = mat.begin(); row != mat.end(); ++row){
		for(auto el = row->begin(); el != row->end(); ++el){
			cout << *el << " ";
		}
		cout << endl;
	}
}

int MaxWealth(const vector< vector<int> > &matrix, int rows_num, int column_num){
	vector< vector<int> > result(rows_num, vector<int>(column_num));
	init_rows(matrix, result, rows_num);
	init_columns(matrix, result, column_num);

	for(int i = 1; i < rows_num; ++i){
		for(int j = 1; j < column_num; ++j){
			result[i][j] = matrix[i][j] + max(result[i-1][j], result[i][j-1]);
		}
	}

	cout << "--> Result matrix: " << endl;
	print_matrix(result);
	cout << endl;

	return result[rows_num-1][column_num-1];
}