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
  std::vector<int> sorted = array;
  /*
  selection sort: 5 2 1 7 4 9:
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
