//
//  binaryMinHeap.hpp
//  algorithms
//
//  Created by alifar on 7/5/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef binaryMinHeap_hpp
#define binaryMinHeap_hpp

#include <stdio.h>
#include <vector>

using std::size_t;

class BinaryMinHeap{
public:
    BinaryMinHeap();
    void print();
    int GetMin();
    int RemoveMin();
    void Insert(int); // insert a value
    void RemoveAt(size_t); // remove item at index
    void Heapify(size_t);
    size_t get_parent_index(size_t); // calculate parent index for given index
    size_t get_left_child_index(size_t);
    size_t get_right_child_index(size_t);
    size_t size();
private:
    std::vector<int> heap_array_;
    void SiftUp(size_t);
    void swap(int &, int &);
    void DecreaseKey(size_t); // decreasing value at given index to INT_MIN
};

#endif /* binaryMinHeap_hpp */
