//
//  stackFromQueue.hpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef stackFromQueue_hpp
#define stackFromQueue_hpp

#include <stdio.h>
namespace stackFromQueue{
    struct Qnode{
        int data;
        Qnode* next = 0;
        Qnode(int);
        Qnode();
    };

    struct Queue{
        Qnode *front, *rear;
        void enqueue(int);
        int dequeue();
        Queue();
    };

    class Stack{
    public:
        void push(int);
        int pop();
        Stack();
    private:
        Queue *queue1, *queue2;
    };
}

#endif /* stackFromQueue_hpp */
