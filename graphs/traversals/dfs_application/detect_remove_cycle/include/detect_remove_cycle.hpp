//
//  detect_remove_cycle.hpp
//  graphs. dfs application
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "vertex_ec.hpp"
#include <iostream>

/*
 Detecting and Removing a cycle from the Graph

 The lemma is that if Graph has a Backward edge it has a cycle 
 (as well as if there is a cycle in the graph, there is a Backward edge)

 The solution is to modify edge_classification DFS to detect a backward edge and remove it.
 
 Basically, the algorithm has to track nodes in current recursion stack and detect a backward edge
*/

template <class T>
void RemoveACycle(Graph<T, VertexEc> *graph, VertexEc<T> *root_vertex){
	root_vertex->visited = true;
	LinkedList<VertexEc<T> *> adj_list = graph->get_adj()[root_vertex->get_id()];
	for(auto u: adj_list){
		if(root_vertex == u){
				continue;
		}
		if(!graph->directed){
			root_vertex->add_type(u, EdgeType::kNone);
		}
		if(!u->visited){
			u->visited = true;
			u->add_type(root_vertex, EdgeType::kTree);
			std::cout << "Tree Edge: " << root_vertex << "-" << u << std::endl;
			RemoveACycle(graph, u);
		} else{
			if(!u->finished && !u->get_types().count(root_vertex)){
				std::cout << "Cycle Edge is " << root_vertex << "-" << u << std::endl;
				std::cout << "Removing a cycle edge" << std::endl;
				graph->remove_edge(root_vertex->get_id(), u->get_id());
			}
		}
	}
	root_vertex->finished = 1;
}

template <class T>
void DetectRemoveCycles(Graph<T, VertexEc> *graph){
	for(auto v: graph->get_vertices()){
		RemoveACycle(graph, v);
	}
}
