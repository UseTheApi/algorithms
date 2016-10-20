//
//  unpack_string.cpp
//  algorithms. strings.
//
//  Created by alifar on 10/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "unpack_string.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 You are given a string of kind: {abc}3xyz
 Write a function that will unpack a string and will return a result string that looks like: abcabcabcxyz

 Solution:
	Recursion used to implement a solution. The main idea is to keep track of curly brackets
	and recursively repeat everything inside

 Example:
  s = a{b{c}2d}3xt

        i
        | 
  s0 = a{b{c}2d}3xt
         i
         | 
  s0 = a{b{c}2d}3xt - calling recursively UnpackString and replacing s with the result

          i
          |
    s1 = b{c}2d}3xt 
           i
           |
    s1 = b{c}2d}3xt - calling recursively UnpackString and replacing s with the result

            i
            |
      s2 = c}2d}3xt
             i
             |
      s2 = c}2d}3xt - calling RepeatString:

      s2 = ccd}3xt -> retrun s2

    s1 = bccd}3xt etc...

  Note: An assumotion made the number of repeatitions will be only one digit, 
        but correcting an algorithm to work with many digits of repeatitions is not very hard and is not covered here.
        Also the string must be valid (each '{' should follow with '}' somewhere in a string and the number then)

*/

std::string RepeatString(std::string &str, int len, int num_of_repeatitions){
	std::string tmp = str.substr(0, len);
	std::string s = tmp;
	for(int i = 1; i < num_of_repeatitions; ++i){
		s += tmp;
	}
	return s;
}

std::string UnpackString(std::string &s){
	int cur_repeat_len = 0;
	int num_of_repeatitions = 0;
	for(int i = 1; i <= s.size(); ++i){
		if(s[i-1] == '{'){
			std::string tmp = s.substr(i);
			s.replace(i-1, s.size(), UnpackString(tmp));
		} else if(s[i-1] == '}'){
			num_of_repeatitions = atoi(&s[i]);
			cur_repeat_len = i-1;
			std::string repeat = RepeatString(s, cur_repeat_len, num_of_repeatitions);
			s.replace(0, i+1, repeat);
			return s;
		}
	}
	return s;
}
