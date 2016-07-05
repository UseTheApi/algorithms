//
//  queueUsingLinkedList.cpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "queueUsingLinkedList.hpp"
#include <iostream>

/* Implementation of a Queue using Linked List
   Queue has two pointers to a Linked List nodes: front and rear
   enqueue to the end of the Linked List
   dequeue from the head of the Linked List */

Qnode * newQNode(int data){
    Qnode * node = new Qnode();
    node->data = data;
    node->next = 0;
    return node;
}

Queue * createQueue(){
    Queue* queue = new Queue();
    queue->front = queue->rear = 0;
    return queue;
}

void enqueue(Queue *queue, int data){ // 1->2, 4 ==> 1->2->4
    Qnode *tmp = newQNode(data);
    if(queue->rear == 0){
        queue->front = queue->rear = tmp;
    }
    
    queue->rear->next = tmp;
    queue->rear = tmp;
}

Qnode * dequeue(Queue *queue){
    if(queue->front == 0){
        return 0;
    }
    Qnode *tmp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == 0){
        queue->rear = 0;
    }
    return tmp;
}
