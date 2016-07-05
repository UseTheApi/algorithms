# algorithms
This repo contains most common algorithms and DS implementations
Current list:
  1. **Stack implemented with Linked List** : stackUsingLinkedList.hpp
  2. **Queue implemented with Linked List** : queueUsingLinkedList.hpp
  3. **Stack implemented from a Queue** : stackUsingQueue.hpp
  4. **Queue implemented from a Stack** : queueUsingStack.hpp
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
  6. **Heap** *TBD*
  7. **AVL tree balancing** *TBD*
  8. **Red-Black tree** *TBD*
  9. **Dynamic Programming**
    1. Factorial and Fibonacci : factorial_fibonacci.hpp
    2. Binomial Coefficients : binomialCoefficients.hpp
    3. Jump Stairs task: hopSomeStairs.hpp
  
       >*A child is running up a staircase with n steps, and can hop either 1 step, 2 steps or 3 steps at a time.*
       >*Implement a method to count how many possible ways the child can run up the stairs.*
    4. Amount from given denominations: amountWithCoins.hpp
       
       > *Write a function that, given:*
          >  * *an amount of money*
          >  * *a list of coin denominations*

       > *computes the number of ways to make amount of money with coins of the available denominations.*
    4. Knapsack problem (1-0) : knapsackProblem.hpp
  10. **Sorting Algorithms** *TBD*
  11. **Interesting tasks**
    * Reverse a sentance : sentenceReverse.hpp
    
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
      
    * Multiplication in Array: productAllNumsExceptItself.hpp
    
      > Given an array of integrs. Write a function that will return array of products of all numbers in a given array except itslef.
        Ex: [3,2,4,1] => [2*4*1, 3*4*1, 3*2*1, 3*2*4] => [8, 12, 6, 24]
        
    * Prices in Stock: maxProfitInStock.hpp
      
      > Write an efficient function that takes stock_prices_yesterday and returns the best profit I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.
      
      > Ex: stock_prices_yesterday = [10, 7, 5, 8, 11, 9], then you'd buy for $5 and sell for $11 => answer is 6
      
    * Pascal's Triangle: pascalsTriangle.hpp
    
      > Given an index k, return the kth row of the Pascal's triangle.
        For example, given k = 3,
        Return [1,3,3,1].

