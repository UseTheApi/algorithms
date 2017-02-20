//
//  max_path_wbst.hpp
//  algorithms. weighted BST application.
//
//  Created by alifar on 02/20/17.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <weighted_binary_tree.hpp>
#include <queue_linked_list.hpp>
#include <algorithm>
#include <iostream>

template <class T>
int MaxPathWbst(TWnode<T> *node){
	if(!node){
		return 0;
	}
	Queue<TWnode<T> *> nodes;
	nodes.Enqueue(node);
	TWnode<T> *cur;
	int max_weight = 0;
	while(!nodes.empty()){
		cur = nodes.Top()->get_data();
		if(cur->parent){
			cur->weight += cur->parent->weight;
		}
		nodes.Dequeue();
		if(cur->left){
			nodes.Enqueue(cur->left);
		}
		if(cur->right){
			nodes.Enqueue(cur->right);
		}
		if(!cur->left && !cur->right){
			max_weight = std::max(cur->weight, max_weight);
		}
	}
	return max_weight;
}
