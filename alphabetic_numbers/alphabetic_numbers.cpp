//
//  alphabetic_numbers.cpp
//  algorithms
//
//  Created by alifar on 8/21/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "alphabetic_numbers.hpp"

/*
 Given an mapped alphabet A=1, B=2, C=3 ...Z=26 
 Calculate how many words can you form from a given number.

 Section: DP.
 	1 method: calculate from the begining of the number: d[i] = [di-1] + (d[i-2] if d[i-1]+arr[i] < 27) - requires to cast number to an array
 	2 method: calculate from the end of the number: cur_number%100 < 27 ? then d[i] = [di-1] + d[i-2] - no need to cast number to an array
*/

using namespace std;

map<int, char> alphabet = { {1, 'A'}, {2, 'B'}, {3, 'C'}, {4, 'D'}, {5, 'E'}, {6, 'F'}, {7, 'G'},
							{8, 'H'}, {9, 'I'}, {10, 'J'}, {11, 'K'}, {12, 'L'}, {13, 'M'}, {14, 'N'},
							{15, 'O'}, {16, 'P'}, {17, 'Q'}, {18, 'R'}, {19, 'S'}, {20, 'T'}, {21, 'U'}, {22, 'V'},
							{23, 'W'}, {24, 'X'}, {25, 'Y'}, {26, 'Z'} };

void print_alphabet(){
	for(int i = 1; i <= 26; ++i){
		cout << alphabet[i] << " ";
	}
}

vector<int> get_digits(int number){
	vector<int> num_vec;
	while(number){
		num_vec.insert(num_vec.begin(), number % 10);
		number /= 10;
	}
	return num_vec;
}

int num_of_digits(int number){
	int count = 0;
	while(number){
		number /= 10;
		++count;
	}
	return count;
}

int WordsCountBackwards(int number){
	/*
	 This method assumes there is no zeroes in a given number
	*/
	int size = num_of_digits(number) + 1;
	vector<int> result(size); 
	int cur_number = 0;
	int i = 2;
	result[0] = 1; // initial state
	result[1] = 1;
	while(number){
		if(number > 10){
			cur_number = number%100;
			if(cur_number < 27){
				result[i] += result[i-2];
			}
			result[i] += result[i-1];
		}
		number /= 10;
		++i;
	}
	return result[size - 1];
}

int WordsCountStraight(int number){
	/*
	 This method assumes there is no zeroes in a given number
	*/
	vector<int> n_vector = get_digits(number);

	vector<int>result(n_vector.size());
	result[0] = 1;
	result[1] = 1;

	for(int i = 2; i < n_vector.size(); ++i){
		if(n_vector[i-1]*10 + n_vector[1] < 27){
			result[i] += result[i-2];
		}
		result[i] += result[i-1];
	}
	return result[n_vector.size() - 1];
}

int WordsCount(int number){
	/*
	 This method can deal with zeroes in a given number:
	 1023 -> 10,2,3; 10,23. 
	 result=[1,2]
	*/
	vector<int> n_vector = get_digits(number);
	vector<int> result(n_vector.size());
	if(n_vector[0]){
		result[0] = 1;
	} else{
		result[0] = 0;
	}
	result[1] = result[0];
	if(result[0]*10 + result[1] < 27){
		result[1] += 1;
	}

	for(int i = 2; i < n_vector.size(); ++i){
		result[i] = result[i-1];
		int last_two_digits = n_vector[i-1]*10 + n_vector[i];
		if( last_two_digits > n_vector[i] && last_two_digits < 27 ){
			result[i] += result[i-2];
		}
	}

	return result[n_vector.size()-1];
}
