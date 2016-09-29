//
//  bfs.hpp
//  graph traversals
//
//  Created by alifar on 9/29/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <adjacency_lists.hpp>
#include <map>
#include <iostream>

template <class T>
void bfs(Graph<T> *graph, int root_id){
	if(root_id >= graph->get_vertices().size()){
		return;
	}
	T root_vertex = graph->get_vertices()[root_id];
	std::cout << root_vertex << " ";
	int i = 1;
	std::map<T, int> level = {{root_vertex, 0}};
	std::vector<int> frontier = {root_id};
	std::vector<int> next;
	while(!frontier.empty()){
		for(auto it: frontier){
			LinkedList<T> adj_list = graph->get_adj()[it];
			for(auto v: adj_list){
				if(!level.count(v)){
					level[v] = i;
					std::cout << v << " ";
					next.push_back(graph->get_id(v));
				}
			}
		}
		frontier = next;
		next.clear();
		++i;
	}
	std::cout << std::endl;
}
