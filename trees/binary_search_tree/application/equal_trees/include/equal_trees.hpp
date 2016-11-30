//
//  equal_trees.cpp
//  algorithms. BST application.
//
//  Created by alifar on 11/30/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <binary_search_tree.hpp>
#include <queue_linked_list.hpp>

template <class T>
bool Equal(Tnode<T> *root1, Tnode<T> *root2){
	if(!root1 && !root2){
		return true;
	}
	if(!root1 || !root2){
		return false;
	}
	Queue<Tnode<T> *> q1;
	Queue<Tnode<T> *> q2;
	q1.Enqueue(root1);
	q2.Enqueue(root2);
	while(!q1.empty() && !q2.empty()){
		Tnode<T> *cur1 = q1.Top()->get_data();
		Tnode<T> *cur2 = q2.Top()->get_data();
		if(cur1->data != cur2->data){
			return false;
		}
		q1.Dequeue();
		q2.Dequeue();
		if(cur1->left && cur2->left){
			q1.Enqueue(cur1->left);
			q2.Enqueue(cur2->left);
		} else if(cur1->left || cur2->left){
			return false;
		}
		if(cur1->right && cur2->right){
			q1.Enqueue(cur1->right);
			q2.Enqueue(cur2->right);
		} else if(cur1->right || cur2->right){
			return false;
		}
	}
	return true;
}
