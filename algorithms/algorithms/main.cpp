//
//  main.cpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <iostream>
#include "stackUsingLinkedList.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //std::cout << bimonialCoefficient(8,4) << std::endl;
    
//    BinaryTree *tree = new BinaryTree(4);
//    tree->root->left = new Tnode(3);
//    tree->root->right = new Tnode(5);
//    tree->inOrderTraversal();
    
// TEST: Stack using Queue
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
// TEST: Queue using stack
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
    
// TEST: stack using class
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
    
// TEST: stack using linked list
    stackNode *head = newNode(1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    std::cout << pop(&head) << std::endl;
    std::cout << peek(head) << std::endl;
    std::cout << " ================== " << std::endl;
//
// TEST: queue using linked list
//    Queue *q = createQueue();
//    enqueue(q, 2);
//    enqueue(q, 4);
//    enqueue(q, 5);
//    std::cout << dequeue(q)->data << std::endl;
//    std::cout << dequeue(q)->data << std::endl;
    return 0;
}
