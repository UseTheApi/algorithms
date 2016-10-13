//
//  vertex_bfs.hpp
//  graph traversals. bfs
//
//  Created by alifar on 9/29/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <adjacency_lists.hpp>

template <class T>
class VertexBfs: public Vertex<T>{
public:
	VertexBfs(T init_data, int init_id): Vertex<T>(init_data, init_id){
		parent = 0;
		distance = 0;
	};
	VertexBfs<T> * get_parent();
	int get_distance();
	void set_parent(VertexBfs<T> *);
	void set_distance(int);
private:
	VertexBfs<T> *parent;
	int distance;
};

template <class T>
VertexBfs<T> * VertexBfs<T>::get_parent(){
	return parent;
}

template <class T>
int VertexBfs<T>::get_distance(){
	return distance;
}

template <class T>
void VertexBfs<T>::set_parent(VertexBfs<T> *new_parent){
	parent = new_parent;
}

template <class T>
void VertexBfs<T>::set_distance(int new_distance){
	distance = new_distance;
}