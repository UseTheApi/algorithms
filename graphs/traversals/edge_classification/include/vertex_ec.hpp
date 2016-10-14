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

enum EdgeType { kTree, kForward, kBackward, kCross };

template <class T>
class VertexEc: public VertexBfs<T>{
public:
	void add_type(VertexEc<T> *, EdgeType);
	std::map<VertexEc<T> *, EdgeType> get_types();
private:
	std::map<VertexEc<T> *, EdgeType> edge_types_;
};

template <class T>
void VertexEc<T>::add_type(VertexEc<T> *vertex, EdgeType ktype){
	edge_types_[vertex] = ktype;
}

template <class T>
std::map<VertexEc<T> *, EdgeType> get_types(){
	return edge_types_;
}
