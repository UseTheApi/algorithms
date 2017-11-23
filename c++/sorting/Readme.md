# Sorting

Sorting is one of the main basic areas of Algorithms.

Sorting Algorithms implemented:

  * **Selection Sort**

### Selection Sort

Selection sort is the most conceptually simple of all the sorting algorithms. It works by selecting the smallest (or largest, if you want to sort from big to small) element of the array and placing it at the head of the array. Then the process is repeated for the remainder of the array; the next largest element is selected and put into the next slot, and so on down the line. [(c)](https://www.cprogramming.com/tutorial/computersciencetheory/sorting2.html)

**Time Complexity**: ```O(n)``` **Space Complexity**: ```O(1)```

## Sorting Algorithms Comparison
##### http://bigocheatsheet.com/
<img src="/static/sort_algo_compared.png" width="600">

#### Notes
Sorting Algorithms are implemented in ```include/sorting.hpp``` source file. ```make``` helps generate main and test binaries to run tests or interactive main program.

#### Targets:
  * ```make build```
  * ```make run```
  * ```make test```
  * ```make clean```
