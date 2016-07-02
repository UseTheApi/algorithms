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
    
// TEST: Knapsack 1-0 problem: knapsackProblem.hpp
//    int n_items = 5;
//    int capacity = 11;
//    int *values = new int[n_items];
//    int *weights = new int[n_items];
//    values[0] = 1; weights[0] = 1;
//    values[1] = 6; weights[1] = 2;
//    values[2] = 18; weights[2] = 5;
//    values[3] = 22; weights[3] = 6;
//    values[4] = 28; weights[4] = 7;
//    maxValueforKnapsack(capacity, n_items, values, weights);
    
// TEST: ways to calculate amount with give list of debominations: amountWithCoins.hpp
//    int *denominations = new int[3];
//    denominations[0] = 1;
//    denominations[1] = 2;
//    denominations[2] = 3;
//    std::cout << waysToGetAmount(6, denominations) << std::endl;
    
// TEST: Jump Stairs tasks DP: hopSomeStairs.hpp
//    std::cout << walkThoughStairs(10) << std::endl;
    
// TEST: Fibonacci and Factorial DP: factorial_fibonacci.hpp
//    std::cout << fibonacci(45) << std::endl;
//    std::cout << factorial(15) << std::endl;
    
// TEST: Binomial coefficients calculation: binomialCoefficient.hpp
//    std::cout << bimonialCoefficient(5,4) << std::endl;
    
//    BinaryTree *tree = new BinaryTree(4);
//    tree->root->left = new Tnode(3);
//    tree->root->right = new Tnode(5);
//    tree->inOrderTraversal();
    
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
