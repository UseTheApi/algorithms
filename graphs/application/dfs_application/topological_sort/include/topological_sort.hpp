//
//  topological_sort.hpp
//  graphs. dfs application
//
//  Created by alifar on 10/18/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vertex_ec.hpp>
#include <iostream>
#include <vector>

/*
 Topological Sort.

 Topological sort task assumes that Graph is an ADG - Asyclic Directed Graph. 
 For checking it we run detect_remove_cycle.hpp

 A Topological sort of a DAG is a linear ordering of all vertices such that if Graph
  contains an edge(u, v), then u appears before v in ordering.

 Many application use directed graph to indicate precedences among events.

 An example of Topological Sort is a dressing problem (you must wear socks before shoes etc.)

 The clue is in DFS though the graph and storing finish times for vertices.
 Once Vertex is finished insert it in front of the result vector.

 This algorithms will be another variation of dfs from edge_classification
*/

template <class T>
void TopologicalSortVisit(Graph<T, VertexEc> *graph, VertexEc<T> *root_vertex, std::vector<VertexEc<T> *> &sort_result){
	/*
	 To not run similar algorithms twice this function will remove backward edges if found
	*/
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
			TopologicalSortVisit(graph, u, sort_result);
		} else{
			if(!u->finished && !u->get_types().count(root_vertex)){
				std::cout << "Cycle Edge is " << root_vertex << "-" << u << std::endl;
				std::cout << "Removing a cycle edge" << std::endl;
				graph->remove_edge(root_vertex->get_id(), u->get_id());
			}
		}
	}
	if(!root_vertex->finished){
		root_vertex->finished = 1;
		sort_result.insert(sort_result.begin(), root_vertex);
	}
}

template <class T>
std::vector<VertexEc<T> *> TopologicalSort(Graph<T, VertexEc> *graph){
	std::vector<VertexEc<T> *> result_sort;
	for(auto v: graph->get_vertices()){
		TopologicalSortVisit(graph, v, result_sort);
	}
	return result_sort;
}
