//
//  adjacency_lists.hpp
//  graph representations
//
//  Created by alifar on 9/28/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <linked_list.hpp>
#include <vector>
#include <iostream>

/*
 Graph representations:
 	Array of Adjacency List for each vertex for unweighted undirected graph
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
	LinkedList<T> neighbours(int); // adjacent vertices for a given vertex id
	void display_lists();
	void display_vertices();
	int get_id(T);
	std::vector<T> get_vertices();
	std::vector<LinkedList<T>> get_adj();
private:
	std::vector<T> vertices;
	std::vector<LinkedList<T>> adj;
	bool directed; // true if Directed
};

template <class T>
Graph<T>::Graph(bool graph_type){
	directed = graph_type;
}

template <class T>
int Graph<T>::add_vertex(T new_data){
	vertices.push_back(new_data);
	int index = vertices.size()-1;
	LinkedList<T> adj_list;
	adj_list.push(new_data);
	adj.push_back(adj_list);
	return index;
}

template <class T>
void Graph<T>::add_edge(int index1, int index2){
	if(index1 >= vertices.size() || index2 >= vertices.size()){
		return;
	}

	T v1 = vertices[index1];
	T v2 = vertices[index2];
	adj[index1].append(v2);

	if(!directed){
		adj[index2].append(v1);
	}
}

template <class T>
void Graph<T>::remove_edge(int index1, int index2){
	if(index1 >= vertices.size() || index2 >= vertices.size()){
		return;
	}

	T v1 = vertices[index1];
	T v2 = vertices[index2];
	adj[index1].remove(v2);

	if(!directed){
		adj[index2].remove(v1);
	}
}

template <class T>
LinkedList<T> Graph<T>::neighbours(int index){
	if(index >= vertices.size()){
		return 0;
	}

	LinkedList<T> list = adj[index];
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

template <class T>
int Graph<T>::get_id(T vertex){
	int id = 0;
	for(auto it: vertices){
		if(vertex == it){
			return id;
		}
		++id;
	}
	return -1;
}

template <class T>
std::vector<T> Graph<T>::get_vertices(){
	return vertices;
}

template <class T>
std::vector<LinkedList<T>> Graph<T>::get_adj(){
	return adj;
}
