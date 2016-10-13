//
//  dfs.hpp
//  graph traversals. dfs
//
//  Created by alifar on 10/5/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <adjacency_lists.hpp>
#include <map>
#include <iostream>

template <class T>
std::map<Vertex<T> *, Vertex<T> *> dfs_visit(Graph<T, Vertex> *graph, Vertex<T> * root_vertex, std::map<Vertex<T> *,Vertex<T> *> &parent){
	int root_id = root_vertex->get_id();
	LinkedList<Vertex<T> *> adj_list = graph->get_adj()[root_id];
	for(auto v: adj_list){
		if(!parent.count(v)){
			parent[v] = root_vertex;
			std::cout << v << " ";
			dfs_visit(graph, v, parent);
		}
	}
	return parent;
}

template <class T>
std::map<Vertex<T> *,Vertex<T> *> dfs(Graph<T, Vertex> *graph){
	std::map<Vertex<T> *,Vertex<T> *> parent;
	for(auto v: graph->get_vertices()){
		if(!parent.count(v)){
			std::cout << v << " ";
			parent[v] = 0;
			parent = dfs_visit(graph, v, parent);
		}
	}
	return parent;
}
