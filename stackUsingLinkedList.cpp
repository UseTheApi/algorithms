//
//  stackUsingLinkedList.cpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "stackUsingLinkedList.hpp"
#include <iostream>

/* Implementation of a Stack using Linked List
   Node of a Stack is a node of Linked List
   push to the head of the Linked List
   pop from the head of the Linked List */

stackNode * newNode(int data){
    stackNode *node = new stackNode();
    node->data = data;
    node->next = 0;
    return node;
}

void push(stackNode **head, int data){
    stackNode *node = newNode(data);
    node->next = *head;
    *head = node;
    std::cout << "Pushed " << node->data << std::endl;
    return;
}

int isEmpty(stackNode *head){
    return !head;
}

int pop(stackNode **head){
    if(isEmpty(*head)){
        return INT32_MIN;
    }
    stackNode *temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    delete temp;
    return popped;
}

int peek(stackNode *head){
    if(isEmpty(head)){
        return INT32_MIN;
    }
    return head->data;
}
