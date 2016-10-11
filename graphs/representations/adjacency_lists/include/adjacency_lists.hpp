//
//  adjacency_lists.hpp
//  graph representations
//
//  Created by alifar on 9/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include "vertex.hpp"
#include <linked_list.hpp>
#include <vector>
#include <iostream>

/*
 Graph representations:
 	Array of Adjacency List for each vertex for unweighted (un-)directed graph
 	a -- b
 	|    |
 	c    d

 	a -> b -> c
 	b -> a -> d
 	c -> a
 	d -> b
*/

template <class T>
class Graph{
public:
	Graph(bool);
	int add_vertex(T); // returns an id of the vertex (position in vertices[])
	void add_edge(int, int); // positions (ids) of vertices
	void remove_edge(int, int);
	LinkedList<Vertex<T> *> neighbours(int); // adjacent vertices for a given vertex id
	void display_lists();
	void display_vertices();
	// int get_id(T);
	std::vector<Vertex<T> *> get_vertices();
	std::vector<LinkedList<Vertex<T> *>> get_adj();
	Vertex<T> * get_vertex_by_id(int);
private:
	std::vector<Vertex<T> *> vertices;
	std::vector<LinkedList<Vertex<T> *>> adj;
	bool directed; // true if Directed
};

template <class T>
Graph<T>::Graph(bool graph_type){
	directed = graph_type;
}

template <class T>
int Graph<T>::add_vertex(T new_data){
	Vertex<T> *new_vertex = new Vertex<T>(new_data, vertices.size());
	vertices.push_back(new_vertex);
	// int index = vertices.size()-1;
	LinkedList<Vertex<T> *> adj_list;
	adj_list.push(new_vertex);
	adj.push_back(adj_list);
	return new_vertex->get_id();
}

template <class T>
Vertex<T> * Graph<T>::get_vertex_by_id(int given_id){
	for(auto it: vertices){
		if(it->get_id() == given_id){
			return it;
		}
	}
	return 0;
}

template <class T>
void Graph<T>::add_edge(int index1, int index2){
	Vertex<T> *v1 = get_vertex_by_id(index1);
	Vertex<T> *v2 = get_vertex_by_id(index2);
	if(v1 != 0 && v2 != 0){
		adj[index1].append(v2);

		if(!directed){
			adj[index2].append(v1);
		}
	}
}

template <class T>
void Graph<T>::remove_edge(int index1, int index2){
	Vertex<T> *v1 = get_vertex_by_id(index1);
	Vertex<T> *v2 = get_vertex_by_id(index2);
	if(v1 != 0 && v2 != 0){
		adj[index1].remove(v2);

		if(!directed){
			adj[index2].remove(v1);
		}
	}
}

template <class T>
LinkedList<Vertex<T> *> Graph<T>::neighbours(int index){
	if(index >= vertices.size()){
		return 0;
	}

	LinkedList<Vertex<T>*> list = adj[index];
	list.remove_head();
	return list;

}

template <class T>
void Graph<T>::display_lists(){
	for(auto it: adj){
		it.print_list();
		std::cout << std::endl;
	}
}

template <class T>
void Graph<T>::display_vertices(){
	for(auto it: vertices){
		std::cout << it << " ";
	}
	std::cout << std::endl;
}

// template <class T>
// int Graph<T>::get_id(T vertex){
// 	int id = 0;
// 	for(auto it: vertices){
// 		if(vertex == it){
// 			return id;
// 		}
// 		++id;
// 	}
// 	return -1;
// }

template <class T>
std::vector<Vertex<T> *> Graph<T>::get_vertices(){
	return vertices;
}

template <class T>
std::vector<LinkedList<Vertex<T> *>> Graph<T>::get_adj(){
	return adj;
}
