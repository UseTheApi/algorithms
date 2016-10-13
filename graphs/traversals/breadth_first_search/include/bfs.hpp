//
//  bfs.hpp
//  graph traversals. bfs
//
//  Created by alifar on 9/29/16.
//  Copyright © 2016 alifar. All rights reserved.
//
#include "vertex_bfs.hpp"
#include <map>
#include <iostream>

template <class T>
void bfs_map(Graph<T, VertexBfs> *graph, int root_id){ // explicit specialization to use VertexBfs 
	// (for simplicity, even though in this function I don't use full functionality of VertexBfs)
	VertexBfs<T> * root_vertex = graph->get_vertex_by_id(root_id);
	if(!root_vertex){
		return;
	}
	std::cout << "Starting from: " << root_vertex << " ";
	int i = 1;
	std::map<VertexBfs<T> *, int> level = {{root_vertex, 0}};
	std::vector<int> frontier = {root_id};
	std::vector<int> next;
	while(!frontier.empty()){
		for(auto it: frontier){
			LinkedList<VertexBfs<T> *> adj_list = graph->get_adj()[it];
			for(auto v: adj_list){
				if(!level.count(v)){
					level[v] = i;
					std::cout << v << " ";
					next.push_back(v->get_id());
				}
			}
		}
		frontier = next;
		next.clear();
		++i;
	}
	std::cout << std::endl;
}

// template <class T>
// void bfs_queue(Graph<T> *graph, int root_id){
	
// }
