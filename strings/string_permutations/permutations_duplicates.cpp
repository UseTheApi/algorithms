//
//  permutations_duplicates.cpp
//  algorithms
//
//  Created by alifar on 8/20/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "permutations.hpp"

/*
 Write a program to print all permutations of a given string.
                        ABC
            ABC         BAC         CBA
        ABC    ACB   BAC  BCA    CBA   CAB
*/

using namespace std;

void swap(char &ch1, char &ch2){
    char tmp = ch1;
    ch1 = ch2;
    ch2 = tmp;
}

void permute_with_duplicates(string &str, int start, int end){
    if(start == end){
        cout << str << endl;
    }
    for(int i = start; i <= end; ++i){
        swap(str[start], str[i]);
        permute_with_duplicates(str, start+1, end);
        swap(str[start], str[i]);
    }
}
