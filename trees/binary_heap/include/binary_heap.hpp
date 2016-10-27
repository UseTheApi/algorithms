//
//  binary_heap.hpp
//  algorithms. binary heap.
//
//  Created by alifar on 10/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>

template <class T>
class BinaryHeap{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	BinaryHeap(bool);
	bool max_heap; // true if MaxHeap
	T GetRoot();
	T RemoveRoot();
	void Insert(T); // pushes new item into a Heap
	void RemoveAt(size_t); // emove at index
	void Heapify(size_t);
	bool empty();
	size_t size();
	size_t get_parent_index(size_t);
	size_t get_left_child_index(size_t);
	size_t get_right_child_index(size_t);

	iterator begin() { return &heap_array_[0]; };
	const_iterator begin() const { return &heap_array_[0]; };
	iterator end() { return &heap_array_[size_]; };
	const_iterator end() const { return &heap_array_[size_]; };
private:
	std::vector<T> heap_array_;
	size_t size_;
	void decrease_key(size_t); // set key at given index to INT_MIN
	void increase_key(size_t); // set key at given index to INT_MAX
	void sift_up(size_t);
};
