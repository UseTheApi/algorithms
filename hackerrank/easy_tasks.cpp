//
//  easy_tasks.cpp
//  algorithms
//
//  Created by alifar on 8/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "easy_tasks.hpp"
#include <iostream>
#include <string>

/*
 Initial matrix creation. subtask
*/

 std::vector< std::vector<int> > init_matrix(){
 	int n;
	std::cin >> n;
	std::vector< std::vector<int> > mat(n, std::vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			std::cin >> mat[i][j];
		}
	}

	for(auto it = mat.begin(); it != mat.end(); ++it){
		for(auto ti = it->begin(); ti != it->end(); ++ti){
			std::cout << *ti << " ";
		}
		std::cout << std::endl;
	}
	return mat;
 }

/*
 Given a 2d matrix. Write a function that calculates an absolute delta between sums of two diogonals
*/

int diagonals_subtract(const std::vector< std::vector<int> > &matrix){
	int d1_sum = 0;
	int d2_sum = 0;
	for(int i = 0; i < matrix.size(); ++i){
		d1_sum += matrix[i][i];
		d2_sum += matrix[matrix.size()-i-1][i];
	}
	int delta = d1_sum - d2_sum;
	return delta > 0 ? delta : delta*(-1);
}

/*
 Given an array of integers, calculate which fraction of its elements are positive, 
 which fraction of its elements are negative, and which fraction of its elements are zeroes, respectively. 
 Print the decimal value of each fraction on a new line.
*/

void fractions(const std::vector<int> &array){
	double n = static_cast<double>(array.size());
	double f_positive = 0.;
	double f_negative = 0.;
	double f_zeroes = 0.;

	double n_positive = 0.;
	double n_negative = 0.;
	double n_zeroes = 0.;
	for(auto it: array){
		std::cout << it << " ";
		if(it == 0){
			++n_zeroes;
		} else if(it > 0){
			++n_positive;
		} else{
			++n_negative;
		}
	}
	std::cout << std::endl;

	std::cout << n_positive << " " << n_negative << " " << n_zeroes << std::endl;

	f_positive = static_cast<double>(n_positive/n);
	f_negative = n_negative/n;
	f_zeroes = n_zeroes/n;
	std::cout << f_positive << " " << f_negative << " " << f_zeroes << std::endl;
 }

/*
 Write a program that prints a staircase (using # symbols) of size n
 */

void staircase(int n){
	std::string hashtags = "";
	std::string space = "";
	for(int i = 0; i < n-1; ++i){
		space.insert(0, " ");
	}
	int number_of_spaces = n-1;
	for(int i = 0; i < n; ++i){
		hashtags += "#";
		std::cout << space;
		if(!space.empty){
			space.pop_back();
		}
		std::cout << hashtags << std::endl;
		// --number_of_spaces;
	}
	// space.pop_back();
}
