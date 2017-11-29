//
//  main.cpp
//  algorithms. Binary Min Heap. Implementation
//
//  Created by alifar on 11/27/17.
//  Copyright © 2017 alifar. All rights reserved.
//

#include "min_heap.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(int argc, const char *argv[]){
	cout << "== Binary Min Heap ==" << endl;

	MinHeap heap;
	cout << "Insert items into Heap: ";
	int item;
	do{
		cin >> item;
		heap.Insert(item);
	} while(cin.get() != '\n');

	cout << "Heap: " << heap << " GetMin: " << heap.GetMin() << std::endl;
	cout << endl;
	cout << "Removing Root." << endl;
	heap.PopMin();
  cout << "Heap: " << heap << " GetMin: " << heap.GetMin() << std::endl;
}
