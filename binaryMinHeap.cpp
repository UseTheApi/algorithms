//
//  binaryMinHeap.cpp
//  algorithms
//
//  Created by alifar on 7/5/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "binaryMinHeap.hpp"
#include <iostream>

using std::cout;

BinaryMinHeap::BinaryMinHeap(){};

void BinaryMinHeap::print(){
    for(auto it: heap_array_){
        cout << it << " ";
    }
    cout << std::endl;
}

size_t BinaryMinHeap::size(){
    return heap_array_.size();
}

size_t BinaryMinHeap::get_parent_index(size_t index){
    size_t parent_index = (index - 1)/2;
    return parent_index < (size() - 1) ? parent_index : -1;
}

size_t BinaryMinHeap::get_left_child_index(size_t index){
    size_t left_child_index = index*2 + 1;
    return left_child_index < (size() - 1) ? left_child_index: -1;
}

size_t BinaryMinHeap::get_right_child_index(size_t index){
    size_t right_child_index = index*2 + 2;
    return right_child_index < (size() - 1) ? right_child_index: -1;
}

void BinaryMinHeap::swap(int &parent, int &child){
    int tmp = parent;
    parent = child;
    child = tmp;
}

void BinaryMinHeap::SiftUp(size_t index){
    size_t parent_index;
    while(index != 0){
        parent_index = get_parent_index(index);
        if(heap_array_[parent_index] > heap_array_[index])
            swap(heap_array_[parent_index], heap_array_[index]);
        index = parent_index;
    }
}

void BinaryMinHeap::Insert(int new_data){
    heap_array_.push_back(new_data);
    size_t new_data_index = size() - 1;
    SiftUp(new_data_index);
}

int BinaryMinHeap::GetMin(){
    return heap_array_[0];
}

void BinaryMinHeap::DecreaseKey(size_t index){
    heap_array_[index] = INT32_MIN;
    while(index != 0 && heap_array_[get_parent_index(index)] > heap_array_[index]){
        swap(heap_array_[get_parent_index(index)], heap_array_[index]);
        index = get_parent_index(index);
    }
}

void BinaryMinHeap::Heapify(size_t index){
    size_t min_value_index = index;
    size_t left_child_index = index;
    size_t right_child_index = index;
    while(index == 0 || heap_array_[get_parent_index(index)] > heap_array_[index]){
         left_child_index = get_left_child_index(index);
         right_child_index = get_right_child_index(index);
        if(left_child_index < size()-1 && heap_array_[left_child_index] < heap_array_[right_child_index])
            min_value_index = left_child_index;
        if(right_child_index < size()-1 && heap_array_[right_child_index] < heap_array_[min_value_index])
            min_value_index = right_child_index;
        if(min_value_index != index){
            swap(heap_array_[min_value_index], heap_array_[index]);
            index = min_value_index;
        }
    }
}

int BinaryMinHeap::RemoveMin(){
    if(size() <= 0) return INT32_MAX;
    int min_value = heap_array_[0];
    heap_array_[0] = heap_array_[size() - 1];
    heap_array_.pop_back();
    Heapify(0);
    return min_value;
}

void BinaryMinHeap::RemoveAt(size_t index){
    if(index > size() - 1) return;
    DecreaseKey(index);
    RemoveMin();
}
