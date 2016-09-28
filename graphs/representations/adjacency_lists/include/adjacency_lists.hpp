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
 	Array of Adjacency List for each vertex
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
	int add_vertex(T); // returns an id of the vertex (position in vertices[])
	void add_edge(int, int); // positions (ids) of vertices
	void remove_edge(int, int);
	Linked_List<T> * neighbours(int); // adjacent vertices for a given vertex id
	void display_lists();
private:
	std::vector<T> vertices;
	std::vector<Linked_List<T>> adj;
}

template <class T>
int Graph<T>::add_vertex(T new_data){
	
}