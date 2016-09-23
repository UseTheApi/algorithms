//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "max_wealth.hpp"

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

int main(int argc, const char *argv[]){
	int rows_num;
	cout << "--> Number of Rows: ";
	cin >> rows_num;
	int column_num;
	cout << "--> Number of Columns: ";
	cin >> column_num;
	cout << endl;

	vector< vector<int> > matrix;
	matrix.resize(rows_num+1);

	for(int i = 0; i < rows_num; ++i){
		cout << i+1 << "st row: ";
		matrix[i].resize(column_num);
		for(int j = 0; j < column_num; ++j){
			cin >> matrix[i][j];
		}
	}

	cout << endl <<  "--> Initial matrix:" << endl;
	print_matrix(matrix);

	
	int res = MaxWealth(matrix, rows_num, column_num);
	cout << "Max Welth: " << res << endl;
}