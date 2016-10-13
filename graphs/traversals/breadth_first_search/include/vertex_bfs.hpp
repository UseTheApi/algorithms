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
		parent_ = 0;
		distance_ = 0;
		visited = false;
	};
	VertexBfs<T> * get_parent();
	int get_distance();
	void set_parent(VertexBfs<T> *);
	void set_distance(int);
	bool visited;
private:
	VertexBfs<T> *parent_;
	int distance_;
};

template <class T>
VertexBfs<T> * VertexBfs<T>::get_parent(){
	return parent_;
}

template <class T>
int VertexBfs<T>::get_distance(){
	return distance_;
}

template <class T>
void VertexBfs<T>::set_parent(VertexBfs<T> *new_parent){
	parent_ = new_parent;
}

template <class T>
void VertexBfs<T>::set_distance(int new_distance){
	distance_ = new_distance;
}
