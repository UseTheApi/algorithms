//
//  substr_with_k_chars.cpp
//  algorithms
//
//  Created by alifar on 8/22/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "substr_with_k_chars.hpp"
#include <algorithm>
#include <unordered_map>
#include <utility>

/*
 1. Task
 	Given a string, find the length of the longest substring consisting of a single character.
*/

using namespace std;

int max_length_one_char(string str){
	// string: abcaaaccb -> 3 (aaa)
	int tmp_sum = 1;
	int result_sum = 1;
	for(int i = 1; i < str.size(); ++i){
		if(str[i-1] == str[i]){
			++tmp_sum;
		} else{
			tmp_sum = 1;
		}
		result_sum = max(tmp_sum, result_sum);
	}
	return result_sum;
}

typedef pair<char, int> CharPair;
struct CompareSecond
{
	bool operator()(const CharPair &left, const CharPair &right) const {
		return left.second < right.second;
	}
};

pair<char,int> get_min(unordered_map<char, int> char_map){
	pair<char, int> min_item = *min_element(char_map.begin(), char_map.end(), CompareSecond());
	return min_item;
} 

int max_length_k_distinct_chars(string str, int k){
	/*
	 Ex.: k = 2, string = abcaaaccb -> 6(caaacc)

	 map: {{'a': 0}, {'b': 1}} -> {{'b': 1}, {'c': 2}} -> {{'c': 2}, {'a': 3}} ->...-> {{'c': 8}, {'a': 6}}
	*/

	int result_sum = 0;
	int start = 0;

	unordered_map<char, int> char_map;

	for(int i = 0; i < str.size(); ++i){
		if(char_map.size() == k && !char_map.count(str[i])){	
			pair <char, int> min_el = get_min(char_map);
			char_map.erase(min_el.first);
			start = min_el.second+1;
		}
		result_sum = max(result_sum, i - start+1);
		char_map[str[i]] = i;
	 }
	 return result_sum;
}
