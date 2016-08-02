//
//  substrings.cpp
//  algorithms
//
//  Created by alifar on 8/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "substrings.hpp"

std::vector<std::string> * find_all_substrings(const std::string & str){
	std::vector<std::string> *result = new std::vector<std::string>();
	std::string temp;
	for(auto it = str.begin(); it != str.end(); ++it){
		int x = 0;
		while(it+x != str.end()){
			for(int i = 0; i <= x; ++i){
				temp += *(it+i);
			}
			result->push_back(temp);
			temp.clear();
			++x;
		}
	}
	return result;
}