//
//  binary_heap.hpp
//  algorithms. binary heap.
//
//  Created by alifar on 10/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>
#include <climits>
#include <iostream>

using std::size_t;

template <class T>
class BinaryHeap{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    BinaryHeap(){
        size_ = 0;
    };
    BinaryHeap(bool);
    bool max_heap; // true if MaxHeap
    T GetRoot();
    void RemoveRoot();
    void Insert(T); // pushes new item into a Heap
    void RemoveAt(size_t); // remove at index
    void Heapify(size_t);
    bool empty();
    size_t size();
    int get_parent_index(size_t);
    int get_left_child_index(size_t);
    int get_right_child_index(size_t);

    iterator begin() { return &heap_array_[0]; };
    const_iterator begin() const { return &heap_array_[0]; };
    iterator end() { return &heap_array_[size_]; };
    const_iterator end() const { return &heap_array_[size_]; };
private:
    std::vector<T> heap_array_;
    size_t size_;
    // void decrease_key(size_t); // set key at given index to INT_MIN
    // void increase_key(size_t); // set key at given index to INT_MAX
    void downgrade_key(size_t); // decreases or increases key depending on heap_property
    void sift_up(size_t);
    void swap(T &, T &);
    bool compare(T, T); // returns result of comparison depending on heap_property
    void assign_top_value(size_t); // assigns INT_MIN or INT_MAX depending on heap_property
};

template <class T>
BinaryHeap<T>::BinaryHeap(bool heap_property){
    max_heap = heap_property;
    size_ = 0;
}

template <class T>
bool BinaryHeap<T>::empty(){
    return heap_array_.empty();
}

template <class T>
size_t BinaryHeap<T>::size(){
    return size_;
}

template <class T>
int BinaryHeap<T>::get_parent_index(size_t index){
    size_t parent_index = (index - 1)/2;
    return parent_index < (size_) ? parent_index : -1;
}

template <class T>
int BinaryHeap<T>::get_left_child_index(size_t index){
    size_t left_child_index = index*2+1;
    return left_child_index < (size_) ? left_child_index : -1;
}

template <class T>
int BinaryHeap<T>::get_right_child_index(size_t index){
    size_t right_child_index = index*2+2;
    return right_child_index < (size_) ? right_child_index : -1;
}

template <class T>
T BinaryHeap<T>::GetRoot(){
    return heap_array_[0];
}

template <class T>
void BinaryHeap<T>::swap(T &item1, T &item2){
    T tmp = item1;
    item1 = item2;
    item2 = tmp;
}

template <class T>
bool BinaryHeap<T>::compare(T item1, T item2){
    if(max_heap){
        return item1 > item2;
    } else{
        return item1 < item2;
    }
}

template <class T>
void BinaryHeap<T>::sift_up(size_t index){
    int parent_index;
    while(index){
        parent_index = get_parent_index(index);
        if(compare(heap_array_[index], heap_array_[parent_index])){
            swap(heap_array_[index], heap_array_[parent_index]);
        }
        index = parent_index;
    }
}

template <class T>
void BinaryHeap<T>::assign_top_value(size_t index){
    if(max_heap){
        heap_array_[index] = INT_MAX;
    } else{
        heap_array_[index] = INT_MIN;
    }
}

template <class T>
void BinaryHeap<T>::downgrade_key(size_t index){
    assign_top_value(index);
    sift_up(index);
}

template <class T>
void BinaryHeap<T>::Insert(T new_data){
    ++size_;
    heap_array_.push_back(new_data);
    size_t new_index = size_ - 1;
    sift_up(new_index);
}

template <class T>
void BinaryHeap<T>::Heapify(size_t index){
    int index_of_min = index;
    int left_child_index, right_child_index;
    while(!index || compare(heap_array_[get_left_child_index(index)], heap_array_[index]) || compare(heap_array_[get_right_child_index(index)], heap_array_[index])){
        left_child_index = get_left_child_index(index);
        right_child_index = get_right_child_index(index);
        if(left_child_index > 0 && compare(heap_array_[left_child_index], heap_array_[index])){
            index_of_min = left_child_index;
        }
        if(right_child_index > 0 && compare(heap_array_[right_child_index], heap_array_[index_of_min])){
            index_of_min = right_child_index;
        }
        if(index_of_min != index){
            swap(heap_array_[index_of_min], heap_array_[index]);
            index = index_of_min;
        }
        if(left_child_index == -1 && right_child_index == -1){
            return;
        }
    }
}

template <class T>
void BinaryHeap<T>::RemoveRoot(){
    --size_;
    heap_array_[0] = heap_array_[size_];
    heap_array_.pop_back();
    Heapify(0);
}

template <class T>
void BinaryHeap<T>::RemoveAt(size_t index){
    if(index > size_-1 || index < 0){
        return;
    }
    downgrade_key(index);
    RemoveRoot();
}
