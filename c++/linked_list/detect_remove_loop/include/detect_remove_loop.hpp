//
//  detect_remove_loop.hpp
//  algorithms. Linked List.
//
//  Created by alifar on 9/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <linked_list.hpp>

/*
 Given a list with a loop:
  5->4->3->6->1->9
        |________|
 Write a function to detect and remove the loop.
*/

template <class T>
void remove_loop(LinkedList<T> *head, LinkedList<T> *detection_node){
	LinkedList<T> *after_detection = detection_node->next();
	LinkedList<T> *node_in_loop = head->next();
	while(after_detection != detection_node){
		if(after_detection->next() == head){
			after_detection->set_next(nullptr);
			return;
		}
		node_in_loop = node_in_loop->next();
		after_detection = after_detection->next();
	}

	LinkedList<T> *tmp_head = head;
	while(tmp_head->next() != node_in_loop->next()){
		tmp_head = tmp_head->next();
		node_in_loop = node_in_loop->next();
	}
	node_in_loop->set_next(nullptr);
}

template <class T>
void detect_and_remove_loop(LinkedList<T> &list){
	if(!list.top()){
		return;
	}
	LinkedList<T> *fast_step = list.top();
	LinkedList<T> *slow_step = list.top();
	while(fast_step && slow_step && fast_step->next()){
		slow_step = slow_step->next();
		fast_step = fast_step->next()->next();
		if(slow_step == fast_step){
			remove_loop(list.top(), slow_step);
		}
	}
}

template <class T>
bool detect_loop(LinkedList<T> & list){
	if(!list.top()){
		return false;
	}
	LinkedList<T> *fast_step = list.top();
	LinkedList<T> *slow_step = list.top();
	while(fast_step && slow_step && fast_step->next()){
		slow_step = slow_step->next();
		fast_step = fast_step->next()->next();
		if(slow_step == fast_step){
			return true;
		}
	}
	return false;
}
