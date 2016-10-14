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
 Edge Classification.

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
void dfs_visit(Graph<T,VertexEc> *graph, VertexEc<T> *root_vertex){
	LinkedList<VertexEc<T> *> adj_list = graph->get_adj()[root_vertex->get_id()];
	for(auto u: adj_list){
		if(!u->visited){
			u->visited = true;
			// overkill in this case, cause we store edge types foe each vertex
			u->set_parent(root_vertex); // tree edge type represents parent pointer as well
			u->add_type(root_vertex, EdgeType::kTree);
			std::cout << u << " ";
			dfs_visit(graph, u);
		}
	}
}

template <class T>
void Dfs(Graph<T, VertexEc> *graph){
	for(auto v: graph->get_vertices()){
		if(!v->visited){
			v->set_parent(0);
			v->visited = true;
			std::cout << v << " ";
			dfs_visit(graph, v);
		}
	}
}

template <class T>
void TreeEdges(Graph<T, VertexEc> *graph){
	std::vector<VertexEc<T> *> vertices = graph->get_vertices();
	for(auto vertex: vertices){
		std::map<VertexEc<T> *, EdgeType> edge_types = vertex->get_types();
		for(auto it: edge_types){
			if(it.second == EdgeType::kTree){
				std::cout << it.first << " " << vertex << ": tree edge" << std::endl;
			}
		}
	}
}

template <class T>
void dfs_ec_visit(Graph<T, VertexEc> *graph, VertexEc<T> *root_vertex){
	root_vertex->set_parent(0);
	root_vertex->visited = true;
	root_vertex.discovered = ++time;
	LinkedList<VertexEc<T> *> adj_list = graph->get_adj()[root_vertex->get_id()];
	for(auto u: adj_list){
		if(!u->visited){
			u->visited = true;
			u->set_parent(root_vertex);
			u->add_type(root_vertex, EdgeType::kTree);
			u->discovered = ++time;
			dfs_visit(graph, u);
		} else{
			
		}
	}
}

template <class T>
void dfs(Graph<T, VertexEc> *graph){
	int step = 0;
	for(auto v: graph->get_vertices()){
		if(!v.visited){
			dfs_visit(graph, v, time);
		}
	}
}
