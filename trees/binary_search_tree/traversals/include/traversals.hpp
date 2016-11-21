//
//  traversals.hpp
//  algorithms. BST traversals.
//
//  Created by alifar on 11/1/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <binary_search_tree.hpp>
#include <stack_linked_list.hpp>
#include <queue_linked_list.hpp>
#include <iostream>

template <class T>
void InOrder(Tnode<T> *root){
	if(root){
		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}
}

template <class T>
void PostOrder(Tnode<T> *root){
	if(root){
		PostOrder(root->left);
		PostOrder(root->right);
		std::cout << root->data << " ";
	}
}

template <class T>
void PreOrder(Tnode<T> *root){
	if(root){
		std::cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
 
template <class T>
void InOrderStack(Tnode<T> *root){
	Stack<Tnode<T> *> nodes;
	bool done = false;
	Tnode<T> *cur = root;
	while(!done){
		if(cur){
			nodes.Push(cur);
			cur = cur->left;
		} else{
			if(!nodes.empty()){
				cur = nodes.Top()->get_data();
				std::cout << cur << " ";
				nodes.Pop();
				cur = cur->right;
			} else{
				done = true;
			}
		}
	}
}

template <class T>
void InOrderMorris(Tnode<T> *root){
	Tnode<T> *pre = 0;
	Tnode<T> *cur = root;
	if(!root){
		return;
	}
	while(cur){
		if(!cur->left){
			std::cout << cur << " ";
			cur = cur->right;
		} else{
			pre = cur->left;
			if(pre->right && pre->right != cur){
				pre = pre->right;
			}
			if(!pre->right){
				pre->right = cur;
				cur = cur->left;
			} else{
				pre->right = 0;
				std::cout << cur << " ";
				cur = cur->right;
			}
		}
	}
}

template <class T>
void BreadthFirst(Tnode<T> *root){
	/*
	Level Order Traversal using Queue
	*/
	if(!root){
		return;
	}
	Queue<Tnode<T> *> nodes;
	nodes.Enqueue(root);
	while(!nodes.empty()){
		Tnode<T> *cur = nodes.Top()->get_data();
		std::cout << cur << " ";
		nodes.Dequeue();
		if(cur->left){
			nodes.Enqueue(cur->left);
		}
		if(cur->right){
			nodes.Enqueue(cur->right);
		}
	}
}

template <class T>
int height(Tnode <T> *root){
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
void PrintLevelNodes(Tnode <T> *root, int level){
	if(!root){
		return;
	}
	if(level == 1){
		std::cout << root << " ";
	} else{
		PrintLevelNodes(root->left, level-1);
		PrintLevelNodes(root->right, level-1);
	}
}

template <class T>
void LevelOrder(Tnode<T> *root){
	int h = height(root);
	for(int i = 1; i <= h; ++i){
		PrintLevelNodes(root, i);
	}
}
