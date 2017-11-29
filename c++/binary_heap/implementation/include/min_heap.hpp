//
//  min_heap.hpp
//  algorithms. Binary Min Heap. Implementation
//
//  Created by alifar on 11/27/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include <vector>
#include <iostream>

void swap(int &el1, int &el2){
  el2 = el1^el2;
  el1 = el2^el1;
  el2 ^= el1;
}

class MinHeap{
/*
Min Heap represent a Binary Heap with Condition:
  * Each node in a tree has a key which is greater than or equal to the key of its parent.
Elements of Heap are stored in array
*/
public:
  int parent_index(int i){ return (i-1)/2 < heap_array_.size() ? (i-1)/2 : -1; };
  int left_child_index(int i){ return (2*i)+1 < heap_array_.size() ? (2*i) : -1; };
  int right_child_index(int i){ return (2*i)+2 < heap_array_.size() ? (2*i)+1 : -1; };
  void sift_up(int);
  void Insert(int);
  int GetMin();
  void PopMin();
  void Heapify(int);
  friend std::ostream & operator<<(std::ostream &, const MinHeap &);
private:
  std::vector<int> heap_array_;
};

void MinHeap::sift_up(int index){
  /*
  Balance function for Heap.
  A node is copmaired to its parent
  and swapped if Heap condition is violated.
  */
  int parent_i;
  while(index){
    parent_i = parent_index(index);
    if(heap_array_[parent_i] > heap_array_[index]){
      swap(heap_array_[parent_i], heap_array_[index]);
    }
    index = parent_i;
  }
}

void MinHeap::Insert(int new_data){
  /*
  Inserting new_data into the tail of array
  and perform sift_up operation.
  */
  if(heap_array_.empty()){
    heap_array_.push_back(new_data);
    return;
  }
  heap_array_.push_back(new_data);
  sift_up(heap_array_.size()-1);
}

int MinHeap::GetMin(){
  return heap_array_.empty() ? -1 : heap_array_[0];
}

std::ostream & operator<<(std::ostream &os, const MinHeap &heap){
  for(auto it: heap.heap_array_){
    os << it << " ";
  }
  return os;
}

void MinHeap::PopMin(){
  /*
  swap first and last elements of the array.
  remove last element
  perform balance of the Heap with Heapify operation from the root
  */
  swap(heap_array_[0], heap_array_[heap_array_.size()-1]);
  int popped = heap_array_.back();
  heap_array_.pop_back();
  Heapify(0);
}

void MinHeap::Heapify(int index){
  /*
  Compare parent of a Heap to it's right and left child.
  Choosing element for a parent position based on Heap Condition.
  swap and recuirse
  */
  int left_child_i = left_child_index(index);
  int right_child_i = right_child_index(index);
  if(left_child_i == -1){
    return;
  }
  if(right_child_i == -1){
    if(heap_array_[index] > heap_array_[left_child_i]){
      swap(heap_array_[index], heap_array_[left_child_i]);
    }
    return;
  }
  if(heap_array_[index] > heap_array_[left_child_i] && heap_array_[left_child_i] < heap_array_[right_child_i]){
    swap(heap_array_[index], heap_array_[left_child_i]);
    index = left_child_i;
  } else if(heap_array_[index] > heap_array_[right_child_i] && heap_array_[right_child_i] < heap_array_[left_child_i]){
    swap(heap_array_[index], heap_array_[right_child_i]);
    index = right_child_i;
  } else{
    return;
  }
  Heapify(index);
}
