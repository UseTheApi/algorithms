//
//  main.cpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/* In order to run one of the tests including of appropriate .hpp file is required 
   ex. : #include "factorial_fibonacci.hpp" then comment out section marked TEST: Fibonacci and Factorial DP */


int main(int argc, const char * argv[]) {

// TEST: Binary Search: binary_search.hpp
//    std::vector<int> arr = {1, 3, 6, 8, 10, 15, 20, 21, 23, 45, 47};
//    std::cout << BinarySearch(arr, 15) << std::endl;
//    std::cout << BinarySearch(arr, 1) << std::endl;
//    std::cout << BinarySearch(arr, 55) << std::endl;
    
// TEST: Count distinct absolute numbers in array: countElementsInArray.hpp
//    std::vector<int> numbers = {-3, -2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 3};
//    std::cout << noDistinctValues(numbers) << std::endl;
    
// TEST: Min Binary Heap: "binaryMinHeap.hpp"
//    BinaryMinHeap *heap = new BinaryMinHeap();
//    heap->Insert(4);
//    heap->Insert(6);
//    heap->Insert(3);
//    heap->Insert(2);
//    heap->Insert(7);
//    heap->Insert(5);
//    heap->Insert(1);
//    std::cout << "Initial Heap:" << std::endl;
//    heap->print();
//    std::cout << "Current Minimal element: ";
//    std::cout << heap->GetMin() << std::endl;
//    std::cout << "Extract Min: " << heap->RemoveMin() << std::endl;
//    std::cout << "Heap:" << std::endl;
//    heap->print();
//    size_t index_to_remove = 3;
//    std::cout << "Remove element at postition: " << index_to_remove << std::endl;
//    heap->RemoveAt(3);
//    heap->print();


// TEST: Max Stock Profit: maxProfitInStock.hpp
//    std::vector<int> prices = {10, 7, 11, 5, 8, 9};
//    std::cout << maxStockProfit(prices) << std::endl;

// TEST: Product of all numbers in array except itself: productAllNumsExceptItself.hpp
//    const std::vector<int> numbers = {3,2,4,1,5};
//    std::cout << numbers.size() << std::endl;
//    std::vector<int> result1 = productOfAllNumExceptItself(numbers);
//    std::cout << "Brute Force: " << std::endl;
//    for(auto it: result1){
//        std::cout << it << " ";
//    }
//    std::cout << std::endl;
//    std::vector<int> result2 = productOfAllNyumbersExceptItselfLinear(numbers);
//    std::cout << "Linear complexity: " << std::endl;
//    for(auto it: result2){
//        std::cout << it << " ";
//    }
//    std::cout << std::endl;

// TEST: Lowest Common Ancestor: lowestCommonAncestor.hpp
//    Lca *tree = new Lca();
//    tree->setRoot(tree->insert(tree->getRoot(), 6));
//    tree->setRoot(tree->insert(tree->getRoot(), 7));
//    tree->setRoot(tree->insert(tree->getRoot(), 10));
//    tree->setRoot(tree->insert(tree->getRoot(), 3));
//    tree->setRoot(tree->insert(tree->getRoot(), 4));
//    tree->setRoot(tree->insert(tree->getRoot(), 5));
//    tree->setRoot(tree->insert(tree->getRoot(), 2));
//    
//    BstNodeWithParent *n1 = tree->search(tree->getRoot(), 2);
//    BstNodeWithParent *n2 = tree->search(tree->getRoot(), 5);
//    
//    std::cout << tree->lowestCommonAncesrotRoot(tree->getRoot(), n1, n2)->data << std::endl;
//    std::cout << tree->lowestCommonAncestorParent(n1, n2)->data << std::endl;
   
// TEST: check if trees are equal: equalTree.hpp (+ binarySearchTree.hpp)
//    Bst *tree1 = new Bst();
//    Bst *tree2 = new Bst();
//    tree1->insert(7);
//    tree1->insert(9);
//    tree1->insert(8);
//    tree1->insert(5);
//    tree1->insert(6);
//    
//    tree2->insert(7);
//    tree2->insert(9);
//    tree2->insert(8);
//    tree2->insert(5);
//    tree2->insert(6);
//    
//    std::cout << equalTrees(tree1->getRoot(), tree2->getRoot()) << std::endl; // cout 1 if true, 0 if false
    
// TEST: calculate the longest list of non-related nodes: nonRelativeNodes.hpp (+ binarySearchTree.hpp)
//    Bst *tree = new Bst();
//    tree->insert(7);
//    tree->insert(5);
//    tree->insert(10);
//    tree->insert(6);
//    tree->insert(3);
//    tree->insert(4);
//    tree->insert(1);
//    tree->insert(8);
//    tree->insert(11);
//    tree->insert(9);
//    tree->insert(12);
//    
//    std::vector<Tnode *> non_related_nodes = nonRelativeNodes(tree->getRoot());
//    for(auto it: non_related_nodes){
//        std::cout << it->data << " "; // 10 5 12 9 4 1
//    }
//    std::cout << std::endl;

// TEST: In Order Successor in BST: bstInorderSuccessor.hpp
//    bstSuccessor *tree = new bstSuccessor();
//    tree->setRoot(tree->insert(tree->getRoot(), 5));
//    tree->setRoot(tree->insert(tree->getRoot(), 7));
//    tree->setRoot(tree->insert(tree->getRoot(), 10));
//    tree->setRoot(tree->insert(tree->getRoot(), 3));
//    tree->setRoot(tree->insert(tree->getRoot(), 4));
//    BstNodeWithParent *temp = tree->getRoot()->left->right;
//    std::cout << tree->findSuccessorByParent(temp)->data << std::endl;
//    std::cout << tree->findSuccessorByRoot(tree->getRoot(), temp)->data << std::endl;

// TEST: Drone Flight Planning. both solutions: droneFlightPlanner.hpp
//    std::vector<int> coordinates {10, 0, 6, 15, 8};
//    std::cout << littersRequired(coordinates) << std::endl;
//    std::cout << littersRequiredSimple(coordinates) << std::endl;

// TEST: deletion from BST: bstTraversals.hpp or binarySearchTree.hpp
//    Bst *tree = new Bst();
//    tree->insert(4);
//    tree->insert(6);
//    tree->insert(2);
//    tree->insert(5);
//    tree->insert(8);
//    tree->insert(3);
//    tree->insert(1);
//    std::cout << "Current root:" << tree->getRoot()->data << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    tree->setRoot(tree->remove(4));
//    std::cout << "Current root:" << tree->getRoot()->data << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    tree->setRoot(tree->remove(2));
//    std::cout << "Current root:" << tree->getRoot()->data << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    tree->setRoot(tree->remove(3));
//    std::cout << "Current root:" << tree->getRoot()->data << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
    
// TEST: BST insertion, search for key, find Min, find min in a subtree: binarySearchTree.hpp or bstTraversals.hpp
//    Bst *tree = new Bst();
//    tree->insert(4);
//    tree->insert(6);
//    tree->insert(2);
//    tree->insert(5);
//    tree->insert(8);
//    tree->insert(3);
//    tree->insert(1);
//    std::cout << tree->search(3)->data << std::endl;
//    std::cout << tree->findMin()->data << std::endl;
//    std::cout << tree->findSubtreeMin(tree->search(6))->data << std::endl;
    
// TEST: BST Traversals: bstTraversals.hpp
//    Bst *tree = new Bst();
//    tree->insert(4);
//    tree->insert(6);
//    tree->insert(2);
//    tree->insert(5);
//    tree->insert(8);
//    tree->insert(3);
//    tree->insert(1);
//    std::cout << "Pre Order Traversal:" << std::endl;
//    preOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "In Order Traversal:" << std::endl;
//    inOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "Post Order Traversal:" << std::endl;
//    postOrderTraversal(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "In Order Traversal using Stack:" << std::endl;
//    inOrderTraversalStack(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "In Order Traversal Morris:" << std::endl;
//    inOrderTraversalNoRecursion(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "Breadth First Traversal using Queue:" << std::endl;
//    breadthFirstTraversalQueue(tree->getRoot());
//    std::cout << std::endl;
//    std::cout << "Breadth First Traversal using Height:" << std::endl;
//    breadthFirstTraversalHeight(tree->getRoot());
//    std::cout << std::endl;
    
// TEST: Reverse a sentance: sentecReverse.hpp
//    std::string array = "practice reverse words";
//    char arr[22];
//    std::strcpy(arr, array.c_str());
//    
//    reverseWords(arr, 23);
//    for(int i=0; i<23; ++i){
//        std::cout << arr[i];
//    }
//    std::cout << std::endl;

// TEST: split string
//    std::string str("Split me by spaces");
//    std::string buf;
//    std::stringstream ss(str);
//    
//    std::vector<std::string> tokens;
//    while(ss >> buf)
//        tokens.push_back(buf);
//    
//    for (std::vector<std::string>::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
//        std::cout << *i << std::endl;
    
// TEST: Binomial coefficients calculation: binomialCoefficient.hpp
//    std::cout << bimonialCoefficient(5,4) << std::endl;
    
// TEST: Stack using Queue: stackFromQueue.hpp
//    {
//        using namespace stackFromQueue;
//        Stack *stack = new Stack();
//        
//        stack->push(1);
//        stack->push(2);
//        stack->push(3);
//        
//        std::cout << stack->pop() << std::endl;
//        std::cout << stack->pop() << std::endl;
//        std::cout << stack->pop() << std::endl;
//    }
    
// TEST: Queue using stack: QueueFromStack.hpp
//    Queue *q = new Queue();
//    q->enqueue2(1);
//    q->enqueue2(3);
//    q->enqueue2(5);
//    q->enqueue2(9);
//    std::cout << q->dequeue2() << std::endl;
//    std::cout << q->dequeue2() << std::endl;
//    q->enqueue2(15);
//    std::cout << q->dequeue2() << std::endl;
//    std::cout << q->dequeue2() << std::endl;
    
// TEST: stack using class: QueueFromStack.hpp
//    Stack *stack = new Stack();
//    stack->push(3);
//    stack->push(5);
//    stack->push(6);
//    
//    std::cout << stack->pop() << std::endl;
//    std::cout << stack->pop() << std::endl;
//    
//    stack->push(9);
//    
//    std::cout << stack->pop() << std::endl;
//    std::cout << stack->pop() << std::endl;
//    
//    std::cout << stack->pop() << std::endl;
//    std::cout << stack->pop() << std::endl;
    
// TEST: stack using linked list: stackUsingLinkedList.hpp
//    stackNode *head = newNode(1);
//    push(&head, 2);
//    push(&head, 3);
//    push(&head, 4);
//    std::cout << pop(&head) << std::endl;
//    std::cout << peek(head) << std::endl;
//    std::cout << " ================== " << std::endl;

// TEST: queue using linked list: queueUsingLinkedList.hpp
//    Queue *q = createQueue();
//    enqueue(q, 2);
//    enqueue(q, 4);
//    enqueue(q, 5);
//    std::cout << dequeue(q)->data << std::endl;
//    std::cout << dequeue(q)->data << std::endl;
    return 0;
}
