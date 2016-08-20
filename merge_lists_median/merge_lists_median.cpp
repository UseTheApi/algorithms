//
//  merge_lists_median.cpp
//  algorithms
//
//  Created by alifar on 8/14/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "merge_lists_median.hpp"
#include <algorithm>

/*
 Given two sorted array. Write a function that returns a median of merged array. 
 Both arrays are of the same size
*/

 int median(std::vector<int> &arr){
 	int size = static_cast<int>(arr.size());
 	if(size % 2 == 0){
 		return (arr[size/2] + arr[size/2 - 1])/2;
 	} else{
 		return arr[size/2];
 	}
 }

 int MedianOfMergedArray(std::vector<int> &first_arr, std::vector<int> &second_arr, int size){
 	/*
 	 
 	 arr1=[1, 3, 4, 6], arr2=[5, 7, 8, 9] => [1, 3, 4, 5, 6, 7, 8, 9]=>
 	 => med1=(3+4)/2=3; med2=(7+8)/2=7

 	 if(med1 < med2) => arr1[3, 4, 6]; arr2[5, 7, 8]=> med1=4; med2=7
 	 med1<med2) => arr1[4, 6]; arr2[5, 7] => size=2=> (5+6)/2

 	*/
 	if(size == 0){ 
 		return -1;
 	} else if(size == 1){
 		return (first_arr[0] + second_arr[0])/2;
 	} else if(size == 2){
 		return (std::max(first_arr[0], second_arr[0]) + std::min(first_arr[1], second_arr[1]))/2;
 	}

 	int med1 = median(first_arr);
 	int med2 = median(second_arr);

 	if(med1 == med2){
 		return med1;
 	}

 	if(med1 < med2){ // then we can view arr1[med1,...] and arr2[...,med2]
 		if(size % 2 == 0){
 			std::vector<int> new_first(first_arr.begin(),first_arr.begin()+size/2-1);
 			return MedianOfMergedArray(new_first, second_arr, size/2+1);
 		} else{
 			std::vector<int> new_first(first_arr.begin(),first_arr.begin()+size/2);
 			return MedianOfMergedArray(new_first, second_arr, size/2);
 		}
 	}

 	if(size % 2 == 0){
 		std::vector<int> new_second(second_arr.begin(), second_arr.begin()+size/2-1);
 		return MedianOfMergedArray(new_second, first_arr, size/2+1);
 	} else{
 		std::vector<int> new_second(second_arr.begin(), second_arr.begin()+size/2);
 		return MedianOfMergedArray(new_second, first_arr, size/2+1);
 	}

 }

