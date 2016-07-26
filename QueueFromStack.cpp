//
//  QueueFromStack.cpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include <iostream>
#include "QueueFromStack.hpp"

/* Implementation of a Queue with Stack
   Queue is operating with two stacks
   enqueue1 and dequeue1 represent implementation by making enqueue method costly
   enqueue2 and dequeue2 represent implementation by making dequeue method costly*/

StackNode::StackNode(int new_data){
    data = new_data;
    next = 0;
}

Stack::Stack(){
    head = 0;
}

void Stack::push(int data){
    StackNode *node = new StackNode(data);
    node->next = head;
    head = node;
}

int Stack::isEmpty(){
    return !head;
}

int Stack::pop(){
    if(head == 0){
        return 0;
    }
    StackNode *tmp = head;
    head = tmp->next;
    int popped = tmp->data;
    delete tmp;
    return popped;
}

Queue::Queue(){
    stack1 = new Stack();
    stack2 = new Stack();
}

void Queue::enqueue1(int data){
    //this implementation uses the second stack to remain
    //the last item on the top to easy pop it from a queue
    while(!stack1->isEmpty()){
        stack2->push(stack1->pop());
    }
    stack1->push(data);
    while(!stack2->isEmpty()){
        stack1->push(stack2->pop());
    }
}

int Queue::dequeue1(){
    if(stack1->isEmpty()){
        return INT32_MIN;
    }
    return stack1->pop();
}

void Queue::enqueue2(int data){
    stack1->push(data);
}

int Queue::dequeue2(){
    if(stack1->isEmpty() && stack2->isEmpty()) return 0;
    else if(stack2->isEmpty()){
        while(!stack1->isEmpty()){
            stack2->push(stack1->pop());
        }
    }
    return stack2->pop();
}
