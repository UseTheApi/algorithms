//
//  main.cpp
//  algorithms
//
//  Created by alifar on 10/7/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "sentence_reverse.hpp"
#include <vector>
#include <iostream>

using namespace std;

// TEST: Reverse a sentance: sentecReverse.hpp
//    std::string array = "practice reverse words";
//    char arr[22];
//    std::strcpy(arr, array.c_str());
//    
//    reverseWords(arr, 23);
//    for(int i=0; i<23; ++i){
//        std::cout << arr[i];
//    }
//    std::cout << std::endl;

int main(int argc, const char *argv[]){
	// vector<char> str = {'a','b','c','d','e','f', ' ', 'w', 'd', 'a', 'e'};
	

	vector<char> str = {'e', 'v','e', 'r', 'y', ' ', ' ', 'd','a','y', ' ', 'i','s',' ', 'n', 'i', 'c', 'e'};
	ReverseWords(str);
	for(auto it: str){
		cout << it << " ";
	}
	cout << endl;

	// vector<int> s = {1, 2, 3, 4, 5};
	// vector<int> a(s.begin()+1, s.begin()+3);
	// for(auto it: a){
	// 	cout << it << " ";
	// }
	// cout << endl;
}