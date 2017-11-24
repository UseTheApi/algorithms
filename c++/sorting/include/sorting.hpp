//
//  sorting.hpp
//  algorithms. sorting. implementations
//
//  Created by alifar on 23/07/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <vector>

void swap(int &el1, int &el2){
  int tmp = el1;
  el1 = el2;
  el2 = el1;
}

std::vector<int> selection_sort(const std::vector<int> &array){
  /*
  selection sort: 5 2 1 7 4 9
  Starting from empty sorted (left) part of array.
  Looking for min element in unsorted (right) part.
  Do swap with current last element in sorted (left) part.
       |       Looking for min in array
   5 2 1 7 4 9
   |           Swap it with the first element, sorted part consist 1 element now
   1 2 5 7 4 9
     |         Looking for min in unsorted part of array
   1 2 5 7 4 9
           |
   1 2 7 5 4 9
       |
   1 2 4 5 7 9
  */
  std::vector<int> sorted = array;

  int min_i = 0;
  while(min_i < sorted.size()){
    int i_to_swap = min_i;
    for(int i = min_i; i < sorted.size(); ++i){
      if(sorted[i] < sorted[i_to_swap]){
        i_to_swap = i;
      }
    }
    std::swap(sorted[min_i], sorted[i_to_swap]);
    min_i++;
  }
  return sorted;
}

std::vector<int> insertion_sort(const std::vector<int> &array){
  /*
  insertion sort: 5 2 1 7 4 9
  Starting when sorted (left) part of array consists of 1 element (5).
  Taking first element from unsorted (right) part of array.
  Inserting it into correct place in the sorted (left) part of array.
  left | right
      |
  5 | 2 1 7 4 9
        |
  2 5 | 1 7 4 9
          |
  1 2 5 | 7 4 9
            |
  1 2 5 7 | 4 9
              |
  1 2 4 5 7 | 9

  1 2 4 5 7 9 | done.
  */

  std::vector<int> result = array;
  int left_i, key;
  for(int i = 1; i < result.size(); ++i){
    left_i = i - 1;
    key = result[i];
    while(left_i >= 0 && result[left_i] > key){
      result[left_i+1] = result[left_i];
      left_i--;
    }
    result[left_i+1] = key;
  }
  return result;
}
