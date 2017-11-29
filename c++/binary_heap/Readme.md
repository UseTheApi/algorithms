# Binary Heap

**[source](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Binary%20Heaps/heaps.html)**

A **binary heap** is a complete binary tree which satisfies the heap ordering property. The ordering can be one of two types:

* the **_min-heap_** property: the value of each node is greater than or equal to the value of its parent, with the minimum-value element at the root.
* the **_max-heap_** property: the value of each node is less than or equal to the value of its parent, with the maximum-value element at the root.

![binary_heap](/static/heap.bmp)

Elements of Binary Heap are stored in ```array```.

For each ```i``` as index of array:
  * ```left_child_index``` = 2*i + 1;
  * ```right_child_index``` = 2*i + 2;
  * ```parent``` = (i - 1)/2;

Balancing of Binary Heap is done by performing ```sift_up``` operation on each ```Insert``` and ```Heapify``` operation on each ```PopMin``` or ```PopMax```.
