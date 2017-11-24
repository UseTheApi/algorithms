# Sorting

Sorting is one of the main basic areas of Algorithms.

Sorting Algorithms implemented:

  * **Selection Sort**

### Selection Sort

Selection sort is the most conceptually simple of all the sorting algorithms. It works by selecting the smallest (or largest, if you want to sort from big to small) element of the array and placing it at the head of the array. Then the process is repeated for the remainder of the array; the next largest element is selected and put into the next slot, and so on down the line. [(c)](https://www.cprogramming.com/tutorial/computersciencetheory/sorting2.html)

**Time Complexity**: ```O(n^2)``` **Space Complexity**: ```O(1)```

### Insertion Sort

Insertion Sort inserts each element of the array into its proper position, leaving progressively larger stretches of the array sorted. What this means in practice is that the sort iterates down an array, and the part of the array already covered is in order; then, the current element of the array is inserted into the proper position at the head of the array, and the rest of the elements are moved down, using the space just vacated by the element inserted as the final space. [(c)](https://www.cprogramming.com/tutorial/computersciencetheory/sorting2.html)

**Time Complexity**: ```O(n^2)``` **Space Complexity**: ```O(1)```

*Insertion Sort* shows better performance then *Selection Sort*.

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
