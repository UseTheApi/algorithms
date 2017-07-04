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
#include <map>

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
		if(!space.empty()){
			space.pop_back();
		}
		std::cout << hashtags << std::endl;
		// --number_of_spaces;
	}
	// space.pop_back();
}


void foo(){
	/*
	3 2 3
	1 2 3
	0
	1
	2

 	3 - n, 2 - k(times of rotation), 3 - q (number os query)
 	arr = 1 2 3
 	0
 	1
 	2
	*/
	using namespace std;
    int n = 3;
    int k = 2;
    int q = 3;
    //cin >> n >> k >> q;
//    cout << " ";
//    cin >> k;
//    cout << " ";
//    cin >> q;
    cout << endl;
    int element;
    vector<int> input;
    for(int i = 0; i < n; ++i){
        cin >> element;
        input.push_back(element);
    }
    int to_rotate;
    for(int i = 0; i < k; ++i){
        to_rotate = input.back();
        input.pop_back();
        input.insert(input.begin(), to_rotate);
        
    }
    cout << endl;
    for( auto it: input){
        cout << it << " ";
    }
    cout << endl;
    int index;
    for(int i = 0; i < q; ++i){
        cin >> index;
        cout << input[index] << endl;
    }

}

void count_numbers(std::vector<int> &array){
	size_t size = static_cast<int>(array.size());
	int cur_count;
	std::map<int, int> counts;
	for(size_t i = 0; i < size; ++i){
		counts[array[i]] += i;
	}
}
