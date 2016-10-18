//
//  edge_classification.hpp
//  graphs. dfs application
//
//  Created by alifar on 10/11/16.
//  Copyright © 2016 alifar. All rights reserved.
//

#include <vertex_bfs.hpp>
#include <map>
#include <iostream>

enum EdgeType { kTree, kForward, kBackward, kCross, kNone };

template <class T>
class VertexEc: public VertexBfs<T>{
public:
	int discovered; // fixes time counter when vertex was discovered
	int finished; // fixes time counter when vertex left recursion stack of DFS
	VertexEc(T init_data, int init_id): VertexBfs<T>(init_data, init_id){
		discovered = 0;
		finished = 0;
	}
	void add_type(VertexEc<T> *, EdgeType);
	std::map<VertexEc<T> *, EdgeType> get_types();
private:
	std::map<VertexEc<T> *, EdgeType> edge_types_;
};

template <class T>
void VertexEc<T>::add_type(VertexEc<T> *vertex, EdgeType ktype){
	// std::cout << "VERTEX: " << this << " adding: " <<  edge_types_.count(vertex) << std::endl;
	if(!edge_types_.count(vertex)){
		// std::cout << "ADDING" << std::endl;
		if(ktype == EdgeType::kNone){
			// std::cout << "Setting edge " << vertex << "-" << this << " to None type" << std::endl;
		}
		edge_types_[vertex] = ktype;
	}
}

template <class T>
std::map<VertexEc<T> *, EdgeType> VertexEc<T>::get_types(){
	return edge_types_;
}
