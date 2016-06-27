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

StackNode::StackNode(int data){
    this->data = data;
    this->next = 0;
}

Stack::Stack(){
    this->head = 0;
}

void Stack::push(int data){
    StackNode *node = new StackNode(data);
    node->next = this->head;
    this->head = node;
}

int Stack::isEmpty(){
    return !this->head;
}

int Stack::pop(){
    if(this->head == 0){
        return 0;
    }
    StackNode *tmp = this->head;
    this->head = tmp->next;
    int popped = tmp->data;
    delete tmp;
    return popped;
}

Queue::Queue(){
    this->stack1 = new Stack();
    this->stack2 = new Stack();
}

void Queue::enqueue1(int data){
    //this implementation uses the second stack to remain
    //the last item on the top to easy pop it from a queue
    while(!this->stack1->isEmpty()){
        this->stack2->push(this->stack1->pop());
    }
    this->stack1->push(data);
    while(!this->stack2->isEmpty()){
        this->stack1->push(this->stack2->pop());
    }
}

int Queue::dequeue1(){
    if(this->stack1->isEmpty()){
        return INT32_MIN;
    }
    return this->stack1->pop();
}

void Queue::enqueue2(int data){
    this->stack1->push(data);
}

int Queue::dequeue2(){
    if(this->stack1->isEmpty() && this->stack2->isEmpty()) return 0;
    else if(this->stack2->isEmpty()){
        while(!stack1->isEmpty()){
            this->stack2->push(this->stack1->pop());
        }
    }
    return this->stack2->pop();
}








