//
//  max_weighted_path.hpp
//  algorithms. weighted k-ary tree application.
//
//  Created by alifar on 02/25/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <weighted_k_tree.hpp>
#include <algorithm>

template <class T>
int MaxWeightKTree(KWNode<T> *root){
	if(!root){
		return 0;
	}
	KWNode<T> *cur = root;
	std::set<KWNode<T> *> visited;
	int max_weight = 0;
	while(cur){
		if(visited.find(cur) != visited.end()){
			cur = cur->sibling ? cur->sibling : cur->parent;
		} else{
			visited.insert(cur);
			if(cur->f_child){
				cur = cur->f_child;
				cur->weight += cur->parent->weight;
			} else{
				max_weight = std::max(max_weight, cur->weight);
				cur = cur->sibling ? cur->sibling : cur->parent;
			}
		}
	}
	return max_weight;
}
