//
//  stackFromQueue.cpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "stackFromQueue.hpp"
#include <iostream>

/* Implementation of a Stack using Queue
   Stack is operting with two Queues
   in this case implementation represents making push operation costly */

namespace stackFromQueue{
    
    Qnode::Qnode(int data){
        this->data = data;
        this->next = 0;
    }
    
    Qnode::Qnode(){
        this->data = 0;
        this->next = 0;
    }

    Queue::Queue(){
        this->front = 0;
        this->rear = 0;
    }

    void Queue::enqueue(int data) {
        Qnode *node = new Qnode(data);
        if(this->rear == 0){
            this->front = this->rear = node;
        } else{
            this->rear->next = node;
            this->rear = node;
        }
    }

    int Queue::dequeue(){
        if(this->front == 0){
            return 0;
        }
        Qnode *tmp = this->front;
        this->front = tmp->next;
        if(this->front == 0){
            this->rear = 0;
        }
        int popped = tmp->data;
        delete tmp;
        return popped;
    }

    Stack::Stack(){
        this->queue1 = new Queue();
        this->queue2 = new Queue();
    }

    void Stack::push(int data) {
        std::cout << "pushing" << std::endl;
        this->queue2->enqueue(data);
        while(this->queue1->rear != 0){
            this->queue2->enqueue(this->queue1->dequeue());
        }
        Queue *tmp = this->queue2;
        this->queue2 = this->queue1;
        this->queue1 = tmp;
    }

    int Stack::pop(){
        if(this->queue1->rear == 0){
            return 0;
        }
        return this->queue1->dequeue();
    }
}
