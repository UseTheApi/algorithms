//
//  edge_classification.hpp
//  graphs. dfs application
//
//  Created by alifar on 10/11/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "vertex_ec.hpp"
#include <iostream>

/*
 Edge Classification. <- EC

 Approaches:
 	1. Tree edges returns DFS itself within Parent structure
 	2. Backward edges: mark which vertices we are currently exploring in DFS. 
 	   If the edges that currently being explored leads to a vertex that has been makred as 'started', 
 	   then it's a backward edge
 	3. Forward edges: count steps of DFS algorithms and store them in a vertex structure. 
 	   This would tell us time we explored every node and can help to recognize forward edges from cross edges

 Remark: I had to rewrite depth_first_search that was implemented earlier in this project using vertices attributes.
  It makes it easier to implement edge classification and other tasks. 
  The easiest implementation of DFS you can find in depth_first_search/ folder.
*/

template <class T>
int dfs_ec_visit(Graph<T, VertexEc> *graph, VertexEc<T> *root_vertex, int &time){ // O(V+E)
	// parent pointer represents tree edge type  
	// root_vertex->set_parent(0); we store edge types for each vertex
	root_vertex->visited = true;
	root_vertex->discovered = ++time;
	LinkedList<VertexEc<T> *> adj_list = graph->get_adj()[root_vertex->get_id()];
	for(auto u: adj_list){
		if(!u->visited){
			u->visited = true;
			// u->set_parent(root_vertex);
			u->add_type(root_vertex, EdgeType::kTree);
			u->discovered = ++time;
			if(!graph->directed){
				root_vertex->add_type(u, EdgeType::kNone);
			}
			dfs_ec_visit(graph, u, time);
		} else{
			if(root_vertex == u){ // excluding visited root_vertex
				continue;
			}
			// (root_vertex is unfinished because we're iterating through its adj_list)
			if(!u->finished){ // u is unfinished and we're in root_vertex's recursion stack
				u->add_type(root_vertex, EdgeType::kBackward);
			} else{ // either cross or forward. calculating based on times of discover
				if(u->discovered < root_vertex->discovered){
					u->add_type(root_vertex, EdgeType::kCross);
				} else{
					u->add_type(root_vertex, EdgeType::kForward);
				}
			}
			if(!graph->directed){
				root_vertex->add_type(u, EdgeType::kNone);
			}
		}
	}
	root_vertex->finished = ++time;
	return time;
}

template <class T>
void dfs_ec(Graph<T, VertexEc> *graph){
	int time = 0;
	for(auto v: graph->get_vertices()){
		if(!v->visited){
			time = dfs_ec_visit(graph, v, time);
		}
	}
}

template <class T>
void EdgeClassification(Graph<T, VertexEc> *graph){ // O(V+E)
	std::vector<VertexEc<T> *> vertices = graph->get_vertices();
	for(auto vertex: vertices){
		// std::cout << "Vertex: " << vertex << std::endl;
		for(auto edge: vertex->get_types()){
			switch(edge.second){
				case EdgeType::kTree:
					std::cout << edge.first << " " << vertex << ": tree edge" << std::endl;
					break;
				case EdgeType::kForward:
					std::cout << edge.first << " " << vertex << ": forward edge" << std::endl;
					break;
				case EdgeType::kBackward:
					std::cout << edge.first << " " << vertex << ": backward edge" << std::endl;
					break;
				case EdgeType::kCross:
					std::cout << edge.first << " " << vertex << ": cross edge" << std::endl;
					break;
			}
		}
	}
}
