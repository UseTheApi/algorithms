# algorithms
This repo contains most common algorithms and DS implementations. To execute implemented tasks please follow the instructions in wiki of this repo and ```main.cpp``` file.
Current list:
  1. **Stack implemented with Linked List** : stackUsingLinkedList.hpp
  2. **Queue implemented with Linked List** : queueUsingLinkedList.hpp
  3. **Stack implemented from a Queue** : stackUsingQueue.hpp
  4. **Queue implemented from a Stack** : queueUsingStack.hpp
  5. **Special Stack with getMin() method** : special_stack/
  5. **Binary Search Tree**:
    1. Depth traversal (with and InOrder without recursion) : bstTraversals.hpp
      * Pre-, In-, Post-order traversals using recursion
      * In-order traversal using Stack
      * In-order traversal without recursion or Stack - Morris traversal
    2. Breadth traversal (using queue) : bstTraversals.hpp
    3. Breadth traversal (using height of the tree) : bstTraversals.hpp
    3. Search and findMin (for tree nad a subtree) : binarySearchTree.hpp
    4. Insertion and Deletion : binarySearchTree.hpp
    5. In-order Successor (2 methods) : bstInorderSuccessor.hpp
    6. Non-related nodes in BST: nonRelativeNodes.hpp
      
      > Given a pointer to the root of BST. Write a function that will return the max set of nodes that are not children or parents for each other.
    7. Determine if two trees are equal: equalTrees.hpp
    8. Lower Common Ancestor for two nodes in BST: lowerCommonAncestor.hpp (2 methods)
    9. 2nd Largest Node in BST: *TBD*
  6. **Heap** - Binary Min Heap: binaryMinHeap.hpp
  7. **AVL tree balancing** *TBD*
  8. **Red-Black tree** *TBD*
  9. **Binary Search** - set of tasks: binary_search/
  10. **Bit Manipulations**:
    1. max_without_comparison/
    2. bits_in_integer/
  10. **Graphs**: graphs/
    1. Warshall's Algorithm: warshall_floyd_algorithm/
      
      > Build a Reachability Matrix for a given Adjacency Matrix.

    2. Floyd's Algorithm: warshall_floyd_algorithm/
    
      > Build a Reachibility Matrix for a weighted graph Adjacency Matrix.
      
    3. Graph Representations: representations/
      1. Adjacency matrix: adjacency_matrix/
      2. Adjacency List: *TBD*

  9. **Dynamic Programming**: dynamic_programming/
    1. Factorial and Fibonacci : factorial_fibonacci/
    2. Binomial Coefficient : binomial_coefficient/
    3. Jump Stairs task: stairs_hopper/
  
       >*A child is running up a staircase with n steps, and can hop either 1 step, 2 steps or 3 steps at a time.*
       >*Implement a method to count how many possible ways the child can run up the stairs.*
    4. Amount from given denominations: amount_with_coins/
       
       > *Write a function that, given:*
          >  * *an amount of money*
          >  * *a list of coin denominations*

       > *computes the number of ways to make amount of money with coins of the available denominations.*
    4. Knapsack problem (1-0) : knapsack_problem/
    5. Max Wealth problem : max_wealth_dp/
        
      > *Given Matrix of integers representing kg of gold at every mine.*
      > *Write a function that will calculate the max welth that can be made.*
      > *Acceptable moves are only __right__ or __down__ .*
      
    6. Number of words: alphabetic_numbers/ - solution created can work with any inputs (0 in number)
        
      > *Given an mapped alphabet A=1, B=2, C=3 ...Z=26.*
      > *Calculate how many words can you form from a given number.*
      
    7. Find min for every window of given size in array : min_or_max_for_window/
      
      > *Given an array: [1, -2, 5, 3, 4, 6, 8, 10], window_size = 3.*
      > *Output is [-2 -2 3 3 4 6 ].*
      
      > *This task can also be solved using __dequeue__, but found elegant DP solution.*
      
  10. **Sorting Algorithms** : sorting/
  11. **Arrays**: arrays/
    * Prices in Stock: stock_prices/
      
      > Write an efficient function that takes stock_prices_yesterday and returns the best profit I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.
      
      > Ex: stock_prices_yesterday = [10, 7, 5, 8, 11, 9], answer is 6
      
    * Pairs: pairs/
    
      > Given N integers, count the number of pairs of integers whose difference is K.
      
    * Multiplication in Array: products_in_array/
    
      > Given an array of integrs. Write a function that will return array of products of all numbers in a given array except itslef.
        Ex: [3,2,4,1] => [8, 12, 6, 24]
        
    * Median in merged lists: merge_lists_median/
    
      > Given two sorted array. Write a function that returns a median of merged array. 
      > Both arrays are of the same size
      
    * Longest non-decreasing interval: non_decreasing_interval/
    
      > Given an array of intergers. Write a funtion that returns an array of max length 
      > with non-decreasing elements from a given array
      
    * Smallest subarray with sum greater than a given value: shortest_subarray_sum/
    
      > Given Array:
      ```c++
      arr = [1, 4, 45, 6, 0, 19, 39]
      ```
      > given number: num = 51 output -> length of shortest subarray with sum of elements > num.
      
    * Find max subarray sum (Kadane's Algorithm) : *TBD*
      
      > *With variation of this task: Find a subarray with max sum of elements*

  12. **Strings**:
    * Substrings: substrings/
    
      > Given a string. Write a function to return all substrings for a given string.
      
    * All string permutations(without duplicates): string_permutations/
    * All string permutations(with duplicates): *TBD*
    * Single Char String: substring_with_k_chars/
      
      > Given a string, find the length of the longest substring consisting of a single character.
    
    * K distinct Chars String: substring_with_k_chars/
      
      > Find the length of the longest substring consisting of at most k distinct characters.
    
  11. **Interesting tasks**
    * Reverse a sentence : sentenceReverse.hpp
    
      > You are given an array of characters arr, which consists of sequences of characters (words) separated by space characters.
      > How can you most efficiently reverse the order of words in the sentence?
      > For example:
      ```c++
      [ 'p', 'e', 'r', 'f', 'e', 'c', 't', '  ', 'm', 'a', 'k', 'e', 's', '  ', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e' ]
      would turn into:
      [ 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', '  ', 'm', 'a', 'k', 'e', 's', '  ', 'p', 'e', 'r', 'f', 'e', 'c', 't' ]
      ```
    * Drone Flight Planning : droneFlightPlanner.hpp
    
      > You are planning the amount of fuel need to complete a drone flight.
      > To fly higher, the drone burns 1 liter of fuel per feet. However, flying lower charges the drone with the amount of energy equivalent to 1 liter of fuel for every feet. Flying sideways takes no energy (only flying up and down takes/charges energy).
 
      > Given an array of 3D coordinates named route, find the minimal amount of fuel the drone would need to fly through this route.
      > Explain and code the most efficient solution possible, with the minimal number of actions and variables.
 
      > Example:
      > Completing the route [{x:0, y:2, z:10}, {x:3, y:5, z:0}, {x:9, y:20, z:6}, {x:10, y:12, z:15}, {x:10, y:10, z:8}] requires a minimum of 5 liters of fuel.
      
    * Pascal's Triangle: pascalsTriangle.hpp
    
      > Given an index k, return the kth row of the Pascal's triangle.
      
    * Find and Remove loop in Linked List: detect_remove_loop_linked_list/
      
