//
//  binary_search.cpp
//  algorithms
//
//  Created by alifar on 7/8/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "binary_search.hpp"
#include <iostream>

/*
 Given a sorted arr[] of elements. Write a function to search a given element x in arr[]. Time complexity is O(logn)
*/

int BinarySearch(const std::vector<int> &array, int num){ // returns position of num in array
    int begin = 0;
    int end = static_cast<int>(array.size()) - 1;
    int middle;
    while(begin <= end){
        middle = (end+begin)/2;
        if(num == array[middle]){
            return middle;
        } else if(num > array[middle]){
            begin = middle+1;
        } else{
            end = middle-1;
        }
    }
    return -1;
}

/*
 Given a sorted arr[] of elements. Write a function that returns a floor value from arr for a given key
*/

int FloorIndex(const std::vector<int> &array, int key){
    // [4, 6, 8, 10], key=11?
    int begin = 0;
    int end = static_cast<int>(array.size());
    int middle;
    if(key < array[begin]){
        return -1; // no floor value in array
    }
    while(end-begin > 1){
        middle = begin + (end-begin)/2; // 1+(3-1)/2=2;  
        if(array[middle] <= key){ // 6 <= 11
            begin = middle; // begin=1, begin=2
        } else{
            end = middle; 
        }
    }
    return begin;
}

/*
 Given a sorted arr[] of elements with duplicates. Write a function that returns number of occurrances for a given key
*/

 int LeftPosition(const std::vector<int> &array, int key){
    int begin = 0;
    int end = static_cast<int>(array.size());
    int middle;
    while(end-begin > 1){
        middle = begin + (end-begin)/2;
        if(array[middle] <= key){
            begin = middle;
        } else{
            end = middle;
        }
    }
    return begin;
 }

int RightPosition(const std::vector<int> &array, int key){
    int begin = 0;
    int end = static_cast<int>(array.size());
    int middle;
    while(end-begin > 1){
        middle = begin + (end-begin)/2;
        if(array[middle] >= key){
            end = middle;
        } else{
            begin = middle;
        }
    }
    return end;
}

 int Occurrances(const std::vector<int> &array, int key){
    int left_postition = LeftPosition(array, key);
    int right_position = RightPosition(array, key);

    return (array[left_postition] == key && arr[right_position] == key) ? (right_position-left_position)+1 : 0;
 }

/*
 Given a sorted rounded array of elemnts. Write a function that returns a position of the begining of the array
*/

 int MinIndex(std::vector<int> &array){
    // [4, 5, 6, 1, 2, 3]; begin=0; end=5; middle=5/2=2
    int begin = 0;
    int end = array.size();
    int middle;
    if(array[begin] < array[end]){
        return begin;
    }
    while(end-begin > 1){
        if(begin == end){
            return begin;
        }
        middle = begin + (end-begin)/2;
        if(array[middle] < array[end]){
            end = middle;
        } else{
            begin = middle+1;
        }
    }
    return -1;
 }



