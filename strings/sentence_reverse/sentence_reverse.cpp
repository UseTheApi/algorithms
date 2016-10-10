//
//  sentence_reverse.cpp
//  algorithms
//
//  Created by alifar on 6/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "sentence_reverse.hpp"

/*
 You are given an array of characters arr, which consists of sequences of characters (words) separated by space characters.
 How can you most efficiently reverse the order of words in the sentence?
 For example:
 [ 'p', 'e', 'r', 'f', 'e', 'c', 't', '  ', 'm', 'a', 'k', 'e', 's', '  ', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e' ]
 
 would turn into:
 [ 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', '  ', 'm', 'a', 'k', 'e', 's', '  ', 'p', 'e', 'r', 'f', 'e', 'c', 't' ]
 
 Solution:
 
 1. Reverse whole string
 2. Iterate through array to find start and end of the world
 3. Reverse each word in the array
*/

void reverse(std::vector<char> &array, int start, int end){
    
    for(; start < end; ++start, --end){
        if(start == end){
            break;
        }
        array[start] = array[start]^array[end];
        array[end] = array[start]^array[end];
        array[start] = array[start]^array[end];
    }
    // Reverse in place can be done using iterators which is not very suitable for this case:
    //
    // auto rit = array.rbegin();
    // auto it = array.begin();
    // for(; it < rit.base()-1; ++it, ++rit){
    //     if(it == rit.base()-1){
    //         break;
    //     }
    //     *it = *it^*rit;
    //     *rit = *it^*rit;
    //     *it = *it^*rit;
    // }
}

void ReverseWords(std::vector<char> &arr){
    int length = arr.size();
    reverse(arr, 0, length-1); // reverse the whole string
    int wordStart = 0;
    
    for(int i = 0; i < length; ++i){
        if(arr[i] == ' ' && wordStart == i){ // ignoring multiple spaces in the string
            ++wordStart;
        } else if(arr[i] == ' '){
            reverse(arr, wordStart, i-1); // reverse each word back when collected a word
            wordStart = i+1;
        } else if(i == length-1){
            reverse(arr, wordStart, i); 
        }
    }
}
