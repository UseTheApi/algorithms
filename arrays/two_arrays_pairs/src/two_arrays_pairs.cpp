//
//  two_arrays_pairs.cpp
//  algorithms. two_arrays_pairs
//
//  Created by alifar on 12/21/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "two_arrays_pairs.hpp"
#include <iostream>
#include <algorithm>

/*

*/

int PairsBruteForce(const std::vector<int> &arr1, const std::vector<int> &arr2, int el_sum){
	int count_pairs = 0;
	for(int i = 0; i < arr1.size(); ++i){
		for(int j = 0; j < arr1.size(); ++j){
			if(arr1[i] + arr2[j] <= el_sum){
				++count_pairs;
			}
		}
	}
	return count_pairs;
}

void print_matrix(std::vector< std::vector<int> > &mat){
	for(auto row = mat.begin(); row != mat.end(); ++row){
		for(auto el = row->begin(); el != row->end(); ++el){
			std::cout << *el << " ";
		}
		std::cout << std::endl;
	}
}

void init_matrix(
	std::vector< std::vector<int> > &mat, 
	const std::vector<int> &arr1, 
	const std::vector<int> &arr2, 
	int el_sum
	){
	int cur_sum = 0;
	int tmp = arr1[0] + arr2[0];
	mat[0][0] = tmp <= el_sum ? 1 : 0;
	for(int i = 1; i < arr1.size(); ++i){
		cur_sum = arr1[i] + arr2[0];
		// std::cout << mat[0][i] << std::endl;
		mat[0][i] = cur_sum <= el_sum ? mat[0][i-1]+1 : mat[0][i-1];
		cur_sum = arr1[0] + arr2[i];
		// std::cout << cur_sum << std::endl;
		mat[i][0] = cur_sum <= el_sum ? mat[i-1][0]+1 : mat[i-1][0];
	}
}

int PairsDP(const std::vector<int> &arr1, const std::vector<int> &arr2, int el_sum){
	int count_pairs = 0;
	std::vector<std::vector<int>> mat(arr1.size(), std::vector<int>(arr1.size()));
	init_matrix(mat, arr1, arr2, el_sum);
	// print_matrix(mat);
	for(int i = 1; i < arr1.size(); ++i){
		if(mat[0][i] == mat[i][0]){
			mat[i][i] = mat[i-1][i-1] + mat[0][i];
		} else if(mat[0][i] > mat[0][i-1] ||
			mat[i][0] > mat[i-1][0]){
			mat[i][i] = mat[i-1][i-1] + 1;
		} else{
			mat[i][i] = mat[i-1][i-1];
		}
	}
	// print_matrix(mat);
	return mat[arr1.size()-1][arr1.size()-1];
}
