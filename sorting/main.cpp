//
//  main.cpp
//  algorithms
//
//  Created by alifar on 8/7/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"

void print_array(const std::vector<int> &array){
	for(auto it: array){
		std::cout << it << " ";
	}
	std::cout << std::endl;
}

void selection_sort_run(){
	std::cout << "Given array: ";
	std::vector<int> arr = {5, 3, 6, 1, 7};

	print_array(arr);

	selection_sort(arr);

	std::cout << "Result of Selection Sort: ";
	print_array(arr);
}

void insertion_sort_run(){
	std::cout << "Given array: ";
	std::vector<int> arr = {5, 3, 6, 1, 7};

	print_array(arr);

	insertion_sort(arr);

	std::cout << "Result of Insertion Sort: ";
	print_array(arr);
}

void merge_sort_run(){
	std::cout << "Given array: ";
	std::vector<int> arr = {5, 3, 6, 1, 7};

	print_array(arr);

	merge_sort(arr);

	std::cout << "Result of Merge Sort: ";
	print_array(arr);
}

int main(int argc, const char *argv[]){
	selection_sort_run();

	insertion_sort_run();

	merge_sort_run();
}