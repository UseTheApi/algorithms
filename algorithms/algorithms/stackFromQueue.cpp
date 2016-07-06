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
    
    Qnode::Qnode(int new_data){
        data = new_data;
        next = 0;
    }
    
    Qnode::Qnode(){
        data = 0;
        next = 0;
    }

    Queue::Queue(){
        front = 0;
        rear = 0;
    }

    void Queue::enqueue(int new_data) {
        Qnode *node = new Qnode(new_data);
        if(rear == 0){
            front = rear = node;
        } else{
            rear->next = node;
            rear = node;
        }
    }

    int Queue::dequeue(){
        if(front == 0){
            return 0;
        }
        Qnode *tmp = front;
        front = tmp->next;
        if(front == 0){
            rear = 0;
        }
        int popped = tmp->data;
        delete tmp;
        return popped;
    }

    Stack::Stack(){
        queue1 = new Queue();
        queue2 = new Queue();
    }

    void Stack::push(int new_data) {
        std::cout << "pushing" << std::endl;
        queue2->enqueue(new_data);
        while(queue1->rear != 0){
            queue2->enqueue(queue1->dequeue());
        }
        Queue *tmp = queue2;
        queue2 = queue1;
        queue1 = tmp;
    }

    int Stack::pop(){
        if(queue1->rear == 0){
            return 0;
        }
        return queue1->dequeue();
    }
}
