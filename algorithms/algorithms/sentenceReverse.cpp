//
//  sentenceReverse.cpp
//  algorithms
//
//  Created by alifar on 6/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <iostream>
#include "sentenceReverse.hpp"

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

void reverseString(char *arr, int start, int end){
    char tmp = 0;
    
    while(start<end){
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}

void reverseWords(char *arr, int length){
    reverseString(arr, 0, length-1); // reverse the whole string
    int wordStart = 0;
    for(int i=0; i<=length-1; ++i){
        if(arr[i] == ' '){
            if(wordStart){
                reverseString(arr, wordStart, i-1); // revers each word back when collected a word
                wordStart = NULL;
            }
        } else if(i == length-1){
            if(wordStart){
                reverseString(arr, wordStart, i);
                wordStart = NULL;
            }
        } else if(wordStart == 0) {
            wordStart = i;
        }
    }
}
