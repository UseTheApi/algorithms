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
	void display_vertices();
	void display_matrix();
private:
	std::vector< std::vector<int> > adj_matrix_;
	std::vector<T> vertices_; // {5, 6, 3, 1}
};

/*
	Adj Matrix ex:
	1 1 0 0 
	0 1 0 0
	0 0 1 0
	0 0 1 1
*/

template <class T>
int Graph<T>::add_vertex(T new_data){
	vertices_.push_back(new_data);
	int size = vertices_.size();
	adj_matrix_.resize(size);
	for(int i = 0; i < size; ++i){
		adj_matrix_[i].resize(size);
		for(int j = 0; j < size; ++j){
			adj_matrix_[i][j] = 0;
		}
	}
	return size-1;
}

template <class T>
void Graph<T>::add_edge(int v_index1, int v_index2){
	if(v_index1 >= 0 && v_index2 < vertices_.size() && v_index2 >= 0 && v_index2 < vertices_.size()){
		adj_matrix_[v_index1][v_index2] = 1;
		adj_matrix_[v_index2][v_index1] = 1;
	}
}

template <class T>
void Graph<T>::remove_edge(int v_index1, int v_index2){
	if(v_index1 >= 0 && v_index2 < vertices_.size() && v_index2 > 0 && v_index2 < vertices_.size()){
		adj_matrix_[v_index1][v_index2] = 0;
		adj_matrix_[v_index2][v_index1] = 0;
	}
}

template <class T>
bool Graph<T>::adjacent(int v_index1, int v_index2){
	if(v_index1 < vertices_.size() && v_index2 < vertices_.size()){
		return adj_matrix_[v_index1][v_index2];
	}
	return false;
}

template <class T>
void Graph<T>::display_vertices(){
	for(auto it: vertices_){
		std::cout << it << " ";
	}
	std::cout << std::endl;
}

template <class T>
void Graph<T>::display_matrix(){
	int size = adj_matrix_.size();
	for(auto it = adj_matrix_.begin(); it != adj_matrix_.end(); ++it){
		for(auto ti = it->begin(); ti != it->end(); ++ti){
			std::cout << *ti << " ";
		}
		std::cout << std::endl;
	}
}
