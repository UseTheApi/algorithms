//
//  detect_remove_loop.hpp
//  algorithms
//
//  Created by alifar on 9/4/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <linked_list.hpp>

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


