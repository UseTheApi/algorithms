//
//  QueueFromStack.hpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef QueueFromStack_hpp
#define QueueFromStack_hpp

#include <stdio.h>

struct StackNode{
    int data;
    StackNode* next;
    StackNode(int);
private:
    StackNode();
};

class Stack{
public:
    void push(int);
    int pop();
    Stack();
    int isEmpty();
private:
    StackNode *head;
};

class Queue {
public:
    void enqueue1(int);
    int dequeue1();
    void enqueue2(int);
    int dequeue2();
    Queue();
private:
    Stack *stack1;
    Stack *stack2;
};


#endif /* QueueFromStack_hpp */
