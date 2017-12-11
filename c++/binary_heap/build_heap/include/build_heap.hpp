//
//  build_heap.hpp
//  algorithms. Binary Min Heap. Build heap from array
//
//  Created by alifar on 12/07/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <vector>

/*
4 1 5 2 6 7 3 9

cur: 4; left: 1; right: 5; -> swap 1, 4; -> 1, 4, 5; 1 4 5 2 6 7 3 9
cur: 4; left: 2; right: 6; -> swap 2, 4; -> 2, 4, 6; 1 2 5 4 6 7 3 9
cur: 5; left: 7; right: 3; -> swap 3, 5; -> 3, 7, 5; 1 2 3 4 6 7 5 9
cur: 4; left: 9; right: -; -> no swap; -> done.

*/

void swap(int &el1, int &el2){
  /*
  Swap using XOR: no additional space used
  2^4 = 6
  6^2 = 4
  4^6 = 2
  */
  el1 ^= el2;
  el2 ^= el1;
  el1 ^= el2;
}

void build_min_heap(std::vector<int> &array, int cur_i=0){
  std::vector<int> result = array;
  int left_i = (2*cur_i)+1 < array.size() ? (2*cur_i)+1 : -1;
  int right_i = (2*cur_i)+2 < array.size() ? (2*cur_i)+2 : -1;
  if(left_i == -1){
    return result;
  }
  if(right_i == -1){
    if(array[right_i] < array[cur_i]){
      swap(array[right_i], array[cur_i]);
    }
    return;
  }
  if(array[left_i] < array[cur_i] && array[right_i] < array[left_i]){
    swap(array[cur_i], array[left_i]);
  } else if(array[right_i] < array[cur_i] && array[left_i] < array[right_i]){
    swap(array[cur_i], array[right_i]);
  }
  build_heap(array, cur_i+1)
}
