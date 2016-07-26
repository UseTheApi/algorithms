//
//  queueUsingLinkedList.hpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef queueUsingLinkedList_hpp
#define queueUsingLinkedList_hpp

#include <stdio.h>

struct Qnode{
    int data;
    Qnode *next;
};
struct Queue{
    Qnode *front, *rear;
};
Qnode * newQNode(int data);
Queue * createQueue();
void enqueue(Queue* queue, int data);
Qnode * dequeue(Queue* queue);

#endif /* queueUsingLinkedList_hpp */
