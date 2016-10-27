//
//  main.cpp
//  binary heap.
//
//  Created by alifar on 10/27/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "binary_heap.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(int argc, const char *argv[]){
	cout << "Binary Heap implementation." << endl;
	bool heap_type = false; // true if Heap is MaxHeap
	char input;
	cout << "Type of Heap? [default: MinHeap, 1 for MaxHeap]: ";
	if(cin.get() != '\n'){
		heap_type = true;
	} 

	cout << endl;

	BinaryHeap<int> heap;
	heap.max_heap = heap_type;
	cout << "Insert items into Heap: ";
	int item;
	do{
		cin >> item;
		heap.Insert(item);
	} while(cin.get() != '\n');

	cout << "Heap: ";
	for(auto it: heap){
		cout << it << " ";
	}
	cout << endl;
	cout << "Removing Root." << endl;
	heap.RemoveRoot();
	cout << "Heap: ";
	for(auto it: heap){
		cout << it << " ";
	}
	cout << endl;
	cout << "Enter an index to remove: ";
	int index;
	cin >> index;
	heap.RemoveAt(index);
	cout << "Heap: ";
	for(auto it: heap){
		cout << it << " ";
	}
	cout << endl;
}
