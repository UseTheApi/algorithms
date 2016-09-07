//
//  adjacency_matrix.hpp
//  algorithms
//
//  Created by alifar on 8/30/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vector>
#include <iostream>

/*
 Graph representations:
 	Adjacency Matrix is nxn matrix containing all vertices. 
 	Values are 1 if edge from i to j exists and 0 otherwise.
*/

template <class T>
class Graph{
public:
	int add_vertex(T); // returns an id of the vertex (position in vertices[])
	void add_edge(int, int); // positions of vertices
	void remove_edge(int, int);
	bool adjacent(int, int);
private:
	vector< vector<int> > adj_matrix;
	vector<T> vertices; // {5, 6, 3, 1}
}

/*
	Adj Matrix ex:
	1 1 0 0 
	0 1 0 0
	0 0 1 0
	0 0 1 1
*/

template <class T>
int Graph<T>::add_vertex(T new_data){
	vertices.push_back(new_data);
	int size = vertices.size();
	adj_matrix.resize(size);
	for(int i = 0; i < size; ++i){
		adj_matrix[i].resize(size);
		for(int j = 0; j < size; ++j){
			adj_matrix[i][j] = 0;
		}
	}
	return size-1;
}

template <class T>
void add_edge(int v_index1, int v_index2){
	if(v_index1 >= 0 && v_index2 < vertices.size() && v_index2 >= 0 && v_index2 < vertices.size()){
		adj_matrix[v_index1][v_index2] = 1;
		adj_matrix[v_index2][v_index1] = 1;
	}
}

template <class T>
void remove_edge(int v_index1, int v_index2){
	if(v_index1 >= 0 && v_index2 < vertices.size() && v_index2 >= 0 && v_index2 < vertices.size()){
		adj_matrix[v_index1][v_index2] = 0;
		adj_matrix[v_index2][v_index1] = 0;
	}
}

bool adjacent(int v_index1, int v_index2){
	if(v_index1 < vertices.size() && v_index2 < vertices.size()){
		return adj_matrix[v_index1][v_index2];
	}
}
