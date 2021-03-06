//
//  not_related_nodes.hpp
//  algorithms. BST application.
//
//  Created by alifar on 11/30/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <binary_search_tree.hpp>
#include <vector>
#include <iostream>

/*
 Given a pointer to the root of BST. Write a function that will return the max set of nodes that are not children or parents for each other.
 Solution:
    1. Calculate height of a given tree
    2. Create a function that returns vector of nodes for given level
    3. Iterate through a hight and collect all even and odd level nodes
    4. Return a vector of max size
*/

template <class T>
int height(Tnode<T> *root){
	if(!root){
		return 0;
	}
	int lheight = height(root->left);
	int rheight = height(root->right);
	if(lheight > rheight){
		return lheight+1;
	} else{
		return rheight+1;
	}
}

template <class T>
std::vector<Tnode<T> *> CollectLevelNodes(Tnode<T> *root, int level, std::vector<Tnode<T> *> &result){
	if(!root){
		return result;
	}
	if(level == 1){
		result.push_back(root);
		return result;
	} else{
		result = CollectLevelNodes(root->right, level-1, result);
		result = CollectLevelNodes(root->left, level-1, result);
	}
	return result;
}

template <class T>
std::vector<Tnode<T> *> NotRelatedNodes(Tnode<T> *root){
	int h = height(root);
	std::vector<Tnode<T> *> even_nodes;
	std::vector<Tnode<T> *> odd_nodes;
	for(int i = 1; i <= h; ++i){
		std::vector<Tnode<T> *> result;
		result = CollectLevelNodes(root, i, result);
		if(i%2 == 0){
			even_nodes.insert(even_nodes.end(), result.begin(), result.end());
		} else{
			odd_nodes.insert(odd_nodes.end(), result.begin(), result.end());
		}
	}
	if(even_nodes.size() > odd_nodes.size()){
		return even_nodes;
	} else{
		return odd_nodes;
	}
}
