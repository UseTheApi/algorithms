# Binary Min Heap Implementation

# Task
Binary Min Heap is a Binary Heap with a condition:
###### Each node in a tree has a key which is greater than or equal to the key of its parent.

Implement a Data Structure that respond to this condition and write methods ```Insert()```, ```GetMin()```, ```PopMin()```.

#### Notes

This implementation contains a ```class``` MinHeap with implemented methods ```Insert()```, ```GetMin()```, ```PopMin()```.

Balancing of a heap is implemented with ```sift_up``` and ```Heapify``` operations:

  1. ```sift_up``` operation implements comparison of an element at an ```index``` of array with it's parent (element at ```(index-1)/2``` of array). Following by performing a ```swap``` if Condition of a Heap was violated (```array[parent] > array[index]```)

  2. ```Heapify``` operation implements a comparison of an element of array at ```index``` to its **left** and **right** children. Minimal element is **swapped** with element at ```index```.

```make``` helps generate main and test binaries to run tests or interactive main program.

#### Targets:
  * ```make build```
  * ```make run```
  * ```make test```
  * ```make clean```
