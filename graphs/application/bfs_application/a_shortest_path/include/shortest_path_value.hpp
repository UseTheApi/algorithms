//
//  a_shortest_path.hpp
//  graph traversals. bfs application
//
//  Created by alifar on 10/14/16.
//  Copyright © 2016 alifar. All rights reserved.
//

/*
 Consider an undirected graph consisting of n nodes where each node is labeled from 1 to n
 and the edge between any two nodes is always of length 6. 
 We define node S to be the starting position for a BFS.

 Given q queries in the form of a graph and some starting node S, perform each query by
 calculating the shortest distance from starting noe s to all the other nodes in the graph.
 If node is unreachable from S then it's distance is -1.

 Solution:
 	The idea is to BFS through graph and collect level structure of the graph.
 	Thus collecting all shortest paths from root to each vertex
*/

#include <algorithm>

template <class T>
std::map<VertexBfs<T> *, int> bfs_level(Graph<T, VertexBfs> *graph, int root_id){
	VertexBfs<T> *root = graph->get_vertex_by_id(root_id);
	std::map<VertexBfs<T> *, int> level = {{root, 0}};
	if(!root){
		return level;
	}
	int i = 1;
	std::vector<int> frontier = {root_id};
	std::vector<int> next;
	while(!frontier.empty()){
		for(auto it: frontier){
			LinkedList<VertexBfs<T> *> adj_list = graph->get_adj()[it];
			for(auto v: adj_list){
				if(!level.count(v)){
					level[v] = i;
					next.push_back(v->get_id());
				}
			}
		}
		frontier = next;
		next.clear();
		++i;
	}
	return level;
}

template <class T>
void PrintPaths(Graph<T, VertexBfs> *graph, int id){
	std::map<VertexBfs<T> *, int> level_res = bfs_level(graph, id);
	std::vector<VertexBfs<T> *> vertices = graph->get_vertices();
	for(auto it: level_res){
		std::cout << it.first << " " << it.second << std::endl;
	}
	std::cout << std::endl;
	for(auto it: level_res){
		if(std::find(vertices.begin(), vertices.end(), it.first) == vertices.end()){
			std::cout << -1 << " ";
		} else if(it.second == 0){
			vertices.erase(vertices.begin()+it.first->get_id());
			continue;
		} else{
			vertices.erase(vertices.begin()+it.first->get_id());
			std::cout << it.second*6 << " ";
		}
		// std::cout << it.first << " " << it.second << std::endl;
	}
	for(auto it: vertices){
		std::cout << -1 << " ";
	}
	std::cout << std::endl;
}
