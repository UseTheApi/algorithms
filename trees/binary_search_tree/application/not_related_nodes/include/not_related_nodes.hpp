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
		if(i%2 == 0){
			std::vector<Tnode<T> *> result;
			result = CollectLevelNodes(root, i, result);
			even_nodes.insert(even_nodes.end(), result.begin(), result.end());
		} else{
			std::vector<Tnode<T> *> result;
			result = CollectLevelNodes(root, i, result);
			odd_nodes.insert(odd_nodes.end(), result.begin(), result.end());
		}
	}
	if(even_nodes.size() > odd_nodes.size()){
		return even_nodes;
	} else{
		return odd_nodes;
	}
}
