//
//  stackUsingLinkedList.hpp
//  algorithms
//
//  Created by alifar on 6/24/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#ifndef stackUsingLinkedList_hpp
#define stackUsingLinkedList_hpp

#include <stdio.h>


struct stackNode {
    int data;
    stackNode *next;
};
stackNode *newNode(int data);
void push(stackNode **node, int data);
int pop(stackNode **head);
int isEmpty(stackNode *head);
int peek(stackNode *head);



#endif /* stackUsingLinkedList_hpp */
