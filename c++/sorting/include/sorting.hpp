//
//  sorting.hpp
//  algorithms. sorting. implementations
//
//  Created by alifar on 23/07/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <vector>
#include <iostream>
#include <queue>

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

std::vector<int> merge(std::vector<int> &array, int l_start, int l_end, int r_start, int r_end){
  /*
  Merge two sorted parts of array.
  keep comparing both parts until one is empty.
  then adding what's left from available part.
  returning modificated array.
  merge sort: 5 2 1 7 4 9 split start
          /             \
      5 2 1           7 4 9
     /   \             /  \
  5 2     1          7 4   9
  / \    /           / \    \
  5 2   1           7  4    9 split done. merge start
  \ /   /           \ /     \
  2 5  1            4 7     9
    \ /               \    /
  1 2 5              4 7 9
        \           /
        1 2 4 5 7 9 merge done
  */
  std::vector<int> result = array;
  int l_i = l_start;
  int r_i = r_start;
  int i = l_start;
  while(l_i <= l_end && r_i <= r_end){
    // comparing elements in both parts
    if(result[l_i] < result[r_i]){
      array[i] = result[l_i];
      l_i++;
    } else{
      array[i] = result[r_i];
      r_i++;
    }
    i++;
  }
  while(l_i <= l_end){
    // add what's left in left part
    array[i] = result[l_i];
    l_i++; i++;
  }
  while(r_i <= r_end){
    // add what's left in right part
    array[i] = result[r_i];
    r_i++; i++;
  }
  return array;
}

std::vector<int> merge_sort_helper(std::vector<int> &array, int begin, int last){
  /*
  Split array in parts and merge sorted.
  Split happens around middle element that is calculating on each revursive call.
  merge happens in bottom-up manner.
  */
  if(begin >= last){
    return array;
  }
  int middle = (last+begin)/2;

  merge_sort_helper(array, begin, middle);
  merge_sort_helper(array, middle+1, last);

  return merge(array, begin, middle, middle+1, last);
}

std::vector<int> merge_sort(const std::vector<int> &array){
  // wrapper for recuirsive sort.
  std::vector<int> result = array;
  return merge_sort_helper(result, 0, array.size()-1);
}

struct compare{
  /*
  Comparator struct for standard priority queue to support MinHeap.
  */
  bool operator()(const int &l, const int &r){
    return l > r;
  }
};

std::vector<int> heap_sort(const std::vector<int> &array){
  /*
  Heap Sort is done through adding all items from given array into a MinHeap.
  Then Extracting Min from MinHeap one by one and replacing items in result sorted array.
  */
  std::vector<int> result = array;
  std::priority_queue<int, std::vector<int>, compare> heap;
  for(auto it: result){
    heap.push(it);
  }
  for(int i=0; i < result.size(); ++i){
    result[i] = heap.top();
    heap.pop();
  }
  return result;
}
